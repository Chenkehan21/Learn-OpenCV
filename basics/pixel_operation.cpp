#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;


int main()
{
    Mat src;
    src = imread("/home/chenkehan/图片/EVA/-2041209915.jpg");
    if(src.empty())
    {
        cout << "can't load this image!!" << endl;
        return -1;
    }
    namedWindow("lingboli", CV_WINDOW_AUTOSIZE);
    imshow("lingboli", src);
    
    
    // one channel pixel convert
    Mat gray_src;
    cvtColor(src, gray_src, CV_BGR2GRAY);
    imshow("gray lingboli", gray_src); // namedWindow can be omitted !!!
    int gray_height, gray_width;
    gray_height = gray_src.rows;
    gray_width = gray_src.cols;
    for (int row = 0; row < gray_height; row++){
    	for (int col = 0; col < gray_width; col++){
    		int gray_pixel = gray_src.at<uchar>(row, col);
    		gray_src.at<uchar>(row, col) = 255 - gray_pixel; // convert
    	}
    }
    imshow("gray converted lingboli", gray_src);
    imwrite("/home/chenkehan/OpenCV-Test/images/gray_converted_lingboli.png", gray_src);
    
    
    Mat dst, max_gray, min_gray;
    cvtColor(src, max_gray, CV_BGR2GRAY);
    cvtColor(src, min_gray, CV_BGR2GRAY);
    dst = Mat(src.size(), src.type());
    int height, width, pic_channels;
    height = src.rows;
    width = src.cols;
    pic_channels = src.channels(); 
    for (int row = 0; row < height; row++){
		for (int col = 0; col < width; col++){
		
			// one channel pixel convert
			if (pic_channels == 1){
				int gray_pixel = gray_src.at<uchar>(row, col);
    			gray_src.at<uchar>(row, col) = 255 - gray_pixel;
			}
			
			// three channels convert
			else if (pic_channels == 3){
				int r, g, b;
				b = src.at<Vec3b>(row, col)[0];
				g = src.at<Vec3b>(row, col)[1];
				r = src.at<Vec3b>(row, col)[2];
				dst.at<Vec3b>(row, col)[0] = 255 - b; //put the converted values into the dst!
				dst.at<Vec3b>(row, col)[1] = 255 - g;
				dst.at<Vec3b>(row, col)[2] = 255 - r;
				max_gray.at<uchar>(row, col) = max(r, max(g, b)); //max,min are in math.h
				min_gray.at<uchar>(row, col) = min(r, min(g, b));
			}
    	}
    }
    imshow("rgb converted lingboli", dst);
    imwrite("/home/chenkehan/OpenCV-Test/images/rgb_converted_lingboli.png", dst);
    
    imshow("max gray lingboli", max_gray);
    imwrite("/home/chenkehan/OpenCV-Test/images/max_gray_lingboli.png", max_gray);
    
    imshow("min gray lingboli", min_gray);
    imwrite("/home/chenkehan/OpenCV-Test/images/min_gray_lingboli.png", min_gray);
    
    // a faster way to achieve convert
    Mat dst2;
    bitwise_not(src, dst2);
    imshow("faster convert rgb lingboli", dst2);
    imwrite("/home/chenkehan/OpenCV-Test/images/faster_rgb_converted_lingboli.png", dst2);
    waitKey(0);
    return 0;
}
