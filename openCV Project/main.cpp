#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat img_color;

	img_color = imread("download.jpg", IMREAD_COLOR);
	if (img_color.empty())
	{
		cout << "������ �� �� �����ϴ�!" << endl;
		return -1;
	}

	Mat img_gray;

	cvtColor(img_color, img_gray, COLOR_BGR2GRAY);
	imwrite("gray image.jpg", img_gray);

	namedWindow("BGR", WINDOW_AUTOSIZE);
	namedWindow("Grayscale", WINDOW_AUTOSIZE);

	imshow("BGR", img_color);
	imshow("Grayscale", img_gray);

	while (waitKey(0) != 27);

	return 0;
}