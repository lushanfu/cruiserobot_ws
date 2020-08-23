#include"robotrun/common.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <ros/ros.h>
#include<pthread.h>
#include"robotrun/op_arm.h"
using namespace std;
void* op_arm_move(void * arg)
{
     CFixedArmParseData fixedParse;
     int motor=*((int*)arg);
    ros::Rate rate(8);
     while (true)
     {
         if(1==motor)
         {
             fixedParse.opArmMovingControl(MotorState::walkForward,30,0);
         }
         else
         {
             fixedParse.opArmMovingControl(MotorState::walkBackward,30,0);
         }
         rate.sleep();
     }
     
}

bool oparm_move(robotrun::op_arm::Request &req,robotrun::op_arm::Response &res)
{
    CFixedArmParseData fixedParse;
    CMovingArmParseData movedParse;
    int threshold=req.stopThreshold;
    int travelDirection=req.travelDirection;
    // if (1==travelDirection)
    // {   
    //     while (movedParse.opArmApproachDis()<threshold)
    //     {
    //         fixedParse.opArmMovingControl(MotorState::walkForward,15,0);
    //         //sleep(0.1);   
    //     }             
    // }
    // else
    // {
    //      while (fixedParse.opArmApproachDis()<threshold)
    //     {
    //          fixedParse.opArmMovingControl(MotorState::walkBackward,15,0);
    //          //sleep(0.1);   
    //     }
    // }

    pthread_t threads[1];
    pthread_create(&threads[0],NULL,&op_arm_move,&travelDirection);
  
    
    while (true)
    {
        if (travelDirection==0 && fixedParse.opArmApproachDis()>=req.stopThreshold  || travelDirection==1 && movedParse.opArmApproachDis()>=req.stopThreshold)
        {
            //线程结束
            
            pthread_cancel(threads[0]);
            break;
        }
        sleep(0.01);
    }
    fixedParse.opArmMovingControl(MotorState::brake,0,0);
    fixedParse.opArmMovingControl(MotorState::neutralPos,0,0);
    res.feedmsg="Hi Guys,Your replay is completed! thank you";  
    return true;
}
int main(int argc,char **argv)
{
    ros::init(argc,argv,"oparm_move_server");
    ros::NodeHandle nh;
    ros::ServiceServer service=nh.advertiseService("oparm_move",oparm_move);
    ros::spin();  
    return 0;

}