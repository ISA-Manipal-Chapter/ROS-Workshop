#!/usr/bin/env python
import rospy
from std_msgs.msg import String

def receivedMessage(msg):
    # Print message
    rospy.loginfo("Message received (Python Subscriber): {0}".format(msg.data))

if __name__ == "__main__":
    # Initialize node
    rospy.init_node("SimplePY_Subscriber")
    # Subscriber object
    subscriberObject = rospy.Subscriber('topic1', String, receivedMessage, queue_size=10)
    # Spin node
    rospy.spin()