#include <opencv2/opencv.hpp>
#include <iostream>


using namespace cv;
using namespace std;


int main(){
	VideoCapture cap(0);
	if (!cap.isOpened()){
		cerr << "camera open failed!" << endl;
		return -1;
	}
	Size s(640, 480); 
	//the parameters must in line with the camrea, otherwise, the camera can be used but the video can't open.
	Mat frame(s, CV_8UC3);
	VideoWriter writer = VideoWriter("test_video.avi", CV_FOURCC('M', 'J', 'P', 'G'), 30, s);
	// 25 is fps(frame per second) has nothing to do with clearity.
	// high fps means the video will be very smooth.
	double t = 0;
	double fps;
	namedWindow("camera", CV_WINDOW_AUTOSIZE);
	if (!writer.isOpened()){
		cerr << "writer create failed!!!" << endl;
		return -1;
	}
	while (1){
		t = (double)getTickCount();
		cap >> frame;
		if (frame.empty()){
			cerr << "frame empty!" << endl;
			break;
		}
		t = ((double)getTickCount() - t) / (cvGetTickFrequency() * 1e6); // important!
		fps = 1.0 /t;
		printf("fps(reality): %.2f || fps(camera): %.2f\n", fps, cap.get(CV_CAP_PROP_FPS));
		writer << frame; //writer should accept a Mat object !! can't " writer << cap " !!!
		imshow("camera", frame);
		if (waitKey(30) >= 0){break;}
		// without this line, the video can be recoreded, but we can't see anything on the screen.
		// it has nothing to do with fps.
	}
	return 0;
}
