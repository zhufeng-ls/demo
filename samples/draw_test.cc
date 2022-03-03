
#include <opencv4/opencv2/core/core.hpp>
#include "opencv4/opencv2/highgui/highgui.hpp"
#include <opencv4/opencv2/imgproc/imgproc.hpp>
using namespace cv;
 
//宏定义部分
 
#define Win_Name3 "Cross 红十字"


void drawRegtangle(Mat image) 
{
    //Mat image3 = Mat::zeros(800, 800, CV_8UC3);//生成一个800x800的窗口
    Rect rec1 = Rect(100, 300, 600, 200);
    rectangle (image, rec1,Scalar(0, 0, 255), -1, 8, 0);//横矩形
    rectangle (image, Point(100, 300), Point(700, 500), Scalar(0, 255, 255), 2, 8, 0);//黄色矩形镶边
    imshow(Win_Name3, image);
    //waitKey();
}

void showVideo1()
{
    // const auto window_name = "Display Image";
    // namedWindow(window_name, WINDOW_NORMAL);
    // imshow(window_name, color_mat);
    // if (waitKey(1) >=1)
    //     break;
}

int showVideo2()
{
    VideoCapture cap("../doc/chenyuanliang.mp4"); 
    if(!cap.isOpened()) 
    { 
        return -1; 
    } 
    Mat frame;  
    while(1) 
    { 
        cap>>frame; 
        //drawRegtangle(frame);
        if(frame.empty()) break;
        imshow("当前视频",frame); 
        if(waitKey(1) >=1) 
            break;
    } 
    return 0;
}

//main函数
int main(int argc,char** argv)
{
    showVideo2();
    //<span style="white-space:pre"> </span>//绘制红十字
}