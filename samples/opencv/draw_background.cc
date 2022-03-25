#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>   
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace cv;

void test1()
{
   // namedWindow("利用ROI实现图像叠加");
    auto logo = imread("/home/jim/code/demo/build/outer_frame.png");
    if (!logo.data)
    {
        cout << "read image logo error!" << endl;
        return;
    }
    auto img1 = imread("/home/jim/code/demo/datouzhao_1.png");
    if (!img1.data)
    {
        cout << "read image img2 error!" << endl;
        return;
    }

    cv::Mat mask = cv::imread("/home/jim/code/demo/build/outer_frame.png",0);

    imshow("ubt", logo);
    // imshow("women", img1);
    
    Mat imageROI;
    imageROI = img1(cv::Rect(0,360,logo.cols,logo.rows)); //450
    logo.copyTo(imageROI, mask);
    imshow("Hello", img1);
    waitKey(0);
    return;
}

void test2()
{
   // namedWindow("利用ROI实现图像叠加");
    auto logo = imread("/home/jim/code/demo/build/outer_frame.png");
    if (!logo.data)
    {
        cout << "read image logo error!" << endl;
        return;
    }
    auto img1 = imread("/home/jim/code/demo/datouzhao_1.png");
    if (!img1.data)
    {
        cout << "read image img2 error!" << endl;
        return;
    }

    cv::Mat mask = cv::imread("/home/jim/code/demo/build/outer_frame.png",0);

    imshow("ubt", logo);
    // imshow("women", img1);
    
    Mat imageROI;
    imageROI = img1(cv::Rect(0,360,logo.cols,logo.rows)); //450
    cv::addWeighted(imageROI, 1.0, logo, 0.6, 0, imageROI);
    imshow("Hello", img1);
    waitKey(0);
    return;
}

void test3()
{
    auto logo = imread("/home/jim/code/demo/build/outer_frame.png");
    if (!logo.data)
    {
        cout << "read image logo error!" << endl;
        return;
    }
    imshow("ubt", logo);
    waitKey(0);
}

int main()
{
    test1();
}
