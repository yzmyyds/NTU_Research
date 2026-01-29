import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class Simplelistener(Node):
    def __init__(self):
        super().__init__('listener_node')
        self.subscription_=self.create_subscription(String, 'chatter', self.listener_callback, 10)

    def listener_callback(self,msg):
        self.get_logger().info(f'Receive: {msg.data}')

def main(args=None):
    rclpy.init(args=args)
    node = Simplelistener()
    rclpy.spin(node)
    rclpy.shutdown()
