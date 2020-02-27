#include <opencv2/opencv.hpp>
#include <iostream>
 
using namespace std;
using namespace cv;
 
int main()
{
	
	VideoWriter video("test.avi", CV_FOURCC('X', 'V', 'I', 'D'), 5, Size(1920, 1080));
 
	String img_path = "/home/chenkehan/图片/EVA/*.jpg";
	vector<String> img;
 
	glob(img_path, img, false); // use glob can get images from img_path and store them into Vector<string> img.
 
	size_t count = img.size(); // size_t can create enough space to store the images!
	for (size_t i = 0; i < count; i++)
	{
		Mat image = imread(img[i]);
		resize(image, image, Size(1920, 1080));	
		video << image;
	}
	cout << "处理完毕！" << endl;
	return 0;
}

