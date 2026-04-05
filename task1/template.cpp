#include <iostream>
#include <opencv2/opencv.hpp>
#include "convolution.hpp" 

using namespace std;

int main()
{
    // The two kernels — do not change these
    cv::Mat K1 = (cv::Mat_<double>(3, 3) <<
         1,  2,  1,
         0,  0,  0,
        -1, -2, -1
    );

    cv::Mat K2 = (cv::Mat_<double>(3, 3) <<
         1,  0, -1,
         2,  0, -2,
         1,  0, -1
    );

    cv::Mat img = cv::imread("./assets/hogwarts.png", cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        cerr << "Could not load image at ./assets/hogwarts.png\n";
        return -1;
    }
     cv::Mat intermediate;
      cv::Mat output_1;
      cv::Mat output_2;


    cv::Mat img_f;
    img.convertTo(img_f, CV_64FC1);
    intermediate = convolve(img, K1);
    output_1 = convolve(intermediate,  K1); 

    intermediate = convolve(img, K2);
    output_2 = convolve(intermediate,  K2); 








    // TODO: apply K1 and K2 to img_f with as few multiplications per pixel as possible.
    // Print the number of multiplications your approach uses per pixel.
     
      cv::imshow("Output by Naive Seperable Convolution", output_1);
      cv::waitKey(0); 
      cv::imshow("Output by Naive Seperable Convolution", output_2);
      cv::waitKey(0); 

    return 0;
}
