#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv) {
    // Initialize node
    ros::init(argc, argv, "SimpleCPP_Publisher");
    // Node Handler
    ros::NodeHandle nodeHandler;
    // Publishing object
    ros::Publisher publishingObject = nodeHandler.advertise<std_msgs::String>("topic1", 10);
    // Rate Handler (2 times a second, 2 Hz)
    ros::Rate rateHandler(2);

    while(ros::ok()) {
        // Create the message object
        std_msgs::String messageObject;
        messageObject.data.assign("C++ Publisher, publishing to topic1");
        // Publish the message object
        publishingObject.publish(messageObject);
        // Cause the delay
        rateHandler.sleep();
    }

    return 0;
}
