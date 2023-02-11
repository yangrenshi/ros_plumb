/*
    需求: 
        编写两个节点实现服务通信，客户端节点需要提交两个整数到服务器
        服务器需要解析客户端提交的数据，相加后，将结果响应回客户端，
        客户端再解析

    服务器实现:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建 ROS 句柄
        4.创建 客户端 对象
        5.请求服务，接收响应

*/
// 1.包含头文件
#include "ros/ros.h"
#include "plumbing_pub_sub/Personal.h" 

void doPerson(const plumbing_pub_sub::Personal::ConstPtr& personal)
{
    ROS_INFO("订阅人的消息:%s,%d,%.2f",personal->name.c_str(),personal->age,personal->height);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    // 2.初始化 ROS 节点
    ros::init(argc,argv,"jiazhang");
    // 3.创建 ROS 句柄
    ros::NodeHandle nh;
    // 4.创建 客户端 对象
    ros::Subscriber sub = nh.subscribe("chatter",10,doPerson);
    //5,处理订阅的数据

    //6,调用spin()函数
    ros::spin();
    return 0;
}
