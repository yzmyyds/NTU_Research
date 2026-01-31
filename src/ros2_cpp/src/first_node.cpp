#include "rclcpp/rclcpp.hpp"

class FirstNode : public rclcpp::Node{

    public:
        FirstNode() : Node("first_node") {
            RCLCPP_INFO(this->get_logger(),"Hello Node with cpp");
            timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&FirstNode::timer_callback, this));
 
        }

    private:
        int counter =0;
        rclcpp::TimerBase::SharedPtr timer_;

        void timer_callback(){
            RCLCPP_INFO(this->get_logger(),"%i",counter);
            counter++;
        }
};



int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<FirstNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}