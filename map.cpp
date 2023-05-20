#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;


int main() {
    cv::Mat test;
    test = cv::imread("/home/maximum/Desktop/Iran-Map-Route-Planning/map.png");
    cv::imshow("test", test);
    cv::waitKey(0);

    return 0;
}