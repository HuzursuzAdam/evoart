#!/usr/bin/env python3
import serial
import time
import keyboard  # Klavye dinleme kütüphanesi

# Seri port ayarları
PORT = '/dev/ttyUSB0'
BAUD = 115200

def main():
    try:
        ser = serial.Serial(PORT, BAUD, timeout=1)
        print(f"[BAŞARILI] {PORT} açıldı. Dinamik klavye yayını başlıyor (10 Hz).")
    except Exception as e:
        print(f"[HATA] {PORT} açılamadı! (sudo chmod 666 /dev/ttyUSB0 yaptın mı?)")
        return

    print("---------------------------------------------------")
    print("KONTROLLER (Sadece terminal seçiliyken değil, her yerde çalışır!):")
    print("[W TUŞU]    : İleri Vites (Yön: 100 - Kalıcı)")
    print("[Z TUŞU]    : Geri Vites  (Yön: 200 - Kalıcı)")
    print("[YUKARI OK] : Gaz Pedalı (Kademeli artar max 2000, bırakınca 1500)")
    print("[AŞAĞI OK]  : Fren 1 (Bırakınca 0)")
    print("[SAĞ OK]    : Direksiyon 2000 (Bırakınca 1500)")
    print("[SOL OK]    : Direksiyon 1000 (Bırakınca 1500)")
    print("Çıkmak için : Ctrl+C")
    print("---------------------------------------------------")

    sayac = 1
    
    # Kalıcı (Stateful) değişkenler döngünün dışında tanımlanır
    yon = 100 
    hiz = 1500
    
    try:
        while True:
            # 1. Her döngüde yaylı olarak merkeze dönmesi gerekenler
            direksiyon = 1500
            fren = 0

            # --- VİTES KONTROLÜ (Kalıcı) ---
            if keyboard.is_pressed('w'):
                yon = 100
            elif keyboard.is_pressed('z'):
                yon = 200

            # --- GAZ PEDALI KONTROLÜ (Kademeli İvmelenme) ---
            if keyboard.is_pressed('up'):
                # Her döngüde (0.1 sn) hızı 25 artır. (2 saniyede 1500'den 2000'e çıkar)
                #hiz += 25
                if hiz < 2000:
                    hiz +=50 # 2000'i geçmesini engelle
            #else:
                # Tuştan elini çekince anında durma noktasına (1500) geri dönsün
               # hiz = 1500
                
            # --- FREN KONTROLÜ ---
            if keyboard.is_pressed('down'):
                fren = 1
                hiz = 1500
                
            # --- DİREKSİYON KONTROLÜ (Yaylı) ---
            if keyboard.is_pressed('right'):
                direksiyon = 2000
            elif keyboard.is_pressed('left'):
                direksiyon = 1000

            # 3. Dinamik 16-bit MSB/LSB Hesaplaması
            hiz_msb = (hiz >> 8) & 0xFF
            hiz_lsb = hiz & 0xFF

            dir_msb = (direksiyon >> 8) & 0xFF
            dir_lsb = direksiyon & 0xFF

            # 4. Paketi Oluştur
            paket = [
                16,         # B0: Sabit
                128,        # B1: Sabit
                hiz_msb,    # B2: Dinamik Hız
                hiz_lsb,    # B3: Dinamik Hız
                dir_msb,    # B4: Dinamik Açı
                dir_lsb,    # B5: Dinamik Açı
                yon,        # B6: Yön (Vites)
                fren        # B7: Fren
            ]

            byte_array = bytearray(paket)

            # 5. Kabloya Yaz ve Ekrana Bas
            ser.write(byte_array)
            
            print(f"\r[{sayac:04d}] VİTES: {yon} | HIZ: {hiz} | AÇI: {direksiyon} | FREN: {fren} | PAKET: {paket}", end="")
            
            sayac += 1
            time.sleep(0.1) # 10 Hz
            
    except KeyboardInterrupt:
        print("\n\n[BİLGİ] Test manuel olarak durduruldu.")
    finally:
        ser.close()
        print("Seri port güvenle kapatıldı.")

if __name__ == '__main__':
    main()
