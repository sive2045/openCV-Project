#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;



int main()
{
	Mat img = imread("123.jpg", IMREAD_GRAYSCALE);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat img_result;
	morphologyEx(img, img_result, MORPH_CLOSE, kernel);
	imshow("Op", img_result);
	threshold(img_result, img_result, 200, 255, THRESH_BINARY);
	
	imshow("Original", img);
	imshow("Output", img_result);
	
	waitKey(0);

	return 0;
}