#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

static void on_trackbar(int, void*)
{

}

int main()
{
	namedWindow("Canny Edge");
	createTrackbar("low threshold", "Canny Edge", 0, 1000, on_trackbar);
	createTrackbar("high threshold", "Canny Edge", 0, 1000, on_trackbar);
	setTrackbarPos("low threshold", "Canny Edge", 50);
	setTrackbarPos("high threshold", "Canny Edge", 150);
	Mat img;
	img = imread("1.png", IMREAD_COLOR);
	Mat img_gray;
	cvtColor(img, img_gray, COLOR_BGR2GRAY);
	imshow("Original", img_gray);
	Mat img_edge;
	blur(img_gray, img_gray, Size(3, 3));

	while (1)
	{
		int low = getTrackbarPos("low threshold", "Canny Edge");
		int high = getTrackbarPos("high threshold", "Canny Edge");

		Canny(img_gray, img_edge, low, high, 3);
		imshow("Canny Edge", img_edge);

		if (waitKey(1) == 27)
			break;
	}

	return 0;
}