#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from pynput import keyboard

class GlobalTeleop(Node):
    def __init__(self):
        super().__init__('global_teleop')
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        self.msg = Twist()
        
        # Hız ayarları
        self.speed = 0.5
        self.turn = 1.0

        # Klavye dinleyicisini başlat (Arka plan thread'i olarak çalışır)
        self.listener = keyboard.Listener(
            on_press=self.on_press,
            on_release=self.on_release)
        self.listener.start()
        
        self.get_logger().info('Global Teleop Aktif! Pencere odağı olmadan Gazebo arka plandayken aracı kontrol edebilirsin.')
        self.get_logger().info('Kontroller: W (İleri), S (Geri), A (Sol), D (Sağ). Çıkmak için terminalde CTRL+C bas.')

    def on_press(self, key):
        try:
            if key.char == 'w':
                self.msg.linear.x = self.speed
                self.msg.angular.z = 0.0
            elif key.char == 's':
                self.msg.linear.x = -self.speed
                self.msg.angular.z = 0.0
            elif key.char == 'a':
                self.msg.linear.x = 0.0
                self.msg.angular.z = self.turn
            elif key.char == 'd':
                self.msg.linear.x = 0.0
                self.msg.angular.z = -self.turn
                
            self.publisher_.publish(self.msg)
        except AttributeError:
            # Özel tuşlara (Shift, Ctrl vb.) basıldığında hata vermesini engeller
            pass

    def on_release(self, key):
        # Tuş bırakıldığında aracı durdur
        try:
            if key.char in ['w', 'a', 's', 'd']:
                self.msg.linear.x = 0.0
                self.msg.angular.z = 0.0
                self.publisher_.publish(self.msg)
        except AttributeError:
            pass

def main(args=None):
    rclpy.init(args=args)
    node = GlobalTeleop()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
