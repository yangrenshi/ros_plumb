#! /usr/bin/env python

import rospy
from std_msgs.msg import String

if __name__ == "__main__":

    #需求：不同话题通信

    #1，全局
    pub = rospy.Publisher("/chatter",String,queue_size=1000);
    
    #2，相对
    pub = rospy.Publisher("chatter/money",String,queue_size=1000)

    #3，私有
    pub = rospy.Publisher("~chatter/money",String,queue_size=1000)

    while not rospy.is_shutdown():
        pass