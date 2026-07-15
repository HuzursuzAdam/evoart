import logging
from launch import LaunchDescription
from launch_ros.actions import Node

# Özel Log Filtresi: Sadece belirli bir metni içeren logları engeller
class GecersizLogFiltresi(logging.Filter):
    def filter(self, record):
        # Eğer log mesajının içinde bu metin geçiyorsa False döndür (Gösterme)
        if 'process started with pid' in record.getMessage():
            return False
        # Diğer tüm durumlarda True döndür (Göster)
        return True

# Filtremizi ROS 2'nin 'launch' loglayıcısına takıyoruz
launch_logger = logging.getLogger('launch')
launch_logger.addFilter(GecersizLogFiltresi())
# Dikkat: setLevel komutunu sildik, böylece diğer INFO'lar çalışmaya devam edecek

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='evoart_control',
            executable='stm32_odom_node',
            name='stm32_odom_node',
            output='screen',
            emulate_tty=True,
        )
    ])
