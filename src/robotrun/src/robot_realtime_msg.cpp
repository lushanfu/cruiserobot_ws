#include"robotrun/common.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <ros/ros.h>
#include<pthread.h>

using namespace std;


int main(int argc,char **argv)
{
   CFixedArmParseData fixedParse;
   CMovingArmParseData movedParse;
   robotrun::robot_data robotData;
   CUtils cutil;
   ros::init(argc,argv,"talker");  
   ros::NodeHandle nh;
   ros::Rate rate(10);
 
   ros::Publisher pub = nh.advertise<robotrun::robot_data>("robot_msgs",10);
   while(ros::ok)
    {
        
        
        robotData=cutil.obtainMsg();
        pub.publish(robotData);
        ros::spinOnce();
        rate.sleep();
        
        // ROS_INFO("operation arm approach fixed_arm distance is %d",robotData.fixedArmData.opArmDistance);
        // ROS_INFO("operation arm approach moving_arm distance is %d",robotData.movingArmData.opArmDistance);
       
    }
}