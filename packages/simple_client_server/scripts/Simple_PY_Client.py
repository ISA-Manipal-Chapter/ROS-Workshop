#!/usr/bin/env python
# Import libraries
import rospy
# Service files
from simple_msg_srv_def.srv import *
from simple_msg_srv_def.msg import EllipseSides
# System files
import sys

def main():
    # Initialize the node
    rospy.init_node("PY_EllipseAreaClient", anonymous=True)
    # Initialize Service Client
    serviceClient = rospy.ServiceProxy("ellipse_area", EllipseArea)
    # Call the service and then receive response
    response = serviceClient(EllipseSides(float(sys.argv[1]), float(sys.argv[2])))
    rospy.loginfo("[a,b] = [{0},{1}], area = {2}".format(float(sys.argv[1]), float(sys.argv[2]), response))

if __name__ == "__main__":
    try:
        main()
    except rospy.ROSInterruptException:
        rospy.logfatal("Node crashed")
