#!/usr/bin/env python
# Import files
import rospy
from simple_msg_srv_def.srv import *
import math

# Service server function
def equation(request):
    # Response object
    response = EllipseAreaResponse()
    # Relation between request and response
    response.area = request.sides.a * request.sides.b * math.pi
    rospy.loginfo("Request: [{0}, {1}], response: {2}".format(request.sides.a, request.sides.b, response.area))
    # Return the response object
    return response

def main():
    # Initialize the node
    rospy.init_node("PY_EllipseAreaService", anonymous=True)
    # Setup the server
    rospy.Service("ellipse_area", EllipseArea, equation)
    rospy.loginfo("Service activated. Equation: area = PI * a * b, area is output and a,b are inputs.")
    # Spin the node
    rospy.spin()

# Main code that will be executed
if __name__ == "__main__":
    try:
        # Main function
        main()
    except rospy.ROSInterruptException:
        rospy.logfatal("Node crashed")
