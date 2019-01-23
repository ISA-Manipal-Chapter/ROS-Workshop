// Include the main header file
#include "ros/ros.h"

int main(int argc, char **argv) {
    // Initialize the node
    ros::init(argc, argv, "ArgumentParser");
    // Display output
    ROS_INFO_STREAM(argc << " arguments received");
    for (int i = 0; i < argc; i++) {
        ROS_INFO_STREAM("Argument "<<i<<": "<<argv[i]);
    }
    // End program
    return 0;
}
