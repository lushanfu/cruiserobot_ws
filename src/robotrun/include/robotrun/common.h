#pragma once
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include"robotrun/fixed_arm.h"
#include"robotrun/moving_arm.h"
#include"robotrun/robot_data.h"
#include <ctime>

using namespace std;
enum UnitType
{
    fixedArm=0,
    movingArm=1,
    cabinet=2
};


enum IOLineState
{
  
    unKnown=0,
    enter=1,
    outsize=2,
    edge=3
};

enum SensorState
{
    
    invalid=0,
    valid=1
};

enum MotorState
{
    neutralPos=0,
    brake=1,
    walkForward=2,
    walkBackward=3
};

struct SpeedType
{
   unsigned  int bagNum=-1;
   unsigned  int distance=-1;
};
struct robotArmProperty // Description prameters of robot_arm motion control
{
    MotorState motorState;
    UnitType   armState;
    int        threshold;
    int        speed;
}; 
struct AnchorPos
{
    int A1=6; int A2=20; int A3=40; int B1=36; int B2=40; int C1=16; int C2=41; int C3=16; int D1=6; int D2=39; int D3=40; int E1=36; int E2=40; int F1=1; int F2=21; int F3=21; int G1=87; int G2=6; int G3=200; int G4=6; int G5=29; int G6=180; int G7=145; int M1=-1; int M2=-1; int N1=-1; int N2=-1;   
};
class BaseData
{
public:
    BaseData();
    virtual ~BaseData();

public:
    IOLineState horizontalIOLineState;
    IOLineState horizontalIOLineState2;
    IOLineState verticalIOLineState;

    SensorState horizontalArmOnLineLock;
    SensorState horizontalArmOnLineUnLock;
    
    int horizontalArmBagNum;
    int movingArmBagNum;
public:
    void setHorizontalIOLineState(IOLineState ioState);
    

    void setHorizontalIOLineState2(IOLineState ioState);
    

    void setVerticalIOLineState(IOLineState ioState);
    

    void setHorizontalArmOnLineLock(SensorState state);
    
    void setHorizontalArmOnLineUnLock(SensorState state);
    


    IOLineState getHorizontalIOLineState();
    

    IOLineState getHorizontalIOLineState2();
    

    IOLineState getVerticalIOLineState();
    

    SensorState getHorizontalArmOnLineLock();
    
    SensorState getHorizontalArmOnLineUnLock();
    

   
};

class CRecieve
{
public:
    CRecieve();
    virtual ~CRecieve();

public:
    int length;
    char * content;
    int realNum;
};

class CNetTransfer
{
public:
    CNetTransfer();
    virtual ~CNetTransfer();
public:
 CRecieve netTransfer(const char* Ip,int Port,char arrMsg[],int n=8);
  
private:
    /* data */
};

class CParseData
{
public:
    CParseData();
    
    virtual ~CParseData();
private:
    // char * Msg=nullptr;
    
    
    CRecieve rec;
public:
    const char * Ip="192.168.3.8";
    CNetTransfer netT;
    int port=100;


public:
    int parseByte(int binaryData,string bitOpStr,int moveBit);
    
    /******************************data obtain********************************/
    int horizontalArmBagNum(UnitType t);
   
    int movingArmBagNum(UnitType t);
    

    BaseData horizontalIOLineState(UnitType t);


    int horizontalRotAng(UnitType t);
   

    SpeedType travelSpeed(UnitType t);
   
    int horizontalTorsion(UnitType t);
    

    int verticalRotAng(UnitType t);
   

    int opArmApproachDis(UnitType t);
   

    /***********************************control part*********************************************/
    void motorTravelControl(UnitType t,MotorState motorState,int num);
   

    void horizontalArmRotMotor(UnitType t,MotorState motorState,int brakeThreashold,int horizontalArmDis,int horizontalArmTorsion);
    


    void verticalArmRotMotor(UnitType t,MotorState motorState,int brakeThreashold,int verticalArmDis);
    


    void onLineLockMotorControl(UnitType t,MotorState motorState,int brakeThreashold,int sensorValue);
   

    void onLineClutchControl(UnitType t,MotorState motorState);
  

};

class CFixedArmParseData:public CParseData
{
public:
    CFixedArmParseData();
    virtual ~CFixedArmParseData();

public:
    int horizontalArmBagNum();
   
    int movingArmBagNum();
    
    BaseData horizontalIOLineState();
    
    int horizontalRotAng();
    
    SpeedType travelSpeed();
    

    int horizontalTorsion();
   
    int verticalRotAng();
    
    int opArmApproachDis();
    
    int controlCabinetBagNum();
   
    int controlCabinetStayWireSensorDis();
    
    int gps();
    
    int batteryCapcity();
    

    /************************control part****************************/
    void motorTravelControl(MotorState motorState,int threshold);
    

    void horizontalArmRotMotor(MotorState motorState,int threshold,int horizontalArmDis,int horizontalArmTorsion);
   

    void verticalArmRotMotor(MotorState motorState,int brakeThreashold,int verticalArmDis);
    
    void onLineLockMotorControl(MotorState motorState,int brakeThreashold,int sensorValue);
   
    void onLineClutchControl(MotorState motorState);
   
    void opArmMovingControl(MotorState motorState,int threshold1,int threshold2);
    void opArmMovingControl2(MotorState motorState,int threshold1,int threshold2);
   

    void movingArmMovingControl(MotorState motorState,int threshold1,int threshold2);
    void cabinetMotionControl(MotorState motorState,int threshold);
    

};

class CMovingArmParseData:public CParseData
{
public:
    CMovingArmParseData();
    virtual ~CMovingArmParseData();

public:
    int horizontalArmBagNum();
    
    int movingArmBagNum();
    
    BaseData horizontalIOLineState();
    
    int horizontalRotAng();
    
    SpeedType travelSpeed();
   

    int horizontalTorsion();
    
    int verticalRotAng();
    
    int opArmApproachDis();
    
   
    int stayWireSensorDis();
    
   
    /************************control part****************************/
    void motorTravelControl(MotorState motorState,int threshold);
   

    void horizontalArmRotMotor(MotorState motorState,int threshold,int horizontalArmDis,int horizontalArmTorsion);
    
    void verticalArmRotMotor(MotorState motorState,int brakeThreashold,int verticalArmDis);
    
    void onLineLockMotorControl(MotorState motorState,int brakeThreashold,int sensorValue);
    
    void onLineClutchControl(MotorState motorState);
   
};

class CUtils
{
   public:
    CUtils();
    ~CUtils();
    public:
    robotrun::robot_data obtainMsg();
    void armX2PosMotion(robotArmProperty o);
    void armY2PosMotion(robotArmProperty o);
    void armZ2PosMotion(robotArmProperty o);

    void fixedArmX2Pos(int threshold);
    void fixedArmY2Pos(int threshold);

    void movingArmX2Pos(int threshold);
    void movingArmY2Pos(int threshold);
    void movingArmZ2Pos(int threshold);
    
    void opZ2Pos(robotArmProperty o);
    void operationArmZ2Pos(int threshold,int direction=-1);
    void cabinet2Pos(robotArmProperty o);
    void controlCabinet2Pos(int threshold);
    void travelFixedDistance(UnitType t,double distance);
};
