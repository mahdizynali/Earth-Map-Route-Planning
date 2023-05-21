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
        Mat roads; 
        bool flagRoads = false;
        int flagNewRoute = -1;
        Point mousePoint;
        Point cityCenter;
        vector <Point> wheel;

    public:
        Country(string);
        Mat Access();
        int updateMap();
        void drawRoutes();
        static void mouseAttacher(int ,int ,int ,int ,void *);
        void Mouse(int ,int ,int ,int);
};

#endif // MAP_HPP