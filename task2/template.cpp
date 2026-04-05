#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    // Load the three fragment images as grayscale — do not change these lines
    cv::Mat frag_a = cv::imread("./assets/fragment_a.png", cv::IMREAD_GRAYSCALE);
    cv::Mat frag_b = cv::imread("./assets/fragment_b.png", cv::IMREAD_GRAYSCALE);
    cv::Mat frag_c = cv::imread("./assets/fragment_c.png", cv::IMREAD_GRAYSCALE);

    if (frag_a.empty() || frag_b.empty() || frag_c.empty()) {
        cerr << "Could not load one or more fragment images from ./assets/\n";
        return -1;
    }

    // TODO: reverse the charm on eacfh fragment, merge the recovered channels
    // into a single BGR image, save it as ./assets/memory_restored.png,
    // and print the number of non-zero pixels in the result.
      cv::Mat s1 ,s2,s3;
      cv::Mat mat1 ,mat2 ,mat3 ;
      cv::Mat matsum32 = (s1 + s2 + s3);
      mat1.convertTo(s1,CV_32S);
      mat2.convertTo(s2 , CV_32S);
      mat3.convertTo(s3, CV_32S);
      //matsum32 = (s1 + s2 + s3);
      cv::Mat masked;
     // cv::bitwise_and(matsum32,cv::Scalar(0xFF),masked);
      cv::Mat result_A;
      masked.convertTo(result_A,CV_8U);

     
     
     cv::Mat flipped_a, flipped_c;
     cv::flip(frag_a,flipped_a,1);
     cv::flip(frag_c,flipped_c,0);
     cv::Mat inv_a;
     cv::bitwise_not(flipped_a,inv_a);
     cv::Mat B;
     inv_a.convertTo(B,CV_8UC1);

     vector<cv::Mat> channels = {B,frag_b,flipped_c};
      cv::Mat memory_restored;
      cv::merge(channels, memory_restored);
      imwrite("./assets/memory_restored.png", memory_restored);


    cv::Mat mask;
     cv::cvtColor(memory_restored, mask, cv::COLOR_BGR2GRAY);
     int K = countNonZero(mask);

     cout << "Number of non-zero pixels: " << K << endl;
     cv::imshow("Restored", memory_restored);
     cv::waitKey(0);





      

      
      


      

       

      
      




    

    return 0;
}
