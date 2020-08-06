#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main()
{
	Mat img_1, img_2;
	double alpha = 0.0;
	double beta = 1.0;
	
	while (alpha <= 1.0)
	{
		//addWeightó���ϱ����ؼ��� �Ź� �ҷ��;���. 
		//�� �̹��� ũ��� ���ƾ� ��.
		img_1 = imread("love.jpg", IMREAD_COLOR);
		img_2 = imread("back.jpg", IMREAD_COLOR);

		Mat dst;
		addWeighted(img_1, alpha, img_2, beta, 0, dst);

		cout << alpha << " " << beta << endl;

		imshow("Result", dst);
		waitKey(0);

		alpha += 0.1;
		beta -= 0.1;
	}

	return 0;
}