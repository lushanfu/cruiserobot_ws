#include"robotrun/common.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"ros/ros.h"
#include"robotrun/op_arm.h"
#include"robotrun/camera_motion.h"
using namespace std;
int main(int argc,char ** argv)
{
    CFixedArmParseData fixedParse;
    CMovingArmParseData movingParse;
    ros::init(argc,argv,"action");
    ros::NodeHandle nh;
    int direction=*argv[1]-'0';

    ros::ServiceClient client=nh.serviceClient<robotrun::op_arm>("oparm_move");
    robotrun::op_arm srv;

    ros::ServiceClient client2=nh.serviceClient<robotrun::camera_motion>("camera_motion");
    robotrun::camera_motion srv2;
    if (0==direction)
    {
        srv.request.stopThreshold=19;
        srv.request.travelDirection=0;
        srv2.request.anchor=1;
        client2.call(srv2);
        client.call(srv);


        movingParse.motorTravelControl(MotorState::neutralPos,0);
        fixedParse.motorTravelControl(MotorState::walkBackward,30);
        movingParse.motorTravelControl(MotorState::walkBackward,30);
        
    }
    else
    {
        srv.request.stopThreshold=19;
        srv.request.travelDirection=1;
        srv2.request.anchor=2;
        client2.call(srv2);
        client.call(srv);

        fixedParse.motorTravelControl(MotorState::neutralPos,0);
        movingParse.motorTravelControl(MotorState::walkForward,30);
        fixedParse.motorTravelControl(MotorState::walkForward,30);
    }
    
    
    return 0;
}