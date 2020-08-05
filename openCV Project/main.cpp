#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat img_color;

	img_color = imread("love.jpg", IMREAD_COLOR);

	Mat img_channels[3];
	split(img_color, img_channels);
	
	//BGR->RGB·Î ¹Ù²Þ.
	vector<Mat> channels;
	channels.push_back(img_channels[2]); //red;
	channels.push_back(img_channels[1]); //green;
	channels.push_back(img_channels[0]); //blue;

	Mat img_result;
	merge(channels, img_result);

	imshow("Color",img_result);
	imshow("B", img_channels[0]);
	imshow("G", img_channels[1]);
	imshow("R", img_channels[2]);
	waitKey(0);

	return 0;
}