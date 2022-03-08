
#include <opencv4/opencv2/core/core.hpp>
#include "opencv4/opencv2/highgui/highgui.hpp"
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <unistd.h>
#include <iostream>
using namespace std;
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

void drawonmat(Mat& color_mat, float cur_depth, Rect bbox, bool has_target)
{

    // {

    //     if (bbox.x != 5 && bbox.y != 5 && bbox.width > 5 && bbox.height > 10)
    //     {
    //         std::ostringstream ss;
    //         ss << cur_depth;
    //         rectangle(color_mat, bbox, Scalar(0, 255, 0));
    //         putText(color_mat, ss.str(), Point(bbox.x + 5, bbox.y + 5),
    //                 FONT_HERSHEY_SIMPLEX, 0.8, Scalar(255, 255, 255));
    //     }
    // }

    Point2d mid(int(color_mat.cols/2),int(color_mat.rows/2));
    // cout<<(color_mat.rows/2)<<endl;
    line(color_mat, Point(mid.x-50, mid.y), Point(mid.x+50,mid.y), Scalar(255,255,0), 2);
    line(color_mat, Point(mid.x, mid.y-50), Point(mid.x,mid.y+50), Scalar(255,255,0), 2);
    rectangle(color_mat,
              Rect(int(mid.x - color_mat.rows/4 - color_mat.rows/20), 
              int(mid.y - color_mat.cols/4),
               int(color_mat.rows/2 + color_mat.rows/10),
            int(color_mat.cols/2))
        , Scalar(255, 255, 0), 2);

    // cout<<int(mid.x - color_mat.rows/4 - color_mat.rows/20)<<endl;
    // cout<<int(mid.x - color_mat.rows/4 - color_mat.rows/20+ int(color_mat.rows/2 + color_mat.rows/10))<<endl;


    if(has_target)
    {
        putText(color_mat, "YES target", Point(mid.x-100, 50),
                    FONT_HERSHEY_SIMPLEX, 2.0, Scalar(0, 255, 255));

    }
    else
    {
        putText(color_mat, "NO target", Point(mid.x-100, 50),
                    FONT_HERSHEY_SIMPLEX, 2.0, Scalar(0, 255, 255));
    }

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
    VideoCapture cap("../doc/out.mp4"); 
    if(!cap.isOpened()) 
    { 
        return -1; 
    } 
    Mat frame;  
    Rect rect(20,20,100,100);
    while(1) 
    { 
        cap>>frame; 
        //drawRegtangle(frame);
        drawonmat(frame, 0, rect, true);
        if(frame.empty()) break;
        std::cout << "width: "  << frame.size().width
                << "  height:  " << frame.size().height 
                << endl;
        imshow("当前视频",frame); 
        imwrite("1.png", frame);
        if(waitKey(1) >=1) 
            break;
        usleep(50*1000);
        //sleep(1);
    } 
    return 0;
}

//main函数
int main(int argc,char** argv)
{
    showVideo2();
    //<span style="white-space:pre"> </span>//绘制红十字
}