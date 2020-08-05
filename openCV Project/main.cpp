#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

static void on_trackbar(int, void*)
{

}

int main()
{
	namedWindow("Canny");

	//Ʈ���� ����
	createTrackbar("low threshold", "Canny", 0, 1000, on_trackbar);
	createTrackbar("high threshold", "Canny", 0, 1000, on_trackbar);

	//Ʈ���� �ʱⰪ ����
	setTrackbarPos("low threshold", "Canny", 50);
	setTrackbarPos("high threshold", "Canny", 150);

	Mat img_gray;
	img_gray = imread("road.jpg", IMREAD_GRAYSCALE);

	//Ʈ���� ������ Canny�Լ��� �ݿ��ǵ��� ���ѷ����� ���
	while (1)
	{
		//���� Ʈ������ġ �ҷ�����
		int low = getTrackbarPos("low threshold", "Canny");
		int high =getTrackbarPos("high threshold", "Canny");

		Mat img_canny;
		Canny(img_gray, img_canny, low, high);

		//Canny�Լ��� ������Ȯ�� Canny��? �������� ���� �Լ��� ������ ���ش�.
		imshow("Canny", img_canny);

		if (waitKey(1) == 27)
			break;
	}

	return 0;
}