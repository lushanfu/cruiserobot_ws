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
   unsigned int bagNum;
   unsigned  int distance;
};
// struct RobotData
// {
//     robotrun::fixed_arm fixedArmData;
//     robotrun::moving_arm movingArmData;
// };
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
};
