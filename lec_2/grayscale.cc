#include <iostream>
#include <opencv2/core/core.php> // the basic functions of OpenCV
#include <opencv2/imgproc/imgproc.hpp> // image edition in OpenCV
#include <opencv2/highgui/highgui.hpp> // header file for GUI

using namespace cv; // OpenCV namespace
using namespace std;

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		cerr << "usage: grayscale <file>" << endl;
		return -1;
	}
	Mat image = imread(argv[1]); // reading the image
	cvtColor(image, grayImage, CV_BGR2GRAY); // changing the color
	const string fileName = "gray.jpg";
	imwrite(fileName, grayImage); // saving grayImage to fileName

	string windowName = "Original"; // name for the GUI window
	namedWindow(windowName, CV_WINDOW_AUTOSIZE);
	imshow(windowName, image);
	windowName = "Gray Image";
	namedWindow(windowName, CV_WINDOW_AUTOSIZE);
	imshow(windowName, grayImage);
	waitKey(0);
	image.release();
	grayImage.release();

	return 0;
}