#include"robotrun/common.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "robotrun/op_arm.h"
#include "ros/ros.h"
#include"robotrun/camera_motion.h"

using namespace std;

void* op_arm_move(void * arg)
{
    
     int anchor=*((int*)arg);
    
}


int main(int argc,char **argv)
{
    
    ros::init(argc,argv,"oparm_move_client");
    ros::NodeHandle nh;
    ros::ServiceClient client=nh.serviceClient<robotrun::op_arm>("oparm_move");
    robotrun::op_arm srv;
    int stopPos=stoi(argv[2]) ;

    int travelDirection=*argv[1]-'0';
    srv.request.stopThreshold=stopPos;
    srv.request.travelDirection=*argv[1]-'0';
    
    // pthread_t threads[1];
    // pthread_create(&threads[0],NULL,&op_arm_move,&travelDirection);

    ros::ServiceClient client2=nh.serviceClient<robotrun::camera_motion>("camera_motion");
    robotrun::camera_motion srv2;
    int anchor=2;
    if(travelDirection==0)
    {
        anchor=1;
    }
    srv2.request.anchor=anchor;
    if(client2.call(srv2))
    {
        ROS_INFO("Response from server: %d",srv2.response.status);
    }
    else
    {
        ROS_ERROR("Failde to call service operation_arm_moving");
    }

    if(client.call(srv))
    {
        ROS_INFO("Response from server: %s",srv.response.feedmsg.c_str());
    }
    else
    {
        ROS_ERROR("Failde to call service operation_arm_moving");
    }
    
    
    
    return 0;
 
}