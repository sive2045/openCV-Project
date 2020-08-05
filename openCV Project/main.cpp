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

	//트랙바 생성
	createTrackbar("low threshold", "Canny", 0, 1000, on_trackbar);
	createTrackbar("high threshold", "Canny", 0, 1000, on_trackbar);

	//트랙바 초기값 설정
	setTrackbarPos("low threshold", "Canny", 50);
	setTrackbarPos("high threshold", "Canny", 150);

	Mat img_gray;
	img_gray = imread("road.jpg", IMREAD_GRAYSCALE);

	//트랙바 조정시 Canny함수에 반영되도록 무한루프를 사용
	while (1)
	{
		//현재 트랙바위치 불러오기
		int low = getTrackbarPos("low threshold", "Canny");
		int high =getTrackbarPos("high threshold", "Canny");

		Mat img_canny;
		Canny(img_gray, img_canny, low, high);

		//Canny함수의 실행결과확인 Canny란? 윤곽선을 따는 함수로 라인을 따준다.
		imshow("Canny", img_canny);

		if (waitKey(1) == 27)
			break;
	}

	return 0;
}