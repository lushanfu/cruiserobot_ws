#include"robotrun/common.h"
#include <ros/ros.h>
#include"boost/range.hpp"
#include<iostream>
using namespace std;
BaseData::BaseData()
{}
BaseData::~BaseData()
{}

void BaseData::setHorizontalIOLineState(IOLineState ioState)
{
    horizontalIOLineState=ioState;
}

void BaseData::setHorizontalIOLineState2(IOLineState ioState)
{
    horizontalIOLineState2=ioState;
}

void BaseData::setVerticalIOLineState(IOLineState ioState)
{
    verticalIOLineState=ioState;
}

void BaseData::setHorizontalArmOnLineLock(SensorState state)
{
    horizontalArmOnLineLock=state;
}
void BaseData::setHorizontalArmOnLineUnLock(SensorState state)
{
    horizontalArmOnLineUnLock=state;
}

IOLineState BaseData::getHorizontalIOLineState( )
{
    return horizontalIOLineState;
}

IOLineState BaseData::getHorizontalIOLineState2( )
{
    return horizontalIOLineState2;
}

IOLineState BaseData::getVerticalIOLineState( )
{
    return verticalIOLineState;
}

SensorState BaseData::getHorizontalArmOnLineLock( )
{
    return horizontalArmOnLineLock;
}
SensorState BaseData::getHorizontalArmOnLineUnLock( )
{
    return horizontalArmOnLineUnLock;
}

CRecieve::CRecieve(){}
CRecieve::~CRecieve(){}



CNetTransfer::CNetTransfer(){}
CNetTransfer::~CNetTransfer(){}

CRecieve CNetTransfer::netTransfer(const char* Ip,int Port,char arrMsg[],int n)
  {
    
    // socket
    CRecieve x;
    int client = socket(AF_INET, SOCK_STREAM, 0);
    
    if (client == -1) 
    {
        std::cout << "Error: socket" << std::endl;
        x.length=-1;
        return x;
    }
    
    // connect
    struct sockaddr_in serverAddr;
   
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(Port);
    serverAddr.sin_addr.s_addr = inet_addr(Ip);
    
    if (connect(client, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) 
    {
        std::cout << "Error: connect" << std::endl;
        x.length=-1;
        return x;
     }
    // std::cout << "...connect" << std::endl;
    char* data=arrMsg;
    char buf[128];
   
    int l=sizeof(data);
    int ll=strlen(data);
        
    int re=send(client, data, n, 0);

    if(re<0)
    {
        x.length=-1;
        return x;
        
    }
    if (strcmp(data, "exit") == 0) 
    {
        std::cout << "...disconnect" << std::endl;
        x.length=-1;
        return x;
    }
    memset(buf, 0, sizeof(buf));
    int len = recv(client, buf, sizeof(buf), 0);
    buf[len] = '\0';
    
    x.length=len;
    x.content=buf;
    unsigned char num=x.content[len-1];
    x.realNum=num;
    close(client);
    return x;
   }



CParseData::CParseData()
{
}
CParseData::~CParseData(){}


int CParseData::parseByte(int binaryData,string bitOpStr,int moveBit)
{
    int num=stoi(bitOpStr,nullptr,2);
    int ret=binaryData & num;
    ret=ret >> moveBit;
    return ret;
}
    /******************************data obtain********************************/
int CParseData::horizontalArmBagNum(UnitType t)
{
        char * Msg;
        CRecieve rec;
        if(t==UnitType::fixedArm)
        {
           char sttr[]={0,0,0,0,0,0,0,0};
           Msg=sttr;
        }
        else if(t==UnitType::movingArm)
        {
            char sttr[]={0x20,0,0,0,0,0,0,0};
            Msg=sttr;
        }
        rec=netT.netTransfer(Ip,port,Msg);
        if(rec.length<1)
          return -1;
        return rec.realNum;
}

int CParseData::movingArmBagNum(UnitType t)
    {
        CRecieve rec;
        char * Msg=nullptr;
        if(t==UnitType::fixedArm)
        {
           char sttr[]={1,0,0,0,0,0,0,0};
           Msg=sttr;
        }
        else if(t==UnitType::movingArm)
        {
            char sttr[]={0x21,0,0,0,0,0,0,0};
            Msg=sttr;
        }
       rec=netT.netTransfer(Ip,port,Msg);
       if(rec.length<1)
          return -1;
       return rec.realNum;
    }

BaseData CParseData::horizontalIOLineState(UnitType t)
    {
        BaseData b;
        CRecieve rec;
        char * Msg=nullptr;
        if(t==UnitType::fixedArm)
        {
            char sttr[]={2,0,0,0,0,0,0,0};
            Msg=sttr;
        }
        else if(t==UnitType::movingArm)
        {
            char sttr[]={0x22,0,0,0,0,0,0,0};
            Msg=sttr;
        }
        rec=netT.netTransfer(Ip,port,Msg);
        if(rec.length<1)
        {
            return b;
        }
        int ret1=parseByte(rec.realNum,"11000000",6);
        int ret2=parseByte(rec.realNum,"110000",4);
        int ret3=parseByte(rec.realNum,"1000",3);
        int ret4=parseByte(rec.realNum,"100",2);
        int ret5=parseByte(rec.realNum,"11",0);
       

        switch (ret1)
        {
            case 0:
                b.setHorizontalIOLineState(IOLineState::unKnown);
                break;
            case 1:
                b.setHorizontalIOLineState(IOLineState::enter);
                break;
            case 2:
                b.setHorizontalIOLineState(IOLineState::outsize);
                break;
            case 3:
                b.setHorizontalIOLineState(IOLineState::edge);
                break;

            default:
               break;
        }

        switch (ret2)
        {
            case 0:
                b.setVerticalIOLineState(IOLineState::unKnown);
                break;
            case 1:
                b.setVerticalIOLineState(IOLineState::enter);
                break;
            case 2:
                b.setVerticalIOLineState(IOLineState::outsize);
                break;
            case 3:
                b.setVerticalIOLineState(IOLineState::edge);
                break;
            default:
               break;
        }

        switch (ret3)
        {
            case 0:
                b.setHorizontalArmOnLineLock(SensorState::invalid);
                break;
            case 1:
                b.setHorizontalArmOnLineLock(SensorState::invalid);
                break;
            default:
               break;
        }
        switch (ret4)
        {
            case 0:
                b.setHorizontalArmOnLineUnLock(SensorState::invalid);
                break;
            case 1:
                b.setHorizontalArmOnLineUnLock(SensorState::invalid);
                break;
            default:
               break;
        }
        switch (ret5)
        {
             case 0:
                b.setHorizontalIOLineState2(IOLineState::unKnown);
                break;
            case 1:
                b.setHorizontalIOLineState2(IOLineState::enter);
                break;
            case 2:
                b.setHorizontalIOLineState2(IOLineState::outsize);
                break;
            case 3:
                b.setHorizontalIOLineState2(IOLineState::edge);
                break;
            default:
               break;
        }
        return b;
    }

int CParseData::horizontalRotAng(UnitType t)
    {
        CRecieve rec;
        char * Msg=nullptr;
        if(t==UnitType::fixedArm)
        {
            char sttr[]={3,0,0,0,0,0,0,0};
            Msg=sttr;

        }
        else if(t==UnitType::movingArm)
        {
            char sttr[]={0x23,0,0,0,0,0,0,0};
            Msg=sttr;
        }
        rec=netT.netTransfer(Ip,port,Msg);
        return rec.realNum;
    }

SpeedType CParseData::travelSpeed(UnitType t)
    {
        CRecieve rec;
        SpeedType speed;
        char * Msg=nullptr;
        if(t==UnitType::fixedArm)
        {
           char sttr[]={4,0,0,0,0,0,0,0};
           Msg=sttr;
        }
        else if(t==UnitType::movingArm)
        {
            char sttr[]={0x24,0,0,0,0,0,0,0};
            Msg=sttr;
        }
       rec=netT.netTransfer(Ip,port,Msg);
       if(rec.length<1)
       {
           speed.distance=-1;
           return speed;
       }
       unsigned char bagNum=rec.content[rec.length-1];
       unsigned char dis=rec.content[rec.length-2];
       speed.bagNum=(int)bagNum;
       speed.distance=(int)dis;
       return speed;
    }
int CParseData::horizontalTorsion(UnitType t)
    {
        CRecieve rec;
        char * Msg=nullptr;
         if(t==UnitType::fixedArm)
        {
           char sttr[]={5,0,0,0,0,0,0,0};
           Msg=sttr;
        }
        else if(t==UnitType::movingArm)
        {
            char sttr[]={0x25,0,0,0,0,0,0,0};
            Msg=sttr;
        }
       rec=netT.netTransfer(Ip,port,Msg);
       if(rec.length<1)
       {
          return -1;
       }
       return rec.realNum;
    }

int CParseData::verticalRotAng(UnitType t)
    {
        CRecieve rec;
        char * Msg=nullptr;
        if(t==UnitType::fixedArm)
        {
           char sttr[]={6,0,0,0,0,0,0,0};
           Msg=sttr;
        }
        else if(t==UnitType::movingArm)
        {
            char sttr[]={0x26,0,0,0,0,0,0,0};
            Msg=sttr;
        }
        rec=netT.netTransfer(Ip,port,Msg);
        if(rec.length<1)
        {
          return -1;
        }
        return rec.realNum;

    }

int CParseData::opArmApproachDis(UnitType t)
    {
        CRecieve rec;
        char * Msg=nullptr;
        if(t==UnitType::fixedArm)
        {
           char sttr[]={7,0,0,0,0,0,0,0};
           Msg=sttr;
        }
        else if(t==UnitType::movingArm)
        {
            char sttr[]={0x31,0,0,0,0,0,0,0};
            Msg=sttr;
        }
        rec=netT.netTransfer(Ip,port,Msg);
        if(rec.length<1)
        {
          return -1;
        }
        return rec.realNum;
    }


    /***********************************control part*********************************************/
void CParseData::motorTravelControl(UnitType t,MotorState motorState,int num)
    {
        CRecieve rec;
        char * Msg=nullptr;
        int motor;
        switch (motorState)
        {
            case MotorState::neutralPos:
                 motor=0;
                break;
            case MotorState::brake:
                 motor=1;
                break;
            case MotorState::walkForward:
                 motor=2;
                break;
            case MotorState::walkBackward:
                 motor=3;
                break;
 
        }
      
        
       if(t==UnitType::fixedArm)
        {
           char sttr[]={0x08,0,0,0,0,0,2,0,motor,num};
           Msg=sttr;
           
        }
        else if(t==UnitType::movingArm)
        {
            char sttr[]={0x28,0,0,0,0,0,2,0,motor,num};
            Msg=sttr;
           
        }
      
       rec=netT.netTransfer(Ip,port,Msg,10);
       if(rec.length<1)
       {
          return ;
       }
    }

void CParseData::horizontalArmRotMotor(UnitType t,MotorState motorState,int brakeThreashold,int horizontalArmDis,int horizontalArmTorsion)
    {
        int motor;
        char * Msg=nullptr;

        switch (motorState)
        {
            case MotorState::neutralPos:
                motor=0;
                break;
            case MotorState::brake:
                motor=1;
                break;
            case MotorState::walkForward:
                motor=2;
                break;
            case MotorState::walkBackward:
                motor=3;
                break;
            default:
                break;
        }

        if(t==UnitType::fixedArm)
        {
           char sttr[]={0x09,0,0,0,0,0,4,0,motor,brakeThreashold,horizontalArmDis,horizontalArmTorsion};
           Msg=sttr;
        }
        else if(t==UnitType::movingArm)
        {
            char sttr[]={0x29,0,0,0,0,0,4,0,motor,brakeThreashold,horizontalArmDis,horizontalArmTorsion};
            Msg=sttr;
        }
        netT.netTransfer(Ip,port,Msg,12);
        
    }



void CParseData::verticalArmRotMotor(UnitType t,MotorState motorState,int brakeThreashold,int verticalArmDis)
    {
        int motor;
        char * Msg=nullptr;
        switch (motorState)
        {
            case MotorState::neutralPos:
                motor=0;
                break;
            case MotorState::brake:
                motor=1;
                break;
            case MotorState::walkForward:
                motor=2;
                break;
            case MotorState::walkBackward:
                motor=3;
                break;
            default:
                return;
        }

        if(t==UnitType::fixedArm)
        {
           char sttr[]={0x0a,0,0,0,0,0,3,0,motor,brakeThreashold,verticalArmDis};
           Msg=sttr;
        }
        else if(t==UnitType::movingArm)
        {
            char sttr[]={0x2a,0,0,0,0,0,3,0,motor,brakeThreashold,verticalArmDis};
            Msg=sttr;
        }
        netT.netTransfer(Ip,port,Msg,11);
    }


void CParseData::onLineLockMotorControl(UnitType t,MotorState motorState,int brakeThreashold,int sensorValue)
    {
        int motor;
        char * Msg=nullptr;
        switch (motorState)
        {
            case MotorState::neutralPos:
                motor=0;
                break;
            case MotorState::brake:
                motor=1;
                break;
            case MotorState::walkForward:
                motor=2;
                break;
            case MotorState::walkBackward:
                motor=3;
                break;
            default:
                return;
        }

        if(t==UnitType::fixedArm)
        {
           char sttr[]={0x0b,0,0,0,0,0,3,0,motor,brakeThreashold,sensorValue};
           Msg=sttr;
        }
        else if(t==UnitType::movingArm)
        {
            char sttr[]={0x2b,0,0,0,0,0,3,0,motor,brakeThreashold,sensorValue};
            Msg=sttr;
        }
        netT.netTransfer(Ip,port,Msg,11);
    }

void CParseData::onLineClutchControl(UnitType t,MotorState motorState)
    {
        int motor;
        char * Msg=nullptr;
        switch (motorState)
        {
            case MotorState::neutralPos:
                motor=0;
                break;
            case MotorState::brake:
                motor=1;
                break;
            case MotorState::walkForward:
                motor=2;
                break;
            case MotorState::walkBackward:
                motor=3;
                break;
            default:
                return;
        }

        if(t==UnitType::fixedArm)
        {
           char sttr[]={0x0c,0,0,0,0,0,1,0,motor};
           Msg=sttr;
        }
        else if(t==UnitType::movingArm)
        {
            char sttr[]={0x2c,0,0,0,0,0,1,0,motor};
            Msg=sttr;
        }
        netT.netTransfer(Ip,port,Msg,9);
    }




CFixedArmParseData::CFixedArmParseData(){}
CFixedArmParseData:: ~CFixedArmParseData(){}


int CFixedArmParseData::horizontalArmBagNum()
    {
       
        return CParseData::horizontalArmBagNum(UnitType::fixedArm);
    }
int CFixedArmParseData::movingArmBagNum()
    {
        return CParseData::movingArmBagNum(UnitType::fixedArm);
    }
BaseData CFixedArmParseData::horizontalIOLineState()
    {
        return CParseData::horizontalIOLineState(UnitType::fixedArm);
    }
int CFixedArmParseData::horizontalRotAng()
    {
        return CParseData::horizontalRotAng(UnitType::fixedArm);
    }
SpeedType CFixedArmParseData::travelSpeed()
    {
        return CParseData::travelSpeed(UnitType::fixedArm);
    }

int CFixedArmParseData::horizontalTorsion()
    {
        return CParseData::horizontalTorsion(UnitType::fixedArm);
    }
int CFixedArmParseData::verticalRotAng()
    {
        return CParseData::verticalRotAng(UnitType::fixedArm);
    }
int CFixedArmParseData::opArmApproachDis()
    {
        return CParseData::opArmApproachDis(UnitType::fixedArm);
    }
int CFixedArmParseData::controlCabinetBagNum()
    {
        CRecieve rec;
        char sttr[]={0x2d,0,0,0,0,0,0,0}; 
        rec=netT.netTransfer(Ip,port,sttr);
        if(rec.length<1)
          return -1;
        return rec.realNum;
    }
int CFixedArmParseData::controlCabinetStayWireSensorDis()
    {
        CRecieve rec;
        char sttr[]={0x30,0,0,0,0,0,0,0}; 
        rec=netT.netTransfer(Ip,port,sttr);
        if(rec.length<1)
          return -1;
        return rec.realNum;
    }
int CFixedArmParseData::gps()
    {
         CRecieve rec;
        char sttr[]={(char)0xf0,0,0,0,0,0,0,0}; 
        rec=netT.netTransfer(Ip,port,sttr);
        if(rec.length<1)
          return -1;
        return rec.realNum;
    }
int CFixedArmParseData::batteryCapcity()
    {
        CRecieve rec;
        char sttr[]={(char)0xf1,0,0,0,0,0,0,0}; 
        rec=netT.netTransfer(Ip,port,sttr);
        if(rec.length<1)
          return -1;
        return rec.realNum;
    }

    /************************control part****************************/
void CFixedArmParseData::motorTravelControl(MotorState motorState,int threshold)
    {
        CParseData::motorTravelControl(UnitType::fixedArm,motorState,threshold);
    }

void CFixedArmParseData::horizontalArmRotMotor(MotorState motorState,int threshold,int horizontalArmDis,int horizontalArmTorsion)
    {
        CParseData::horizontalArmRotMotor(UnitType::fixedArm,motorState,threshold,horizontalArmDis,horizontalArmTorsion);
    }

void CFixedArmParseData::verticalArmRotMotor(MotorState motorState,int brakeThreashold,int verticalArmDis)
    {
        CParseData::verticalArmRotMotor(UnitType::fixedArm,motorState,brakeThreashold,verticalArmDis);
    }
void CFixedArmParseData::onLineLockMotorControl(MotorState motorState,int brakeThreashold,int sensorValue)
    {
        CParseData::onLineLockMotorControl(UnitType::fixedArm,motorState,brakeThreashold,sensorValue);
    }
void CFixedArmParseData::onLineClutchControl(MotorState motorState)
    {
        CParseData::onLineClutchControl(UnitType::fixedArm,motorState);
    }
void CFixedArmParseData::opArmMovingControl(MotorState motorState,int threshold1,int threshold2)
    {
        int motor;
        switch (motorState)
        {
            case 0:
                motor=0;
                break;
            case 1:
                motor=1;
                break;
            case 2:
                motor=2;
                break;
            case 3:
                motor=3;
                break;
            default:
               return;
        }
        char sttr[]={0x0d,0,0,0,0,0,3,0,motor,threshold1,threshold2};
        netT.netTransfer(Ip,port,sttr,11);
    }
void CFixedArmParseData::opArmMovingControl2(MotorState motorState,int threshold1,int threshold2)
    {
        int motor;
        switch (motorState)
        {
            case 0:
                motor=0;
                break;
            case 1:
                motor=1;
                break;
            case 2:
                motor=2;
                break;
            case 3:
                motor=3;
                break;
            default:
               return;
        }
        char sttr[]={0x0d,0,0,0,0,0,3,0,motor,threshold1,threshold2};
        netT.netTransfer(Ip,port,sttr,11);
        if (motorState==MotorState::walkForward)
        {
            CMovingArmParseData movingArm;
            while (movingArm.opArmApproachDis()>=threshold1)
            {
                char sttr2[]={0x0d,0,0,0,0,0,3,0,1,0,0};
                netT.netTransfer(Ip,port,sttr2,11);
                break;
            }
            
        }
        else if(motorState==MotorState::walkBackward)
        {
            while (opArmApproachDis()>=threshold1)
            {
                char sttr3[]={0x0d,0,0,0,0,0,3,0,1,0,0};
                netT.netTransfer(Ip,port,sttr3,11);
                break;
            }
            
        }
        
        
    }

void CFixedArmParseData::movingArmMovingControl(MotorState motorState,int threshold1,int threshold2)
    {
        int motor;
        switch (motorState)
        {
            case 0:
                motor=0;
                break;
            case 1:
                motor=1;
                break;
            case 2:
                motor=2;
                break;
            case 3:
                motor=3;
                break;
            default:
               return;
        }
        char sttr[]={0x0e,0,0,0,0,0,3,0,motor,threshold1,threshold2};
        netT.netTransfer(Ip,port,sttr,11);
    }

void CFixedArmParseData::cabinetMotionControl(MotorState motorState,int threshold)
{
    int motor;
        switch (motorState)
        {
            case 0:
                motor=0;
                break;
            case 1:
                motor=1;
                break;
            case 2:
                motor=2;
                break;
            case 3:
                motor=3;
                break;
            default:
               return;
        }
        char sttr[]={0x0f,0,0,0,0,0,2,0,motor,threshold};
        netT.netTransfer(Ip,port,sttr,10);
}

CMovingArmParseData::CMovingArmParseData(){}
CMovingArmParseData::~CMovingArmParseData(){}


int CMovingArmParseData::horizontalArmBagNum()
    {
        return CParseData::horizontalArmBagNum(UnitType::movingArm);
    }
int CMovingArmParseData::movingArmBagNum()
    {
        return CParseData::movingArmBagNum(UnitType::movingArm);
    }
BaseData CMovingArmParseData::horizontalIOLineState()
    {
        return CParseData::horizontalIOLineState(UnitType::movingArm);
    }
int CMovingArmParseData::horizontalRotAng()
    {
        return CParseData::horizontalRotAng(UnitType::movingArm);
    }
SpeedType CMovingArmParseData::travelSpeed()
    {
        return CParseData::travelSpeed(UnitType::movingArm);
    }

int CMovingArmParseData::horizontalTorsion()
    {
        return CParseData::horizontalTorsion(UnitType::movingArm);
    }
int CMovingArmParseData::verticalRotAng()
    {
        return CParseData::verticalRotAng(UnitType::movingArm);
    }
int CMovingArmParseData::opArmApproachDis()
    {
        return CParseData::opArmApproachDis(UnitType::movingArm);
    }
   
int CMovingArmParseData::stayWireSensorDis()
{
    CRecieve rec;
    char sttr[]={0x27,0,0,0,0,0,0,0}; 
    rec=netT.netTransfer(Ip,port,sttr);
    if(rec.length<1)
        return -1;
    return rec.realNum;
}
   
    /************************control part****************************/
void CMovingArmParseData::motorTravelControl(MotorState motorState,int threshold)
    {
        CParseData::motorTravelControl(UnitType::movingArm,motorState,threshold);
    }

void CMovingArmParseData::horizontalArmRotMotor(MotorState motorState,int threshold,int horizontalArmDis,int horizontalArmTorsion)
{
    CParseData::horizontalArmRotMotor(UnitType::movingArm,motorState,threshold,horizontalArmDis,horizontalArmTorsion);
}
void CMovingArmParseData::verticalArmRotMotor(MotorState motorState,int brakeThreashold,int verticalArmDis)
{
    CParseData::verticalArmRotMotor(UnitType::movingArm,motorState,brakeThreashold,verticalArmDis);
}
void CMovingArmParseData::onLineLockMotorControl(MotorState motorState,int brakeThreashold,int sensorValue)
{
    CParseData::onLineLockMotorControl(UnitType::movingArm,motorState,brakeThreashold,sensorValue);
}
void CMovingArmParseData::onLineClutchControl(MotorState motorState)
{
    CParseData::onLineClutchControl(UnitType::movingArm,motorState);
}


CUtils::CUtils(){}
CUtils::~CUtils(){}
robotrun::robot_data CUtils::obtainMsg()
{
    robotrun::fixed_arm fixedData;
    robotrun::moving_arm movingData;
    robotrun::robot_data robotData;
    CFixedArmParseData fixedParse;
    CMovingArmParseData movingParse;
    
    fixedData.hArmBagNum=fixedParse.horizontalArmBagNum();
    cout<<"fixedData.hArmBagNum ->"<<fixedData.hArmBagNum<<endl;

    fixedData.movingArmBagNum=fixedParse.movingArmBagNum();
    cout<<"fixedData.movingArmBagNum ->"<<fixedData.movingArmBagNum<<endl;

    BaseData bd=fixedParse.horizontalIOLineState();
    fixedData.hIOLine_1=bd.getHorizontalIOLineState();
    cout<<"fixedData.hIOLine_1 ->"<<fixedData.hIOLine_1<<endl;

    fixedData.hIOLine_2=bd.getHorizontalIOLineState2();
    cout<<"ffixedData.hIOLine_2 ->"<<fixedData.hIOLine_2<<endl;

    fixedData.vIOLine=bd.getVerticalIOLineState();
    cout<<"fixedData.vIOLine ->"<<fixedData.vIOLine<<endl;

    fixedData.hArmOnLineLock=bd.getHorizontalArmOnLineLock();
    cout<<"fixedData.hArmOnLineLock ->"<<fixedData.hArmOnLineLock<<endl;

    fixedData.hArmOnLineUnlock=bd.getHorizontalArmOnLineUnLock();
    cout<<" fixedData.hArmOnLineUnlock->"<< fixedData.hArmOnLineUnlock<<endl;

    fixedData.hRotateAngle=fixedParse.horizontalRotAng();
    cout<<" fixedData.hRotateAngle->"<< fixedData.hRotateAngle<<endl;

    fixedData.speed=fixedParse.travelSpeed().distance;
    cout<<" fixedData.speed->"<< fixedData.speed<<endl;

    fixedData.hTorsion=fixedParse.horizontalTorsion();
    cout<<" fixedData.hTorsion->"<< fixedData.hTorsion<<endl;

    fixedData.vRorateAngle=fixedParse.verticalRotAng();
    cout<<" fixedData.vRorateAngle->"<< fixedData.vRorateAngle<<endl;

    fixedData.opArmDistance=fixedParse.opArmApproachDis();
    cout<<" fixedData.opArmDistance->"<< fixedData.opArmDistance<<endl;

    //fixedData.controlCabinetBagNum=fixedParse.controlCabinetBagNum();
    fixedData.controlCabinetStayWireSensorDis=fixedParse.controlCabinetStayWireSensorDis();
    cout<<" fixedData.controlCabinetStayWireSensorDis->"<< fixedData.controlCabinetStayWireSensorDis<<endl;

    // fixedData.gps=fixedParse.gps();
    // fixedData.batteryCapcity=fixedParse.batteryCapcity();
    
    


    movingData.hArmBagNum=movingParse.horizontalArmBagNum();
    cout<<" movingData.hArmBagNum->"<< movingData.hArmBagNum<<endl;


    movingData.movingArmBagNum=movingParse.movingArmBagNum();
    cout<<" movingData.movingArmBagNum->"<< movingData.movingArmBagNum<<endl;
    
    BaseData bd2=movingParse.horizontalIOLineState();
    movingData.hIOLine_1=bd2.getHorizontalIOLineState();
    cout<<" movingData.hIOLine_1->"<<movingData.hIOLine_1<<endl;
    
    movingData.hIOLine_2=bd2.getHorizontalIOLineState2();
    cout<<" movingData.hIOLine_2->"<<movingData.hIOLine_2<<endl;
    
    movingData.vIOLine=bd2.getVerticalIOLineState();
    cout<<" movingData.vIOLine->"<<movingData.vIOLine<<endl;
    
    movingData.hArmOnLineLock=bd2.getHorizontalArmOnLineLock();
    cout<<"movingData.hArmOnLineLock->"<<movingData.hArmOnLineLock<<endl;
    
    movingData.hArmOnLineUnlock=bd2.getHorizontalArmOnLineUnLock();
    cout<<" movingData.hArmOnLineUnlock->"<<movingData.hArmOnLineUnlock<<endl;

    movingData.hRotateAngle=movingParse.horizontalRotAng();
    cout<<" movingData.hRotateAngle->"<<movingData.hRotateAngle<<endl;
    
    movingData.speed=movingParse.travelSpeed().distance;
    cout<<" movingData.speed->"<<movingData.speed<<endl;
    
    movingData.hTorsion=movingParse.horizontalTorsion();
    cout<<"movingData.hTorsion->"<<movingData.hTorsion<<endl;
    
    movingData.vRorateAngle=movingParse.verticalRotAng();
    cout<<"movingData.vRorateAngle->"<<movingData.vRorateAngle<<endl;
    
    movingData.stayWiresDis=movingParse.stayWireSensorDis();
    cout<<"movingData.stayWiresDis->"<<movingData.stayWiresDis<<endl;
    
    movingData.opArmDistance=movingParse.opArmApproachDis();
    cout<<"movingData.opArmDistance->"<<movingData.opArmDistance<<endl;

    robotData.fixedArmData=fixedData;
    robotData.movingArmData=movingData;
    return robotData;
}

void CUtils::armX2PosMotion(robotArmProperty o)
{
    CFixedArmParseData fixedParse;
    CMovingArmParseData movingParse;
    time_t first,second; 
    first=time(NULL);
    while (true)
    {
        second=time(NULL);
        int secdiff=(int)difftime(second,first);
       
        if(o.armState==UnitType::fixedArm)
        {
            auto horizonData=fixedParse.horizontalRotAng();
            if((o.motorState==MotorState::walkForward && horizonData>= o.threshold)||(o.motorState==MotorState::walkBackward && horizonData<=o.threshold))
            {
                fixedParse.horizontalArmRotMotor(MotorState::brake,0,0,0);
                return;
            }
            if(secdiff>0)
            {
                 first=time(NULL);
                 
                 fixedParse.horizontalArmRotMotor(o.motorState,100,o.threshold,0);
            }
            
        }
        else
        {
            auto horizonData=movingParse.horizontalRotAng();
            if((o.motorState==MotorState::walkForward && horizonData>=o.threshold) || (o.motorState==MotorState::walkBackward && horizonData<=o.threshold))
            {
                movingParse.horizontalArmRotMotor(MotorState::brake,0,0,0);
                return;
            }
            if(secdiff>0)
            {
                first=time(NULL);
                movingParse.horizontalArmRotMotor(o.motorState,100,o.threshold,0);
            }
        }
    }   
}
void CUtils::armY2PosMotion(robotArmProperty o)
{
    CFixedArmParseData  fixedParse;
    CMovingArmParseData movingParse;
    time_t first,second; 
    first=time(NULL);
    while (true)
    {
        second=time(NULL);
        int secdiff=(int)difftime(second,first);
        if(o.armState==UnitType::fixedArm)
        {
            auto verticalData=fixedParse.verticalRotAng();
            if((o.motorState==MotorState::walkForward && verticalData>= o.threshold)||(o.motorState==MotorState::walkBackward && verticalData<=o.threshold))
            {
                fixedParse.verticalArmRotMotor(MotorState::brake,0,0);
                return;
            }
            if(secdiff>0)
            {
                 first=time(NULL);
                 fixedParse.verticalArmRotMotor(o.motorState,100,o.threshold);
            }     
        }
        else
        {
            auto verticalData=movingParse.verticalRotAng();
            if((o.motorState==MotorState::walkForward && verticalData>=o.threshold) || (o.motorState==MotorState::walkBackward && verticalData<=o.threshold))
            {
                movingParse.verticalArmRotMotor(MotorState::brake,0,0);
                return;
            }
            if(secdiff>0)
            {
                first=time(NULL);
                movingParse.verticalArmRotMotor(o.motorState,100,o.threshold);
            }
        }
    } 
}
void CUtils::armZ2PosMotion(robotArmProperty o)
{
    CFixedArmParseData  fixedParse;
    CMovingArmParseData movingParse;
    time_t first,second; 
    first=time(NULL);
    while (true)
    {
        second=time(NULL);
        int secdiff=(int)difftime(second,first);
        auto stayWiresDis=movingParse.stayWireSensorDis();
        if((o.motorState==MotorState::walkBackward && stayWiresDis>=o.threshold) || (o.motorState==MotorState::walkForward && stayWiresDis<=o.threshold))
        {
            fixedParse.movingArmMovingControl(MotorState::brake,0,0);
            return;
        }   
        if(secdiff>0)
        {
            first=time(NULL);
            fixedParse.movingArmMovingControl(o.motorState,100,10);
        }                
    } 
}
void CUtils::opZ2Pos(robotArmProperty o)
{
    CFixedArmParseData  fixedParse;
    CMovingArmParseData movingParse;
    time_t first,second; 
    first=time(NULL);
    int k=1;
    while (true)
    {
        second=time(NULL);
        int secdiff=(int)difftime(second,first);
        auto opArmApproachDis=fixedParse.opArmApproachDis();
        if (opArmApproachDis>=o.threshold)
        {
            return;
        }
        auto stayWiresDis=movingParse.stayWireSensorDis();
        if(1==k)
        {
            k+=1;
            fixedParse.opArmMovingControl(o.motorState,100,0);
            continue;
        }
        if(stayWiresDis>=o.threshold)
        {
            fixedParse.opArmMovingControl(MotorState::brake,0,0);
            return;
        }
        if(secdiff>0)
        {
            first=time(NULL);
            fixedParse.movingArmMovingControl(o.motorState,100,10);
        }                
    } 

}
void CUtils::fixedArmX2Pos(int threshold)
{
    CFixedArmParseData fixedArm;
    robotArmProperty   o;
    auto horizonData=fixedArm.horizontalRotAng();
    o.armState=UnitType::fixedArm;
    o.threshold=threshold;
    o.speed=100;
    o.motorState=MotorState::walkForward;
    if(threshold<horizonData)
    {
       o.motorState=MotorState::walkBackward;
    }
    armX2PosMotion(o);
}
void CUtils::fixedArmY2Pos(int threshold)
{
    CFixedArmParseData fixedArm;
    robotArmProperty   o;
    auto verticalData=fixedArm.verticalRotAng();
    o.armState=UnitType::fixedArm;
    o.threshold=threshold;
    o.speed=100;
    o.motorState=MotorState::walkForward;
    if(threshold<verticalData)
    {
       o.motorState=MotorState::walkBackward;
    }
    armY2PosMotion(o);
}
void CUtils::movingArmX2Pos(int threshold)
{
    
    CMovingArmParseData movingArm;
    robotArmProperty   o;
    auto horizonData=movingArm.horizontalRotAng();
    
    o.armState=UnitType::movingArm;
    o.threshold=threshold;
    o.speed=100;
    o.motorState=MotorState::walkForward;
    if(threshold<horizonData)
    {
       o.motorState=MotorState::walkBackward;
    }
    armX2PosMotion(o);
}
void CUtils::movingArmY2Pos(int threshold)
{
    CMovingArmParseData movingArm;
    robotArmProperty   o;
    auto verticalData=movingArm.verticalRotAng();
    o.armState=UnitType::movingArm;
    o.threshold=threshold;
    o.speed=100;
    o.motorState=MotorState::walkForward;
    if(threshold<verticalData)
    {
       o.motorState=MotorState::walkBackward;
    }
    armY2PosMotion(o);
}
void CUtils::movingArmZ2Pos(int threshold)
{
    CMovingArmParseData movingArm;
    auto stayWiresDis=movingArm.stayWireSensorDis();
    movingArm.motorTravelControl(MotorState::neutralPos,0);
    robotArmProperty   o;
    o.armState=UnitType::movingArm;
    o.threshold=threshold;
    o.speed=0;
    o.motorState=MotorState::walkForward;
    if(threshold<stayWiresDis)
    {
       o.motorState=MotorState::walkForward;
    }
    armZ2PosMotion(o);
}

void CUtils::operationArmZ2Pos(int threshold,int direction)
{
    robotArmProperty o;
    o.motorState=MotorState::walkForward;
    o.speed=0;
    o.threshold=threshold;
    o.armState=UnitType::fixedArm;
    if(direction<0)
    {
        o.motorState=MotorState::walkBackward;
    }
    opZ2Pos(o);
}
void CUtils::cabinet2Pos(robotArmProperty o)
{
    CFixedArmParseData fixedParse;
    time_t first,second; 
    first=time(NULL);
    int k=1;
    while (true)
    {
        second=time(NULL);
        int secdiff=(int)difftime(second,first);
        auto stayWiresDis=fixedParse.controlCabinetStayWireSensorDis();
        if((MotorState::walkForward==o.motorState && stayWiresDis >= o.threshold) || (MotorState::walkBackward==o.motorState && stayWiresDis <= o.threshold))
        {
            fixedParse.cabinetMotionControl(MotorState::brake,0);
            return;
        }
        if(1==k)
        {
            fixedParse.cabinetMotionControl(o.motorState,100);
            k+=1;
            continue;
        }
        if(secdiff>0)
        {
            first=time(NULL);
            fixedParse.cabinetMotionControl(o.motorState,100);
        }       
    }
    

}
void CUtils::controlCabinet2Pos(int threshold)
{
    CFixedArmParseData fixedParse;
    auto stayWire=fixedParse.controlCabinetStayWireSensorDis();
    robotArmProperty o;
    o.motorState=MotorState::walkForward;
    o.threshold=threshold;
    if(threshold<stayWire)
      o.motorState=MotorState::walkBackward;
    cabinet2Pos(o);
}

void CUtils::travelFixedDistance(UnitType t,double distance)
{
     double travelDis=0;
    if(t==UnitType::fixedArm)
    {
       CFixedArmParseData fixedData;
       int currentId=0;
       int preId=-1;
       while (travelDis<distance)
       {
           auto speed=fixedData.travelSpeed();
           currentId=speed.bagNum;
           if(preId!=currentId)
           {
               travelDis+=0.001*speed.distance;
               preId=currentId;   
           }
           

       }
       
    }
    else
    {
       CMovingArmParseData movingData;
       int currentId=0;
       int preId=-1;
       movingData.motorTravelControl(MotorState::walkForward,30);
       time_t first,second; 
       first=time(NULL);
       while (travelDis<distance)
       {
           auto speed=movingData.travelSpeed();
           currentId=speed.bagNum;
           if(preId!=currentId)
           {
               travelDis+=0.001*speed.distance;
               preId=currentId;   
           }
           second=time(NULL);
           int secdiff=(int)difftime(second,first);
           if(secdiff>0)
            {
                first=time(NULL);
                movingData.motorTravelControl(MotorState::walkForward,50);
            }
            cout<<"distance is :"<<travelDis<<endl;
       }
        movingData.motorTravelControl(MotorState::neutralPos,0);
    }

}
