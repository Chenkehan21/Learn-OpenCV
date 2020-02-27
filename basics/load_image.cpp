# include <opencv2/opencv.hpp>
# include <iostream>


using namespace cv;
int main(){
    Mat src = imread("/home/chenkehan/图片/EVA/-2041209915.jpg");
    if (src.empty()){
        printf("could not load img/n");
	return -1;
    }
    namedWindow("lingboli", CV_WINDOW_AUTOSIZE);
    imshow("lingboli", src);

    namedWindow("lingboli_gray", CV_WINDOW_AUTOSIZE);
    Mat output1;
    cvtColor(src, output1, CV_BGR2GRAY);
    imshow("lingboli_gray", output1);
    imwrite("/home/chenkehan/OpenCV-Test/images/ouput1_gray.png", output1);

    namedWindow("lingboli_hsv", CV_WINDOW_AUTOSIZE);
    Mat output2;
    cvtColor(src, output2, CV_BGR2HSV);
    imshow("lingboli_hsv", output2);
    imwrite("/home/chenkehan/OpenCV-Test/images/output2_hsv.png", output2);
    waitKey(0);
    return 0;
}
