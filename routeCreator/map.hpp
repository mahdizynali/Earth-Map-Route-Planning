#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include <chrono>
#include <cmath>
#include <thread>

using namespace std;
using namespace cv;
using namespace chrono;
using namespace this_thread;

class Country {

    private:
        Mat map;
        bool flagCenter = false;
        vector <Point> roadsPoint;
        vector <Point> cityCenter;

    public:
        Country(string);
        Mat Access();
        void updateMap();
        void drawCityCenter();
        static void mouseAttacher(int ,int ,int ,int ,void *);
        void Mouse(int ,int ,int ,int);
};

#endif // MAP_HPP