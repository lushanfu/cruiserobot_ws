#include<stdio.h>
#include<iostream>
#include"ros/ros.h"
#include <opencv-3.3.1-dev/opencv2/core.hpp>
#include <opencv-3.3.1-dev/opencv/highgui.h>
#include <opencv-3.3.1-dev/opencv2/opencv.hpp>
#include<image_transport/image_transport.h>

using namespace cv;
using namespace std;
int main(int argc,char** argv)
{
    ros::init(argc,argv,"img_publisher");
    ros::NodeHandle nh;
    ros::Publisher pub=nh.advertise<int>("img_transfer",10);
    ros::Rate rate(100);
    VideoCapture cap("rtsp://admin:abcd1234@192.168.3.68/mpeg4/ch1/main/av_stream");
    cv::Mat frame;
    if (ros::ok)
    {
        while (cap.isOpened())
        {
           bool flag=cap.read(frame);
           if (!flag)
              continue;
            

        }
        
    }
    
    return 0;
}