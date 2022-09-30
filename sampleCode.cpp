

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include "LogTransform.cpp"
#include "FilterTransform.cpp"

using namespace cv;
using namespace std;

Mat Read(string path)
{
	return imread(path);
}
void Save(Mat image, string path)
{
	imwrite(path, image);
}

int main(void)
{
	/*
	Save(Read("../images/src/P1.jpg"), "../images/dit/P1.jpg");

	Save(LogTransform::Convert(Read("../images/src/P1.jpg"), 6), "../images/dit/P1.jpg");

	Save(LogTransform::Convert(Read("../images/src/P2.jpg"), 8), "../images/dit/P2.jpg");

	Save(
		LogTransform::ToGrey(Read("../images/src/P1.jpg")), "../images/dit/P1_grey.jpg");

	Save(
		LogTransform::ToGrey(Read("../images/src/P2.jpg")), "../images/dit/P2_grey.jpg");

	Save(LogTransform::Convert(Read("../images/dit/P1_grey.jpg"), 6), "../images/dit/P1_grey_after.jpg");

	Save(LogTransform::Convert(Read("../images/dit/P2_grey.jpg"), 8), "../images/dit/P2_grey_after.jpg");

	*/

	// Save(FilterTransform::Blur(Read("../images/src/P3.jpg"),60), "../images/dit/P3_blur.jpg");
	// Save(FilterTransform::Blur(Read("../images/src/P6.jpg"),10), "../images/dit/P6_blur1.jpg");

	Mat kernGx = (Mat_<char>(3, 3)
					  << -1,
				  0, 1,
				  -2, 0, 2,
				  -1, 0, 1);
	Mat kernGy = (Mat_<char>(3, 3)
					  << 1,
				  2, 3,
				  0, 0, 0,
				  -1, -2, -3);

	Mat kernG_x = (Mat_<char>(3, 3) << -1, 0, 1,
				   -1, 0, 1,
				   -1, 0, 1);
	Mat kernG_y = (Mat_<char>(3, 3) << 1, 1, 1,
				   0, 0, 0,
				   -1, -1, -1);

	Mat p45 = (Mat_<char>(3, 3) <<
	 0, 1, 1,
			   -1, 0, 1,
			   -1, -1, 0);
	Mat n45 = (Mat_<char>(3, 3) << -1, -1, 0,
			   -1, 0, 1,
			   0, 1, 1);
	cout << kernGx + kernGy << endl
		 << kernG_x + kernG_y << endl;

	// Save(FilterTransform::Filter(Read("../images/src/P5.jpg"), kernGx + kernGy), "../images/dit/P5_filter1.jpg");
	// Save(FilterTransform::Filter(Read("../images/src/P5.jpg"), kernG_x + kernG_y), "../images/dit/P5_filter2.jpg");



	Save(FilterTransform::Filter(Read("../images/src/P4.jpg"), p45), "../images/dit/P4_filter_p_my.jpg");
	Save(FilterTransform::Filter(Read("../images/src/P4.jpg"), n45), "../images/dit/P4_filter_n_my.jpg");
	// cout << FilterTransform::Filter(test, kernGx) << endl;

	return 0;
}