#include <ros/ros.h>
#include"robotrun/obstacle.h"
#include "robotrun/common.h"

#include<ctime>
int main(int argc,char **argv)
{
   int threshold=*argv[1]-'0';
   ros::init(argc, argv, "param_demo");
   ros::NodeHandle nh;
   int obstacleType,distance;
   CFixedArmParseData fixedArm;
   CMovingArmParseData movingArm;
   movingArm.motorTravelControl(MotorState::neutralPos,0);
   fixedArm.motorTravelControl(MotorState::neutralPos,0);
   while (true)
   {
	 bool ifget1 = ros::param::get("obstacle_type", obstacleType);
	 bool ifget2 = nh.getParam("distance",distance);
     time_t first,second; 
     first=time(NULL);
     //tm* t=localtime(&first);
     //cout<<t->tm_hour<<":"<<t->tm_min<<":"<<t->tm_sec<<endl;
     while (nh.getParam("distance",distance) && distance>threshold)
     {
         //一直走，双驱
         second=time(NULL);
         int secdiff=(int)difftime(second,first);
         if(secdiff>0)
         {
             first=time(NULL);  
             
             fixedArm.motorTravelControl(MotorState::walkBackward,30);
             movingArm.motorTravelControl(MotorState::walkBackward,30);    
         }
         cout<<"current distance is : "<<distance<<endl; 
     }
     //刹车
     movingArm.motorTravelControl(MotorState::neutralPos,0);
     fixedArm.motorTravelControl(MotorState::neutralPos,0);
     movingArm.motorTravelControl(MotorState::brake,0);
     fixedArm.motorTravelControl(MotorState::brake,0);
     //开启越障动作
     break;

   }
   

    //TODO 先根据电池电量状态，判断是否要充电，能否到达充电点或者是就地锁住待救援
    //TODO 先根据地图导航数据来判断位置
    //TODO 根据地图导航的结果来判断是否调用图像测距方法
    //TODO 根据图像测距方法来确定是否执行越障指令

}
