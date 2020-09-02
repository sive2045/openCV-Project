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
		cout << "자표 = x : " << x << ", y : " << y << endl;
	}
	
}



int main()
{
	Mat img_original, img_gray;
	img_original = imread("img_annota1ted.jpg", IMREAD_COLOR);

	cvtColor(img_original, img_gray, COLOR_BGR2GRAY);
	
	namedWindow("original image", WINDOW_AUTOSIZE);
	namedWindow("gray scale", WINDOW_AUTOSIZE);

	//윈도우에 출력  
	imshow("original image", img_original);
	imshow("gray image", img_gray);

	//윈도우에 콜백함수를 등록
	setMouseCallback("gray image", mouse_callback, NULL);


	//키보드 입력이 될때까지 대기  
	waitKey(0);

	return 0;
}