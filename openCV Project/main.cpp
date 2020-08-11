#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;



int main()
{
	Mat img_color = imread("love.jpg", IMREAD_COLOR);
	imshow("original", img_color);
	Mat img_result;
	resize(img_color, img_result, Size(), 2, 2, INTER_CUBIC);
	imshow("x2 INTER_CUBIC", img_result);

	int width = img_color.cols;
	int height = img_color.rows;
	
	resize(img_color, img_result, Size(3 * width, 3 * height), INTER_LINEAR);
	imshow("x3 INTER_LINEAR", img_result);

	resize(img_color, img_result, Size(), 0.5, 0.5, INTER_AREA);
	imshow("x0.5 INTER_AREA", img_result);

	waitKey(0);

	return 0;
}