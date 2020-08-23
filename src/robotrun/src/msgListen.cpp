#include"robotrun/common.h"
#include <ros/ros.h>

void chatcallback(const robotrun::robot_dataConstPtr & data)//回调函数
{
    ROS_INFO("I heared fixed horizontal bagnum is :[%d]",data->fixedArmData.hArmBagNum);
}
int main(int argc,char **argv)
{
    ros::init(argc,argv,"msgListener");
    ros::NodeHandle nh;
 
    ros::Subscriber sub = nh.subscribe("dataTransfer",1000,chatcallback);
    ros::spin();
    return 0;
}