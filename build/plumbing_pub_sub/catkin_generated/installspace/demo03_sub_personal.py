#!/usr/bin/env python3

"""
    需求: 
        编写两个节点实现服务通信，客户端节点需要提交两个整数到服务器
        服务器需要解析客户端提交的数据，相加后，将结果响应回客户端，
        客户端再解析

    客户端实现:
        1.导包
        2.初始化 ROS 节点
        3.创建请求对象
        4.发送请求
        5.接收并处理响应

    优化:
        加入数据的动态获取


"""
#1.导包
import rospy
from plumbing_pub_sub.msg import Personal


def doPersonal(p):
    rospy.loginfo('小伙子数据有:%s,%d,%.2f',p.name,p.age,p.height)

if __name__ == "__main__":


    # 2.初始化 ROS 节点
    rospy.init_node("daye")
    sub = rospy.Subscriber("marry",Personal,doPersonal)
    rospy.spin()
 
