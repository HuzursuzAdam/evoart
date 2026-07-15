#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import os
from ament_index_python.packages import get_package_share_directory

# Not: Model işlemleri için 'pip install ultralytics' veya ONNX runtime gereklidir.

class ObjectDetectorNode(Node):
    def __init__(self):
        super().__init__('object_detector')
        
        # ROS görüntüsünü OpenCV'ye çevirecek köprü
        self.bridge = CvBridge()
        
        # Kamera görüntüsünü dinle
        self.subscription = self.create_subscription(
            Image,
            '/zed/zed_node/rgb/image_rect_color', # Kamera topic ismi
            self.image_callback,
            10)
            
        # Modelin kurulu olduğu yolu dinamik olarak bul
        pkg_dir = get_package_share_directory('evoart_perception')
        model_path = os.path.join(pkg_dir, 'models', 'robotaksi_yolo.onnx')
        
        self.get_logger().info(f'YOLO Modeli Yukleniyor: {model_path}')
        # self.model = cv2.dnn.readNetFromONNX(model_path) # ONNX yükleme örneği

    def image_callback(self, msg):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
            
            # TODO: YOLO tahmin kodları buraya gelecek
            
            # Görüntüyü test için ekranda göster
            cv2.imshow("Object Detection", cv_image)
            cv2.waitKey(1)
        except Exception as e:
            self.get_logger().error(f'Goruntu hatasi: {e}')

def main(args=None):
    rclpy.init(args=args)
    node = ObjectDetectorNode()
    rclpy.spin(node)
    node.destroy_node()
    cv2.destroyAllWindows()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
