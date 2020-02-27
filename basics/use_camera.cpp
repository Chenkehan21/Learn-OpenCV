#include <opencv2/opencv.hpp>
#include <iostream>


using namespace cv;
using namespace std;


int main(){
	VideoCapture capture(0);
	if (!capture.isOpened()){
		cerr << "open cammera failed !!!" << endl;
		return -1;
	}
	Size s(640, 480);
	VideoWriter writer = VideoWriter("myvideo.avi", CV_FOURCC('M', 'J', 'P','G'), 25, s); // 25 is fps.
	if (!writer.isOpened()){
		cerr << "creat writer failed !!!" << endl;
		return -1;
	}
	Mat frame(s, CV_8UC3);
	
	while (1){
		capture >> frame;
		if (frame.empty()){
			break;
		}
		imshow("camera", frame);
		writer << frame;
		if (waitKey(30) >= 0){
			break;
		}
	}
	return 0;
}
