

#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
class LogTransform
{

public:
    static Mat Convert(Mat image, int param = 10)
    {

        auto width = image.rows;
        auto hight = image.cols;
        Mat dit(image.size(), CV_32FC3);
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < hight; j++)
            {

                int pix0 = image.at<Vec3b>(i, j)[0];
                int pix1 = image.at<Vec3b>(i, j)[1];
                int pix2 = image.at<Vec3b>(i, j)[2];

                // cout << pix0 << ' ' << pix1 << ' ' << pix2 << endl;
                dit.at<Vec3f>(i, j)[0] = log(param + pix0);
                dit.at<Vec3f>(i, j)[1] = log(param + pix1);
                dit.at<Vec3f>(i, j)[2] = log(param + pix2);
            }
        }
        normalize(dit, dit, 0, 255, NORM_MINMAX);
        return dit;
    }
    static Mat ToGrey(Mat image)
    {

        Mat grey;
        cvtColor(image, grey, COLOR_RGB2GRAY);
        return grey;
    }
};