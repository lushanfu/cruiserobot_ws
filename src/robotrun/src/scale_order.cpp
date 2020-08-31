/*
 * @Author: Shanfu Lu 
 * @Date: 2020-08-31 15:29:22 
 * @Last Modified by: Shanfu Lu
 * @Last Modified time: 2020-08-31 20:42:22
 */
#include"robotrun/common.h"
#include <ros/ros.h>
#include<iostream>
using namespace std;
void step_00(UnitType unitType,const AnchorPos & anchorPos)
{
    CUtils utils;
    utils.movingArmX2Pos(anchorPos.A1);
    utils.movingArmY2Pos(anchorPos.B1);
    utils.movingArmZ2Pos(anchorPos.C1);
    utils.fixedArmX2Pos(anchorPos.D1);
    utils.fixedArmY2Pos(anchorPos.E1);
    utils.operationArmZ2Pos(anchorPos.F1);
    utils.controlCabinet2Pos(anchorPos.G1);

}
void step_01(UnitType unitType,const AnchorPos & anchorPos)
{
    CUtils utils;
    if(unitType==UnitType::fixedArm)
    {
        utils.movingArmX2Pos(anchorPos.A3);
        utils.movingArmY2Pos(anchorPos.B1);
        utils.movingArmZ2Pos(anchorPos.C1);
        utils.fixedArmX2Pos(anchorPos.D1);
        utils.fixedArmY2Pos(anchorPos.E1);
        utils.operationArmZ2Pos(anchorPos.F1);
        utils.controlCabinet2Pos(anchorPos.G6);
    }
    else
    {
        utils.movingArmX2Pos(anchorPos.A1);
        utils.movingArmY2Pos(anchorPos.B1);
        utils.movingArmZ2Pos(anchorPos.C1);
        utils.fixedArmX2Pos(anchorPos.D3);
        utils.fixedArmY2Pos(anchorPos.E1);
        utils.operationArmZ2Pos(anchorPos.F1);
        utils.controlCabinet2Pos(anchorPos.G4);
    }
    
}
void step_02(UnitType unitType,const AnchorPos & anchorPos)
{
    CUtils utils;
    if(unitType==UnitType::fixedArm)
    {
        utils.movingArmX2Pos(anchorPos.A3);
        utils.movingArmY2Pos(anchorPos.B2);
        utils.movingArmZ2Pos(anchorPos.C1);
        utils.fixedArmX2Pos(anchorPos.D1);
        utils.fixedArmY2Pos(anchorPos.E1);
        utils.operationArmZ2Pos(anchorPos.F1);
        utils.controlCabinet2Pos(anchorPos.G6);
    }
    else
    {
        utils.movingArmX2Pos(anchorPos.A1);
        utils.movingArmY2Pos(anchorPos.B1);
        utils.movingArmZ2Pos(anchorPos.C1);
        utils.fixedArmX2Pos(anchorPos.D3);
        utils.fixedArmY2Pos(anchorPos.E2);
        utils.operationArmZ2Pos(anchorPos.F1);
        utils.controlCabinet2Pos(anchorPos.G4);
    }
}
void step_03(UnitType unitType,const AnchorPos & anchorPos)
{
    CUtils utils;
    if(unitType==UnitType::fixedArm)
    {
       utils.movingArmX2Pos(anchorPos.A3);
       utils.movingArmY2Pos(anchorPos.B1);
       utils.movingArmZ2Pos(anchorPos.C1);
       utils.fixedArmX2Pos(anchorPos.D1);
       utils.fixedArmY2Pos(anchorPos.E1);
       utils.operationArmZ2Pos(anchorPos.F1);
       utils.controlCabinet2Pos(anchorPos.G6);
    }
    else
    {
        utils.movingArmX2Pos(anchorPos.A1);
        utils.movingArmY2Pos(anchorPos.B1);
        utils.movingArmZ2Pos(anchorPos.C1);
        utils.fixedArmX2Pos(anchorPos.D3);
        utils.fixedArmY2Pos(anchorPos.E1);
        utils.operationArmZ2Pos(anchorPos.F1);
        utils.controlCabinet2Pos(anchorPos.G4);
    }
}
void step_04(UnitType unitType,const AnchorPos & anchorPos)
{
    CUtils utils;
    if(unitType==UnitType::fixedArm)
    {
        utils.movingArmX2Pos(anchorPos.A1);
        utils.movingArmY2Pos(anchorPos.B1);
        utils.movingArmZ2Pos(anchorPos.C1);
        utils.fixedArmX2Pos(anchorPos.D1);
        utils.fixedArmY2Pos(anchorPos.E1);
        utils.operationArmZ2Pos(anchorPos.F1);
        utils.controlCabinet2Pos(anchorPos.G6);
    }
    else
    {
        utils.movingArmX2Pos(anchorPos.A1);
        utils.movingArmY2Pos(anchorPos.B1);
        utils.movingArmZ2Pos(anchorPos.C1);
        utils.fixedArmX2Pos(anchorPos.D1);
        utils.fixedArmY2Pos(anchorPos.E1);
        utils.operationArmZ2Pos(anchorPos.F1);
        utils.controlCabinet2Pos(anchorPos.G4);
    }
}
void step_05(UnitType unitType,const AnchorPos & anchorPos)
{
    CUtils utils;
    if(unitType==UnitType::fixedArm)
    {
        utils.controlCabinet2Pos(anchorPos.G4);
        sleep(5);
        utils.movingArmX2Pos(anchorPos.A1);
        utils.movingArmY2Pos(anchorPos.B1);
        utils.movingArmZ2Pos(anchorPos.C1);
        utils.fixedArmX2Pos(anchorPos.D3);
        utils.fixedArmY2Pos(anchorPos.E1);
        utils.operationArmZ2Pos(anchorPos.F1);
    }
    else
    {
        utils.controlCabinet2Pos(anchorPos.G6);
        sleep(5);
        utils.movingArmX2Pos(anchorPos.A3);
        utils.movingArmY2Pos(anchorPos.B1);
        utils.movingArmZ2Pos(anchorPos.C1);
        utils.fixedArmX2Pos(anchorPos.D1);
        utils.fixedArmY2Pos(anchorPos.E1);
        utils.operationArmZ2Pos(anchorPos.F1);
    }
}
void step_06(UnitType unitType,const AnchorPos & anchorPos)
{
    CUtils utils;
    if(unitType==UnitType::fixedArm)
    {
        utils.movingArmX2Pos(anchorPos.A1);
        utils.movingArmY2Pos(anchorPos.B1);
        utils.movingArmZ2Pos(anchorPos.C1);
        utils.fixedArmX2Pos(anchorPos.D3);
        utils.fixedArmY2Pos(anchorPos.E2);
        utils.operationArmZ2Pos(anchorPos.F1);
        utils.controlCabinet2Pos(anchorPos.G4);
    }
    else
    {
        utils.movingArmX2Pos(anchorPos.A3);
        utils.movingArmY2Pos(anchorPos.B2);
        utils.movingArmZ2Pos(anchorPos.C1);
        utils.fixedArmX2Pos(anchorPos.D1);
        utils.fixedArmY2Pos(anchorPos.E1);
        utils.operationArmZ2Pos(anchorPos.F1);
        utils.controlCabinet2Pos(anchorPos.G6);
    }
}
void step_07(UnitType unitType,const AnchorPos & anchorPos)
{
    CUtils utils;
    if(unitType==UnitType::fixedArm)
    {
        utils.movingArmX2Pos(anchorPos.A1);
        utils.movingArmY2Pos(anchorPos.B1);
        utils.movingArmZ2Pos(anchorPos.C1);
        utils.fixedArmX2Pos(anchorPos.D3);
        utils.fixedArmY2Pos(anchorPos.E1);
        utils.operationArmZ2Pos(anchorPos.F1);
        utils.controlCabinet2Pos(anchorPos.G4);
    }
    else
    {
        utils.movingArmX2Pos(anchorPos.A3);
        utils.movingArmY2Pos(anchorPos.B1);
        utils.movingArmZ2Pos(anchorPos.C1);
        utils.fixedArmX2Pos(anchorPos.D1);
        utils.fixedArmY2Pos(anchorPos.E1);
        utils.operationArmZ2Pos(anchorPos.F1);
        utils.controlCabinet2Pos(anchorPos.G6);
    }
}
void step_08(UnitType unitType,const AnchorPos & anchorPos)
{
    CUtils utils;
    if(unitType==UnitType::fixedArm)
    {
        utils.movingArmX2Pos(anchorPos.A1);
        utils.movingArmY2Pos(anchorPos.B1);
        utils.movingArmZ2Pos(anchorPos.C1);
        utils.fixedArmX2Pos(anchorPos.D1);
        utils.fixedArmY2Pos(anchorPos.E1);
        utils.operationArmZ2Pos(anchorPos.F1);
        utils.controlCabinet2Pos(anchorPos.G1);
    }
    else
    {
        utils.movingArmX2Pos(anchorPos.A1);
        utils.movingArmY2Pos(anchorPos.B1);
        utils.movingArmZ2Pos(anchorPos.C1);
        utils.fixedArmX2Pos(anchorPos.D1);
        utils.fixedArmY2Pos(anchorPos.E1);
        utils.operationArmZ2Pos(anchorPos.F1);
        utils.controlCabinet2Pos(anchorPos.G1);
    }
}
int main(int argc,char ** argv)
{
    AnchorPos anchor;
    int unit=*argv[1]-'0';
    int step_num=stoi(argv[2]);
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