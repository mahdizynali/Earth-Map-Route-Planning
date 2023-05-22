#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include <chrono>
#include <cmath>
#include <thread>
// #include <map>

using namespace std;
using namespace cv;
using namespace chrono;
using namespace this_thread;

class Country {

    private:
        int routeID = 1;
        Mat map;
        Mat route; 
        bool flagRoadLine = false;
        int flagNewRoute = -1;
        Point tmp;
        Point cityCenter;
        vector <Point> wheel;
        vector <pair<int, Point>> routeVector;

    public:
        Country(string);
        Mat Access();
        int updateMap();
        void drawRoutes();
        static void mouseAttacher(int ,int ,int ,int ,void *);
        void Mouse(int ,int ,int ,int);
};

#endif // MAP_HPP