
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class FilterTransform
{

public:
    static Mat Blur(Mat image, int size = 5)
    {
        Mat dit(image.size(), CV_32FC3);
        blur(image, dit, Size(size, size));

        return dit;
    }
    static Mat Filter(Mat image, Mat kern)
    {
        
        // image= LogTransform::ToGrey(image);
        Mat dit(image.size(), image.type());
        filter2D(image, dit, -1, kern);
        normalize(dit, dit, 0, 255, NORM_MINMAX);
        return dit;
    }
};