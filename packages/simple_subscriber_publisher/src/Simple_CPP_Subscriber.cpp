#include "ros/ros.h"
#include "std_msgs/String.h"

void receivedMessage(const std_msgs::String::ConstPtr &msg) {
    ROS_INFO("Message received (C++ Subscriber): %s", msg->data.c_str());
}

int main(int argc, char **argv) {
    // Initialize Node
    ros::init(argc, argv, "SimpleCPP_Subscriber");
    // Node Handler
    ros::NodeHandle nodeHandler;
    // Subscriber object
    ros::Subscriber subscriberObject = nodeHandler.subscribe<std_msgs::String>("topic1", 10, receivedMessage);
    // Spin the node
    ros::spin();
    return 0;
}
