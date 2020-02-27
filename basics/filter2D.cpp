#include <opencv2/opencv.hpp>
#include <iostream>


using namespace cv;
using namespace std;

int main()
{
    Mat src, dst;
    src = imread("/home/chenkehan/图片/EVA/680909770.png");
    if(src.empty())
    {
        cout << "can't load this image!";
        return -1;
    }
    Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(src, dst, src.depth(), kernel);
    namedWindow("lingboli_rgb", CV_WINDOW_AUTOSIZE);
    imshow("lingboli_rgb", src);
    namedWindow("lingboli_filter", CV_WINDOW_AUTOSIZE);
    imshow("lingboli_filter", dst);
    imwrite("/home/chenkehan/OpenCV-Test/images/lingboli_filter.png", dst);
    waitKey(0);
    return 0;
}
