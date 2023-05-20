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
        bool flagCenter = false;
        vector <Point> roadsPoint;
        vector <Point> cityCenter;

    public:
        Iran();
        Mat Access();
        void updateMap();
        void drawCityCenter()
        void Mouse(int ,int ,int ,int);
        static void mouseAttacher(int ,int ,int ,int ,void *);
};

#endif // MAP_HPP