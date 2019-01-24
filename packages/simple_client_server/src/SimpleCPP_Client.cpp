// Header files for ROS
#include "ros/ros.h"
// For service
#include "simple_msg_srv_def/EllipseArea.h"
// For atof
#include "stdlib.h"

int main(int argc, char **argv) {
    // Initialize the node
    ros::init(argc, argv, "CPP_EllipseAreaClient");
    // Create a node handler
    ros::NodeHandle nodeHandler;
    // Create a Service Client
    ros::ServiceClient client = nodeHandler.serviceClient<simple_msg_srv_def::EllipseArea>("ellipse_area");
    // Service object
    simple_msg_srv_def::EllipseArea srv;
    // Assign value to request
    srv.request.sides.a = atof(argv[1]);
    srv.request.sides.b = atof(argv[2]);
    // Call the service
    if (client.call(srv)) {
        // srv.response now has value
        ROS_INFO("[a, b] = [%f, %f], area = %f", srv.request.sides.a, 
            srv.request.sides.b, srv.response.area);
    } else {
        ROS_ERROR("Service call failed");
    }
    return 0;
}
