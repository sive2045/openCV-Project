#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <gsl/gsl_fit.h>

using namespace std;
using namespace cv;

bool mouse_is_pressing = false;
int start_x, start_y, end_x, end_y;

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void mouse_callback(int event, int x, int y, int flags, void* param)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		cout << "��ǥ = x : " << x << ", y : " << y << endl;
	}
	
}



int main()
{
	Mat img_original, img_gray;
	img_original = imread("img_annota1ted.jpg", IMREAD_COLOR);

	cvtColor(img_original, img_gray, COLOR_BGR2GRAY);
	
	namedWindow("original image", WINDOW_AUTOSIZE);
	namedWindow("gray scale", WINDOW_AUTOSIZE);

	//�����쿡 ���  
	imshow("original image", img_original);
	imshow("gray image", img_gray);

	//�����쿡 �ݹ��Լ��� ���
	setMouseCallback("gray image", mouse_callback, NULL);


	//Ű���� �Է��� �ɶ����� ���  
	waitKey(0);

	return 0;
}