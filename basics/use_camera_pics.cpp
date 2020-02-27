#include <opencv2/opencv.hpp>
#include <iostream>


using namespace cv;
using namespace std;


int main(){
	int d = 0;
	char address[300] = {0};
	vector<int> compression_params;
	compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(2); 
	// compression level:0-9, a higher value means a smaller size and longer compression time.
	
	VideoCapture cap(0);
	if (!cap.isOpened()){
		cerr << "open cammer failed!!!" << endl;
		return -1;
	}
	Size s(640, 480);
	Mat frame(s, CV_8UC3);
	while (1){
		cap >> frame;
		if (frame.empty()){
			break;
		}
		imshow("picture", frame);
		int k = waitKey(30);
		if (k == 27){
			break;
		}
		else if (k == 'c'){
			sprintf(address, "/home/chenkehan/OpenCV-Test/images/%d.png", ++d);
			imwrite(address, frame, compression_params);
			cout << "get" << d << "picture!" << endl;
		}
	}
	return 0;
}

