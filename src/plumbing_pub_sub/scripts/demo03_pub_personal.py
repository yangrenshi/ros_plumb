#! /usr/bin/env python
"""
    需求: 
        编写两个节点实现服务通信，客户端节点需要提交两个整数到服务器
        服务器需要解析客户端提交的数据，相加后，将结果响应回客户端，
        客户端再解析

    服务器端实现:
        1.导包
        2.初始化 ROS 节点
        3.创建服务对象
        4.回调函数处理请求并产生响应
        5.spin 函数

"""
# 1.导包

import rospy
from plumbing_pub_sub.msg import Personal


if __name__ == "__main__":
    # 2.初始化 ROS 节点
    rospy.init_node("dama")
    # 3.创建服务对象
    pub = rospy.Publisher("marry",Personal,queue_size=10)

    p = Personal()
    p.name = "奥特"
    p.age = 8
    p.height = 1.70
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        pub.publish(p)
        rospy.loginfo("发送的消息:%s,%d,%.2f",p.name,p.age,p.height)
        rate.sleep()
