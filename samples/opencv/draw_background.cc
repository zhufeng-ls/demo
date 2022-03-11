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
    auto img1 = imread("/home/jim/code/demo/build/ubt.png");
    if (!img1.data)
    {
        cout << "read image img1 error!" << endl;
        return;
    }
    auto img2 = imread("/home/jim/code/demo/build/datouzhao_1.png");
    if (!img2.data)
    {
        cout << "read image img2 error!" << endl;
        return;
    }

    imshow("ubt", img1);
    imshow("women", img2);
    
    Mat out;
    out = img2(cv::Rect(450,360,img1.cols,img1.rows));
    imshow("Hello", out);

    waitKey(0);
    return;
}

int main()
{
    test1();
}
