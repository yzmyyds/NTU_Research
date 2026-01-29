import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from geometry_msgs.msg import Point

class Simplepublisher(Node):
    def __init__(self):
        super().__init__('talker_node')
        self.publisher_ = self.create_publisher(Point, 'robot_pos', 10)
        self.timer_=self.create_timer(5.0, self.timer_callback)
        self.x=0.0

    def timer_callback(self):
        msg=Point()
        msg.x=self.x
        msg.y=self.x*2
        msg.z=10.0
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publish: [{msg.x},{msg.y},{msg.z}]')
        self.x += 1.0

def main(args=None):
    rclpy.init(args=args)
    node = Simplepublisher()
    rclpy.spin(node)
    rclpy.shutdown()