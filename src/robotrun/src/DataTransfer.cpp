#include <ros/ros.h>
#include "std_msgs/String.h"
#include "std_msgs/Byte.h"
#include <iostream>
#include <sstream>
#include<stdio.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <cstring>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include<robotrun/fixed_arm.h>
#include<robotrun/moving_arm.h>
#include<memory>
using namespace std;

class CRecieve
{
public:
    CRecieve(){};
    virtual ~CRecieve(){};

public:
    int length;
    char * content;
};


CRecieve netTransfer(const char* Ip,int Port,char arrMsg[])
{
    
    // socket
    CRecieve x;
    int client = socket(AF_INET, SOCK_STREAM, 0);
    if (client == -1) {
        // std::cout << "Error: socket" << std::endl;
        x.length=-1;
        return x;
    }
    
    // connect
    struct sockaddr_in serverAddr;
   
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(Port);
    serverAddr.sin_addr.s_addr = inet_addr(Ip);
    
    if (connect(client, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        // std::cout << "Error: connect" << std::endl;
        x.length=-1;
        return x;
    }
    std::cout << "...connect" << std::endl;
    char* data=arrMsg;
    char buf[128];
   
    int l=sizeof(data);
        
    int re=send(client, data, l, 0);
    if(re<0)
    {
        ROS_INFO("send msg erro!\n");
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
    ROS_INFO("numBag is %u",num);
    return x;
}

 
int main(int argc,char **argv)
{
    // string  s="0101";
    

    // int x=stoi(s,nullptr,2);
    // ROS_INFO("x is %d",x);
    
    char sttr[]={7,0,0,0,0,0,0,0};
    const char *Ip="192.168.1.165";
    ros::init(argc,argv,"talker");  
    ros::NodeHandle nh;
 
    ros::Publisher pub = nh.advertise<std_msgs::String>("baseData",1000);
 
    ros::Rate rate(1);
    int count = 0;
 
    while(ros::ok())  
    {
        
        CRecieve ret=netTransfer(Ip,100,sttr);
        
        std_msgs::String msg;
        std::stringstream ss;
        ss<< "update_baseData is:"<<ret.length<<" time:"<<count;
        msg.data =ss.str();
 
        ROS_INFO("%s",msg.data.c_str());
        pub.publish(msg);
        ros::spinOnce();
        rate.sleep();
        ++count;
    }
    return 0;
}
