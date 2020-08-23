
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp> 
#include"/home/lsf/LSF/cruiserobot_ws/src/cvsion/include/cvsion/rknn_api.h"
#include<iomanip>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<stdint.h>
#include<thread>
using namespace cv;
using namespace std;

float rec(cv::Mat img, rknn_context ctx,rknn_output* out)
{
    rknn_input in[1];
    in[0].index=0;
    in[0].buf=img.data;
    in[0].size=img.cols*img.rows*img.channels();
    in[0].pass_through=false;
    in[0].type=RKNN_TENSOR_FLOAT32;
    
    in[0].fmt=RKNN_TENSOR_NHWC;
    int ret=rknn_inputs_set(ctx,1,in);
    if(ret<0)
    {
        std::cout<<"rknn input_set fail"<<std::endl;
        return -1.0;
    }
    ret=rknn_run(ctx,nullptr);
    if(ret<0)
    {
        std::cout<<"rknn run fail"<<std::endl;
    }
    std::cout<<"model predict achieve"<<std::endl;
    float *result=(float*)out[0].buf;
    std::cout<<"is line probability: "<<result[0]<<std::endl;
    if (result[0]>result[1])
    {
        return 0.0;
    }
    
    
    
    return 1.0;

}

rknn_context getmodel(int & num)
{
  

   rknn_context ctx=0;
    FILE *fp=fopen("/home/toybrick/LSF/modelTransfer/weight.rknn","rb");
    if(NULL== fp)
    {
        std::cout<<"model is not exist"<<std::endl;
        return ctx;

    }
    fseek(fp,0,SEEK_END);
    int model_len=ftell(fp);
    void *pModel=malloc(model_len);
    fseek(fp,0,SEEK_SET);
    if(model_len!=fread(pModel,1,model_len,fp))
    {
        std::cout<<"read model fail"<<std::endl;
        free(pModel);
        return ctx;
    }

    int ret=rknn_init(&ctx,pModel,model_len,RKNN_FLAG_PRIOR_MEDIUM|RKNN_FLAG_COLLECT_PERF_MASK);
    if(ret<0)
    {
        std::cout<<"init rknn environment fail"<<std::endl;
        return ctx;
    }
    std::cout<<"init rknn enviroment success"<<std::endl;
    rknn_tensor_attr attr;
    attr.index=0;
    ret=rknn_query(ctx,RKNN_QUERY_OUTPUT_ATTR,&attr,sizeof(attr));
    if(ret<0)
    {
        std::cout<<"rknn_query fail"<<std::endl;
        return ctx;
    }
    num=attr.n_elems;
    return ctx;
}






void lineCompute(int x1,int y1,int x2,int y2,double &a,double &b)
{
    a=(y2-y1)*1.0/(x2-x1);
    b=y1-a*x1;
}



// double obstacleDistance(cv::Mat & img,rknn_output * out)
// {
//     double dis;
//     rotate(img,img,ROTATE_180);
//     flip(img,img,1);
//     double a1,b1,a2,b2;
//     line(img,Point(0,0),Point(1280,470),Scalar(0,0,255),2);
//     line(img,Point(0,64),Point(1280,534),Scalar(0,0,255),2);
//     lineCompute(0,0,1280,470,a1,b1);
//     lineCompute(0,64,1280,534,a2,b2);
    

//     int w;
    
//     for (size_t i = 0; i <img.cols/64 ; i++)
//     {
//        w=i*64;
//        int y_=(int)(a1*w+b1);
//        Mat roi=img(Rect(w,y_,64,64));
//        float res=rec(roi,ctx2,out);
//        std::cout<<"num i="<<i<<" is:"<<res<<std::endl;

//     }
     

    
//     for (size_t i = 0; i <img.cols/64 ; i++)
//     {
//        w=i*64;
//        int y_=(int)(a1*w+b1);
//        rectangle(img,Rect(w,y_,64,64),Scalar(0,255,0),1,LINE_AA,0);
//     }
    

   
//     return dis;
// }


int main()
{
      
    cv::Mat frame,img;
    VideoCapture capture("rtsp://admin:abcd1234@192.168.3.68/mpeg4/ch1/main/av_stream");
    
    int num=0;
    rknn_context ctx=getmodel(num);
    if(num<=0)
    {
        std::cout<<"init rknn model fail"<<std::endl;
        return -1;
    }
    rknn_output out[1];
    out[0].want_float=true;
    out[0].is_prealloc=true;
    out[0].index=0;
    out[0].buf=malloc(num*sizeof(float));
    out[0].size=num*sizeof(float);
    
 
    cvtColor(frame,frame,COLOR_BGR2RGB);

    while (capture.isOpened())
    {
        capture>>frame;
        
        frame.copyTo(img);
        
        rotate(img,img,ROTATE_180);
        flip(img,img,1);
        double a1,b1,a2,b2;
        line(img,Point(0,0),Point(1280,470),Scalar(0,0,255),2);
        line(img,Point(0,64),Point(1280,534),Scalar(0,0,255),2);
        lineCompute(0,0,1280,470,a1,b1);
        lineCompute(0,64,1280,534,a2,b2);
    

        int w;
    
        for (size_t i = 0; i <img.cols/64 ; i++)
         {
            w=i*64;
            int y_=(int)(a1*w+b1);
            Mat roi=img(Rect(w,y_,64,64));
            float res=rec(roi,ctx,out);
            std::cout<<"num i="<<i<<" is:"<<res<<std::endl;

         }
     

    
        for (size_t i = 0; i <img.cols/64 ; i++)
        {
           w=i*64;
           int y_=(int)(a1*w+b1);
           rectangle(img,Rect(w,y_,64,64),Scalar(0,255,0),1,LINE_AA,0);
        }
    

   
   
        imshow("img",frame);
        waitKey(10);
    }
    return 0;
}