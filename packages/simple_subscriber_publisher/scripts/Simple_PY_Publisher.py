#!/usr/bin/env python
import rospy
from std_msgs.msg import String

if __name__ == "__main__":
    # Initialize node
    rospy.init_node("SimplePY_Publisher")
    # Create a publisher object
    publisherObject = rospy.Publisher('topic1', String, queue_size=10)
    # Create a rate handler 2 Hz
    rateHandler = rospy.Rate(2)
    
    while(not rospy.is_shutdown()):
        # Create message
        messageObject = String()
        messageObject.data = "Python Publisher, publishing to topic1"
        # Publish message
        publisherObject.publish(messageObject)
        rateHandler.sleep()


