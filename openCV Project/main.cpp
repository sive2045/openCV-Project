#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Point2f src[4];
int idx = 0;
Mat img_color;

void mouse_callback(int event, int x, int y, int flags, void* userdata)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		src[idx] = Point(x, y);
		idx++;
		cout << "(" << x << ", " << y << ")" << endl;
		circle(img_color, Point(x, y), 10, Scalar(0, 255, 0), -1);
	}
}

int main()
{
	namedWindow("source");
	setMouseCallback("source", mouse_callback);
	img_color = imread("road.jpg");
	Mat img_original;
	img_original = img_color.clone();

	while (1)
	{
		imshow("source", img_color);

		if (waitKey(1) == 32)
			break;
	}

	int height = img_color.rows;
	int width = img_color.cols;

	Point2f dst[3];
	dst[0] = Point2f(0, 0);
	dst[1] = Point2f(width, 0);
	dst[2] = Point2f(0, height);
	dst[3] = Point2f(width, height);

	Mat M;
	M = getPerspectiveTransform(src, dst);

	Mat img_result;
	warpPerspective(img_original, img_result, M, Size(width, height));

	imshow("result", img_result);
	waitKey(0);

	return 0;
}