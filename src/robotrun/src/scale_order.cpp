/*
 * @Author: Shanfu Lu 
 * @Date: 2020-08-31 15:29:22 
 * @Last Modified by: Shanfu Lu
 * @Last Modified time: 2020-08-31 21:36:18
 */
#include"robotrun/common.h"
#include <ros/ros.h>
#include<iostream>
#include<pthread.h>
using namespace std;

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
    void * status;
    int rc;
    int ret1=pthread_create(&tids[0],NULL,&movingArmX2Pos,&(anchorPos.A1));
    int ret2=pthread_create(&tids[1],NULL,&movingArmY2Pos,&(anchorPos.B1));
    int ret3=pthread_create(&tids[2],NULL,&movingArmZ2Pos,&(anchorPos.C1));
    int ret4=pthread_create(&tids[3],NULL,&fixedArmX2Pos,&(anchorPos.D1));
    int ret5=pthread_create(&tids[4],NULL,&fixedArmY2Pos,&(anchorPos.E1));
    int ret6=pthread_create(&tids[5],NULL,&controlCabinet2Pos,&(anchorPos.G1));
    //pthread_join(tids[0],NULL);
    //pthread_exit(NULL);
    for(int i=0;i<6;++i)
    {
      rc=pthread_join(tids[i],&status);
    }
}
void step_01(UnitType unitType, AnchorPos & anchorPos)
{
    pthread_t tids[6];
    int rc;
    void* status;
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
}
void step_02(UnitType unitType, AnchorPos & anchorPos)
{
    pthread_t tids[6];
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
    pthread_exit(NULL);
}
void step_03(UnitType unitType,AnchorPos & anchorPos)
{
    CUtils utils;
    pthread_t tids[6];
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
    pthread_exit(NULL);
   
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
int main(int argc,char ** argv)
{
    AnchorPos anchor;
    int unit=*argv[1]-'0';
    int step_num=stoi(argv[2]);
    CUtils utils;
    // utils.movingArmX2Pos(anchor.A1);
    // return 0;
    UnitType unitType;
    if(unit==1)
     unitType=UnitType::movingArm;
    else
      unitType=UnitType::fixedArm;
    switch (step_num)
    {
    case 0:
        step_00(unitType,anchor);
        break;
    case 1:
        step_01(unitType,anchor);
        break;
    case 2:
        step_02(unitType,anchor);
        break;
    case 3:
        step_03(unitType,anchor);
        break;
    case 4:
        step_04(unitType,anchor);
        break;
    case 5:
        step_05(unitType,anchor);
        break;
    case 6:
        step_06(unitType,anchor);
        break;
    case 7:
        step_07(unitType,anchor);
        break;
    case 8:
        step_08(unitType,anchor);
        break;    
    default:
        break;
    }
    return 0;
}