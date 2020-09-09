#include"robotrun/common.h"
#include <ros/ros.h>
#include<iostream>
using namespace std;
int main()
{
    
    CMovingArmParseData movingData;
    CFixedArmParseData  fixedData;
    SpeedType speed;
    while (true)
    {
        speed=fixedData.travelSpeed();
        // if(speed.distance>128)
        //   speed.distance=abs(speed.distance-255);
        
        cout<<"num is: "<<speed.bagNum<<"\t"<<"speed is :"<<speed.distance<<endl;
        sleep(1);
       
    }
    // CUtils utils;
    // utils.travelFixedDistance(UnitType::movingArm,0.5);
    return 0;
    
    // robotrun::fixed_arm fixedData;
    // robotrun::moving_arm movingData;
    // robotrun::robot_data robotData;
    // CUtils utils;
    // robotData=utils.obtainMsg();
   
    // CFixedArmParseData  fixedData;
    // fixedData.verticalArmRotMotor(MotorState::walkForward,11,70);
    movingData.motorTravelControl(MotorState::walkBackward,60);
   for (size_t i = 0; i < 3; i++)
   {
       movingData.motorTravelControl(MotorState::walkBackward,50);
       
       
      
   }
   //sleep(1);
   movingData.motorTravelControl(MotorState::neutralPos,0);
    

}