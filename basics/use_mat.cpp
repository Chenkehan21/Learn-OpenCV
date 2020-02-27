#include <opencv2/opencv.hpp>
#include <iostream>


using namespace std;
using namespace cv;


int main()
{
    Mat src; //utility 1: allocate memory for images automatically
    src = imread("/home/chenkehan/图片/EVA/-2041209915.jpg");
    if(src.empty()) // .empty() is a method of Mat
    {
        cout << "can't load this image!!" << endl;
        return -1;
    }
    namedWindow("lingboli", CV_WINDOW_AUTOSIZE);
    imshow("lingboli", src);

    Mat dst;
    dst = Mat(src.size(), src.type()); //utility 2: initialize a Mat object
    dst = Scalar(127, 0, 255);
    namedWindow("output1", CV_WINDOW_AUTOSIZE);
    imshow("output1", dst);

    Mat cloned_img; //utility3: clone a image
    cloned_img = src.clone();
    namedWindow("cloned_lingboli", CV_WINDOW_AUTOSIZE);
    imshow("cloned_lingboli", cloned_img);

    
    //utility4: use the methods of Mat to show some information about the image
    Mat dst2;
    cvtColor(src, dst2, CV_BGR2GRAY);
    int src_channels, dst2_channels, dst2_rows, dst2_cols;
    src_channels = src.channels();
    dst2_channels = src.channels();
    dst2_rows = dst.rows;
    dst2_cols = dst.cols;
    cout << "src channels: " << src_channels << endl;
    cout << "dst2 channels: " << dst2_channels << endl;
    cout << "dst2 rows: " << dst2_rows << endl;
    cout << "dst cols: " << dst2_cols << endl;

    
    //utility5: get the pixel value
    const uchar* firstrow_pixel = dst2.ptr<uchar>(0);
    printf("first row's pixel: %d\n", *firstrow_pixel);
    
    
    //utility6: constructor
    Mat A(100, 100, CV_8UC3, Scalar(0, 0, 127)); //3 channels & 3 X 3
    //cout << "A: " << A << endl;
    namedWindow("constructor_A", CV_WINDOW_AUTOSIZE);
    imshow("constructor_A", A);
    
    
    //utility7: Mat creat
    Mat temp1;
    temp1.create(src.size(), src.type());
    temp1 = Scalar(23, 45, 255);
    namedWindow("temp1", CV_WINDOW_AUTOSIZE);
    imshow("temp1", temp1);
    
    
    //utility8: definde a matrix
    Mat kernel;
    kernel = (Mat_<float>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
    cout << "kernel: " << kernel;
    waitKey(0);
    return 0;
}
