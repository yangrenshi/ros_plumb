#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"haha");
    ros::NodeHandle nh;

    //用param设置
    ros::param::set("/set_A",100); //全局,和命名空间以及节点名称无关
    ros::param::set("set_B",100); //相对,参考命名空间
    ros::param::set("~set_C",100); //私有,参考命名空间与节点名称

    //用NodeHandle设置

    ros::NodeHandle nh1;
    nh1.setParam("/nh1_A",100); //全局,和命名空间以及节点名称无关

    nh1.setParam("nh1_B",100); //相对,参考命名空间

    ros::NodeHandle nh2_private("~");
    nh2_private.setParam("nh1_C",100);//私有,参考命名空间与节点名称

    /* code */
    return 0;
}
