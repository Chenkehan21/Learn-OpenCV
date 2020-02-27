#include <opencv2/opencv.hpp>
#include <iostream>


using namespace cv;
using namespace std;


int main(){
	VideoCapture cap("/home/chenkehan/OpenCV-Test/zhenxinweini.avi");
	if (!cap.isOpened()){
		cerr << "can't open the video!!!" << endl;
		return -1;
	}
	double position = (35 * 60 + 20) * 1000;
	int Frames = 0;
	int num = 0;
	char ad[300] = {0};
	cap.set(CV_CAP_PROP_POS_MSEC, position); // let the video start from the specific place!!!
	while (1){
		Mat frame;
		cap >> frame;
		imshow("EVA", frame);
		if (waitKey(30) >= 0){
			break;
		}
		if (Frames % 40 == 0 && Frames < 40 * 20){
			sprintf(ad, "/home/chenkehan/OpenCV-Test/images/video_%d.png", ++num);
			imwrite(ad, frame);
			cout << "get" << num << "picture!" << endl;
		}
		if (Frames >= 40 * 20){
			break;
		}
		Frames++;
	}
	return 0;
}
