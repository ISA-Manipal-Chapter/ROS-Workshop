// Include header files
#include "ros/ros.h"
// The service header file
#include "simple_msg_srv_def/EllipseArea.h"
#include "math.h"

// Definition function
bool equation(simple_msg_srv_def::EllipseArea::Request &req, 
            simple_msg_srv_def::EllipseArea::Response &res) {
    // Relation between output and input
    res.area = M_PI * req.sides.a * req.sides.b;
    ROS_INFO("Request: [%f, %f], Response: [%f]", req.sides.a, req.sides.b, res.area);
    return true;
}

int main(int argc, char **argv)
{
    // Initialize the Node, name is "Server_FloatIO"
    ros::init(argc, argv, "CPP_EllipseAreaService");
    // Node Handler
    ros::NodeHandle nodeHandler;
    // Service server
    ros::ServiceServer serviceHandler = nodeHandler.advertiseService("ellipse_area", equation);
    ROS_INFO("Service setup complete. Equation is: area = PI * a * b, area is output and a,b are inputs.");
    // Go into listening mode, spin the node
    ros::spin();
    return 0;
}

