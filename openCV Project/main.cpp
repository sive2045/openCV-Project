#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main()
{
	Mat img;
	img = imread("love.jpg", IMREAD_COLOR);

	int height = img.rows;
	int width = img.cols;

	int center_x = (int)width*0.5;
	int center_y = (int)height*0.5;

	//���� ���縦 ���� ���� ������ä cannyó��
	Mat img_roi;
	img_roi = img(Rect(center_x - 100, center_y - 100, 200, 200)).clone();
	Mat img_gray;
	cvtColor(img_roi, img_gray, COLOR_BGR2GRAY);
	//cannyó���� BGRü�η� ��ȯ
	Mat img_edge;
	Canny(img_gray, img_edge, 100, 300);
	cvtColor(img_edge, img_edge, COLOR_GRAY2BGR);
	//������ �ռ�
	img_edge.copyTo(img(Rect(center_x-100,center_y-100,200,200)));
	//��� �����ֱ�
	
	imshow("ROI", img_roi);
	imshow("Result", img);
	waitKey(0);

	return 0;
}