#include <ros/ros.h>
#include "std_msgs/String.h"
#include <iostream>
#include <sstream>
 
int main(int argc,char **argv)
{
    ros::init(argc,argv,"talker");  
    ros::NodeHandle nh;
 
    ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",10);
    
 
    ros::Rate rate(2);
    int count = 0;
 
    while(ros::ok())  
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss<< "Hello ROS!"<<count;
        msg.data =ss.str();
 
        ROS_INFO("%s",msg.data.c_str());
        pub.publish(msg);
        ros::spinOnce();
        rate.sleep();
        ++count;
    }
    return 0;
}
