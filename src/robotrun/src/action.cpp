#include"robotrun/common.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "robotrun/op_arm.h"
#include "ros/ros.h"


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
    
    // CFixedArmParseData fixedParse;
    // CMovingArmParseData movedParse;
    // //fixedParse.opArmMovingControl(MotorState::walkForward,60,0);
    // pthread_t threads[1];
    // pthread_create(&threads[0],NULL,&op_arm_move,&travelDirection);
  
    
    // while (true)
    // {
    //     if (travelDirection==0 && fixedParse.opArmApproachDis()>=stopPos  || travelDirection==1 && movedParse.opArmApproachDis()>=stopPos)
    //     {
    //         //线程结束
            
    //         pthread_cancel(threads[0]);
    //         break;
    //     }
    //     sleep(0.01);


    // }
    // fixedParse.opArmMovingControl(MotorState::brake,0,0);
    // fixedParse.opArmMovingControl(MotorState::neutralPos,0,0);
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