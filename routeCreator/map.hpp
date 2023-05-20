#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
using namespace std;
using namespace cv;

class Iran {

    private:
        Mat map;

    public:
        Iran();
        void fieldCreate();
        Mat Access();
};

#endif // MAP_HPP