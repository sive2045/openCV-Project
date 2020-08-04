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
		cout << "파일을 열 수 없습니다!" << endl;
		return -1;
	}

	Mat img_gray_3channel, img_gray_1channel;
	img_gray_3channel.create(img_color.rows, img_color.cols, CV_8UC3);
	img_gray_1channel.create(img_color.rows, img_color.cols, CV_8UC1);

	for (int y = 0; y < img_color.rows; y++)
	{
		for (int x = 0; x < img_color.cols; x++)
		{
			//2
			uchar b = img_color.at<Vec3b>(y, x)[0];
			uchar g = img_color.at<Vec3b>(y, x)[1];
			uchar r = img_color.at<Vec3b>(y, x)[2];

			//3
			uchar gray = (b + g + r) / 3.0;


			//4
			img_gray_1channel.at<uchar>(y, x) = gray;



			//5
			img_gray_3channel.at<Vec3b>(y, x)[0] = gray;
			img_gray_3channel.at<Vec3b>(y, x)[1] = gray;
			img_gray_3channel.at<Vec3b>(y, x)[2] = gray;
		}
	}


	imshow("Grayscale 3 channel", img_gray_3channel);
	imshow("Grayscale 1 channel", img_gray_1channel);

	while (waitKey(0) != 27);

	return 0;
}