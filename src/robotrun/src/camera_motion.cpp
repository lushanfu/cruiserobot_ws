#include"robotrun/common.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "robotrun/camera_motion.h"
#include "ros/ros.h"


using namespace std;



int main(int argc,char **argv)
{
    
    ros::init(argc,argv,"oparm_move_client");
    ros::NodeHandle nh;
    ros::ServiceClient client=nh.serviceClient<robotrun::camera_motion>("camera_motion");
    robotrun::camera_motion srv;
    int anchor=stoi(argv[1]) ;

    srv.request.anchor=anchor;
    
   
    if(client.call(srv))
    {
        ROS_INFO("Response from server: %d",srv.response.status);
    }
    else
    {
        ROS_ERROR("Failde to call service operation_arm_moving");
    }
    
    
    return 0;








 
    
    



}