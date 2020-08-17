/*
직시각형 좌표 (539,399) , (959,598)
원본에 덧씌우기 라인
라인 확실히 인식하는 법 연구
*/
#include <opencv2/opencv.hpp>
#include <Windows.h>
#include <iostream>

using namespace std;
using namespace cv;

Mat img_src = imread("road.png", IMREAD_COLOR);
Mat img_canny, img_edge, img_Hough;
bool mouse_is_pressing = false;
int start_x = -1, start_y = -1;

void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

static void on_trackbar(int, void*)
{

}

void doHoughline(Mat img_edge)
{
	vector<Vec4i> linesP;
	HoughLinesP(img_edge, linesP, 1, CV_PI / 180, 50, 10, 5);	//맨뒤 : gap, 그 앞 : 직선 최소길이
	for (size_t i = 0; i < linesP.size(); i++)
	{
		Vec4i l = linesP[i];
		line(img_Hough, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, LINE_AA);
	}
}

//Drag on Src and output ROI with HoughLineP
void mouse_callback(int event, int x, int y, int flags, void* param)
{
	img_canny = img_src.clone();

	if (event == EVENT_LBUTTONDOWN)
	{
		mouse_is_pressing = true;
		start_x = x;
		start_y = y;
		circle(img_canny, Point(x, y), 10, Scalar(0, 255, 0), -1);
		cout << x << ", " << y << "\n";
		imshow("img_color", img_canny);
	}

	else if (event == EVENT_MOUSEMOVE)
	{
		if (mouse_is_pressing)
		{
			rectangle(img_canny, Point(start_x, start_y), Point(x, y), Scalar(0, 255, 0), 3);
			imshow("img_color", img_canny);
		}
	}
	else if (event == EVENT_LBUTTONUP)
	{
		cout << x << ", " << y << "\n";

		mouse_is_pressing = false;
		if (start_x > x)
		{
			swap(&x, &start_x);
			swap(&y, &start_y);
		}
		Mat img_cat(img_src, Rect(start_x, start_y, x - start_x, y - start_y));
		cvtColor(img_cat, img_cat, COLOR_BGR2GRAY);
		
		//Canny, HoughLines (both of single channel)
		Canny(img_cat, img_edge, 30, 150);
		cvtColor(img_edge, img_Hough, COLOR_GRAY2BGR);
		
		doHoughline(img_edge);
		
		cvtColor(img_cat, img_cat, COLOR_GRAY2BGR);
		img_cat.copyTo(img_canny(Rect(start_x, start_y, x - start_x, y - start_y)));
		
		imshow("img_color", img_canny);
		imshow("Hough Lines", img_Hough);
	}

}
int main()
{
	
	imshow("img_color", img_src);
	setMouseCallback("img_color", mouse_callback);
	waitKey(0);
			
	return 0;
}