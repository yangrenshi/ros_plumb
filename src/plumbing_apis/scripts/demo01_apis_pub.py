#! /usr/bin/env python
"""
    需求: 实现基本的话题通信，一方发布数据，一方接收数据，
         实现的关键点:
         1.发送方
         2.接收方
         3.数据(此处为普通文本)

         PS: 二者需要设置相同的话题


    消息发布方:
        循环发布信息:HelloWorld 后缀数字编号

    实现流程:
        1.导包 
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 发布者 对象
        4.组织被发布的数据，并编写逻辑发布数据


"""
#1.导包 
import rospy
from std_msgs.msg import String

if __name__ == "__main__":
    #2.初始化 ROS 节点:命名(唯一)
    """
        作用:ROS初始化

        参数：
            name ----设置节点名称
            argv=None,  ----封装节点调用时传递的参数
            anonymous=False, ---可以为节点名词生成随即后缀，可以解决重名问题

        使用：
            1,argv使用
            可以按照ROS中指定的语法格式传参，ROS可以解析并加以使用
            2,anonymous使用
            设值为true避免重复

    """
    rospy.init_node("talker_p",anonymous=True)
    #3.实例化 发布者 对象
    """
        内容：latch
            bool值，默认是False
        作用：
            如果设置为True，可以将发布的最后一条数据保存，且后续当新的订阅对象连接时，会将
            该数据发送给订阅者
        使用：
            latch = True
    """
    pub = rospy.Publisher("chatter",String,queue_size=10,latch=True)
    #4.组织被发布的数据，并编写逻辑发布数据
    msg = String()  #创建 msg 对象
    msg_front = "hello 你好"
    count = 0  #计数器 
    # 设置循环频率
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        count +=1

        #发布数据
        if count <=10:
            pass
        #拼接字符串
            msg.data = msg_front + str(count)

            pub.publish(msg)
            rospy.loginfo("写出的数据:%s",msg.data)
        rate.sleep()