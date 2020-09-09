#include <ros/ros.h>
#include"robotrun/obstacle.h"
#include "robotrun/common.h"
#include<pthread.h>
#include<ctime>


void* movingArmX2Pos(void* argv)
{
    CUtils utils;
    int threshold=*((int *)argv);
    utils.movingArmX2Pos(threshold);
}
void* movingArmY2Pos(void* argv)
{
    CUtils utils;
    int threshold=*((int *)argv);
    utils.movingArmY2Pos(threshold);
}

void* movingArmZ2Pos(void* argv)
{
    CUtils utils;
    int threshold=*((int *)argv);
    utils.movingArmZ2Pos(threshold);
}

void* fixedArmX2Pos(void* argv)
{
    CUtils utils;
    int threshold=*((int *)argv);
    utils.fixedArmX2Pos(threshold);
}
void* fixedArmY2Pos(void* argv)
{
    CUtils utils;
    int threshold=*((int *)argv);
    utils.fixedArmY2Pos(threshold);
}

void* controlCabinet2Pos(void* argv)
{
    CUtils utils;
    int threshold=*((int *)argv);
    utils.controlCabinet2Pos(threshold);
}




void step_00(UnitType unitType, AnchorPos & anchorPos)
{
    pthread_t tids[6];
    int rc;
    void* status;
    int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A1));
    int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B1));
    int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
    int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D1));
    int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E1));
    int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G1));
    //pthread_exit(NULL);
    for(int i=0;i<6;++i)
    {
      rc=pthread_join(tids[i],&status);
    }
}
void step_01(UnitType unitType, AnchorPos & anchorPos)
{
    pthread_t tids[6];
    void* status;
    int rc;
    if(unitType==UnitType::fixedArm)
    {
        
      int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A3));
      int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B1));
      int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
      int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D1));
      int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E1));
      int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G6));  
    }
    else
    {
      int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A1));
      int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B1));
      int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
      int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D3));
      int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E1));
      int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G4));
    }
   // pthread_exit(NULL);
   for(int i=0;i<6;++i)
    {
      rc=pthread_join(tids[i],&status);
    }
   
   
}
void step_02(UnitType unitType, AnchorPos & anchorPos)
{
    pthread_t tids[6];
    int rc;
    void* status;
    if(unitType==UnitType::fixedArm)
    {
        
      int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A3));
      int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B2));
      int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
      int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D1));
      int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E1));
      int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G6));  
    }
    else
    {
      int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A1));
      int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B1));
      int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
      int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D3));
      int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E2));
      int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G4));
    }
    //pthread_exit(NULL);
     for(int i=0;i<6;++i)
    {
      rc=pthread_join(tids[i],&status);
    }
}
void step_03(UnitType unitType,AnchorPos & anchorPos)
{
    CUtils utils;
    pthread_t tids[6];
    int rc;
    void* status;
    CMovingArmParseData movingParse;
    if(unitType==UnitType::fixedArm)
    {    
      int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A3));
      int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B1));
      int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
      int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D1));
      int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E1));
      int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G6)); 

    }
    else
    {
      int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A1));
      int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B1));
      int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
      int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D3));
      int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E1));
      int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G4));
    }
    //pthread_exit(NULL);
    for(int i=0;i<6;++i)
    {
      rc=pthread_join(tids[i],&status);
    }
    movingParse.verticalArmRotMotor(MotorState::walkBackward,10,1);
   
}
void step_04(UnitType unitType, AnchorPos & anchorPos)
{
    pthread_t tids[6];
    if(unitType==UnitType::fixedArm)
    {
      int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A1));
      int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B1));
      int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
      int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D1));
      int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E1));
      int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G6));  
    }
    else
    {
      int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A1));
      int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B1));
      int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
      int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D1));
      int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E1));
      int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G4));
    }
    pthread_exit(NULL);
}
void step_05(UnitType unitType, AnchorPos & anchorPos)
{
    pthread_t tids[6];
    if(unitType==UnitType::fixedArm)
    {
        
      int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G4));
      sleep(6);  
      int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A1));
      int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B1));
      int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
      int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D3));
      int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E1));
      
    }
    else
    {
      int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G6));
      sleep(6);
      int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A3));
      int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B1));
      int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
      int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D1));
      int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E1));
      
    }
    pthread_exit(NULL);
}
void step_06(UnitType unitType, AnchorPos & anchorPos)
{
    pthread_t tids[6];
    if(unitType==UnitType::fixedArm)
    {
      int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A1));
      int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B1));
      int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
      int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D3));
      int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E2));
      int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G4));
    }
    else
    {
      int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A3));
      int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B2));
      int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
      int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D1));
      int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E1));
      int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G6));
      
    }
    pthread_exit(NULL);
}
void step_07(UnitType unitType,AnchorPos & anchorPos)
{
    pthread_t tids[6];
    if(unitType==UnitType::fixedArm)
    {
      int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A1));
      int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B1));
      int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
      int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D3));
      int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E1));
      int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G4));
    }
    else
    {
      int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A3));
      int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B1));
      int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
      int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D1));
      int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E1));
      int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G6));
      
    }
    pthread_exit(NULL);
}
void step_08(UnitType unitType, AnchorPos & anchorPos)
{
    CUtils utils;

    pthread_t tids[6];
    if(unitType==UnitType::fixedArm)
    {
      int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A1));
      int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B1));
      int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
      int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D1));
      int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E1));
      int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G1));
    }
    else
    {
      int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A1));
      int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B1));
      int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
      int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D1));
      int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E1));
      int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G1)); 
    }
    pthread_exit(NULL);
}

void fixedObstacleRecovery()
{

}
void fixedObstacleCrossing(AnchorPos & anchorPos)
{
    step_00(UnitType::fixedArm,anchorPos);
    step_01(UnitType::fixedArm,anchorPos);
    //step_02(UnitType::fixedArm,anchorPos);
    //step_03(UnitType::fixedArm,anchorPos);
    
    
}
void movingObstacleCrossing(){}
void movingObstacleRecovery(){}
void crossObstacleMotion(){}


int main(int argc,char **argv)
{
   int threshold=stoi(argv[1]);
   ros::init(argc, argv, "param_demo");
   AnchorPos anchor;
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
     sleep(2);
     fixedObstacleCrossing(anchor);
     //开启越障动作
     return 0;

   }
   

    //TODO 先根据电池电量状态，判断是否要充电，能否到达充电点或者是就地锁住待救援
    //TODO 先根据地图导航数据来判断位置
    //TODO 根据地图导航的结果来判断是否调用图像测距方法
    //TODO 根据图像测距方法来确定是否执行越障指令

}
