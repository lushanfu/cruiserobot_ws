#include <ros/ros.h>
#include "robotrun/common.h"

 
void chatcallback(const robotrun::robot_data & msg)//回调函数
{
    ROS_INFO("operation arm approach fixed_arm distance is %d",msg.fixedArmData.opArmDistance);
    ROS_INFO("operation arm approach moving_arm distance is %d",msg.movingArmData.opArmDistance);
}
int main(int argc,char **argv)
{
    ros::init(argc,argv,"listener");
    ros::NodeHandle nh;
 
    ros::Subscriber sub = nh.subscribe("robot_msgs",1000,chatcallback);
    ros::spin();
    return 0;
}
