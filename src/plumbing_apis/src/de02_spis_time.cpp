// #include "ros/ros.h"

// /*
//     需求1：演示时间相关操作（获取当前时刻 + 设置指定时刻
//     实现：
//         1，准备（头文件，节点初始化，NodeHandle创建。。。）
//         2，获取当前时刻
//         3，如何设置指定时刻

//     需求2：程序执行中停顿 5秒
//     实现：
//         1，创建持续时间对象
//         2.休眠
//     需求3，已知程序开始运行的 时刻和程序运行的时间，求运行结束的时刻
//     实现：
//         1，获取开始执行的时间
//         2，模拟运行时间（N秒）
//         3，计算结束时间 = 开始 - 结束
//     注意：
//         1，时刻与持续时间可以加减
//         2，时刻时间之间也可以加减
//         3，时刻之间只能相减，不能相加
    
//     需求4：每隔1秒钟，在控制台输出一个文本
//     实现：
//         策略1：ros:Rate()
//         策略2：定时器
//     注意：
//         创建：nh.createTimer()
//         参数1：时间间隔
//         参数2：回调函数（时间事件 TimerEvent）
//         参数3：是否只执行一次
//         参数4：是否自动启动（当设置为false，需要手动调用timer。start()）

//         定时器启动后ros::spin() 
// */    

// //回调函数
// void cb(const ros::TimerEvent& event)
// {
//     ROS_INFO("-----------");
//     ROS_INFO("函数被调用的时刻:%.2f",event.current_real.toSec());
// }

// int main(int argc, char *argv[])
// { 
//     //1，准备（头文件，节点初始化，NodeHangle创建）
//     setlocale(LC_ALL,"");
//     ros::init(argc,argv,"hello_time");
//     ros::NodeHandle nh;//必须创建句柄，否则时间没有初始化，导致后续API调用失败

//     // 2，获取当前时刻
//     // now函数会将当前时刻封装并返回
//     // 当前时刻：now被调用执行的那一刻
//     // 参考系：1970年01月01日 00：00：00

//     ros::Time right_now = ros::Time::now();//将当前时刻封装成对象
//     ROS_INFO("当前时刻:%.2f",right_now.toSec());//获取距离 1970年01月01日 00:00:00 的秒数，double类型
//     ROS_INFO("当前时刻:%d",right_now.sec);//获取距离 1970年01月01日 00:00:00 的秒数，整形

//     //3，设置指定时间
//     ros::Time t1(20,312345678);
//     ros::Time t2(100.35);
//     ROS_INFO("t1 = %.2f",t1.toSec());//获取距离 1970年01月01日 00:00:00 的秒数，double类型
//     ROS_INFO("t2 = %.2f",t2.toSec());//获取距离 1970年01月01日 00:00:00 的秒数，double类型

//     //2.持续时间
//     ROS_INFO("持续时间------------");
//     ros::time start = ros::Time::now();
//     ROS_INFO("开始休眠:%.2f",start.toSec());
//     ROS_INFO("当前时刻:%.2f",ros::Time::now().toSec());
//     ros::Duration du(10);//持续10秒钟,参数是double类型的，以秒为单位
//     du.sleep();//按照指定的持续时间休眠
//     ROS_INFO("持续时间:%.2f",du.toSec());//将持续时间换算成秒
//     ROS_INFO("休眠结束时刻:%.2f",ros::Time::now().toSec());

//     ROS_INFO("时间运算------------");
//     //1，获取开始执行的时间
//     ros::Time now = ros::Time::now();
//     //2，模拟运行时间(秒)
//     ros::Duration du1(10);
//     ros::Duration du2(20);
//     ROS_INFO("当前时刻:%.2f",now.toSec());
//     //1.time 与 duration 运算
//     ros::Time after_now = now + du1;
//     ros::Time before_now = now - du1;
//     ROS_INFO("当前时刻之后:%.2f",after_now.toSec());
//     ROS_INFO("当前时刻之前:%.2f",before_now.toSec());

//     //2.duration 之间相互运算
//     ros::Duration du3 = du1 + du2; 
//     ros::Duration du4 = du1 - du2;
//     ROS_INFO("du3 = %.2f",du3.toSec());
//     ROS_INFO("du4 = %.2f",du4.toSec());
//     //PS: time 与 time 不可以运算
//     // ros::Time nn = now + before_now;//异常

//     ROS_INFO("-------------------定时器---------------------");
//     /*
//         ros::Timer createTImer(ros::Duration period,  //时间间隔 ---1s)
//             const ros::TimerCallback &callback,       //回调函数---封装业务
//             bool oneshot = false,                     //是否是一次性
//             bool autostart = true)                    //自动启动
//     */
//     ros::NodeHandle nh;//必须创建句柄，否则时间没有初始化，导致后续API调用失败

//     // ROS 定时器
//     /**
//     * \brief 创建一个定时器，按照指定频率调用回调函数。
//     *
//     * \param period 时间间隔
//     * \param callback 回调函数
//     * \param oneshot 如果设置为 true,只执行一次回调函数，设置为 false,就循环执行。
//     * \param autostart 如果为true，返回已经启动的定时器,设置为 false，需要手动启动。
//     */
//     //Timer createTimer(Duration period, const TimerCallback& callback, bool oneshot = false,
//     //                bool autostart = true) const;

//     // ros::Timer timer = nh.createTimer(ros::Duration(0.5),doSomeThing);
//     ros::Timer timer = nh.createTimer(ros::Duration(0.5),cb,true);//只执行一次

//     // ros::Timer timer = nh.createTimer(ros::Duration(0.5),doSomeThing,false,false);//需要手动启动
//     // timer.start();
//     ros::spin(); //必须 spin

   

//     return 0;  
// }