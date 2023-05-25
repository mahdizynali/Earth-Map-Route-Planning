#ifndef MAP_HPP
#define MAP_HPP

#include "config.hpp"

class Country {

    private:
        int routeID = 0;
        Mat countryMap;
        Mat route; 
        bool flagRoadLine = false;
        int flagMouseCallBack = -1;
        bool flagInsideCenter = false;
        Point tmp;
        Point wheel;
        map <int, vector<Point>> routeVector;

    public:
        Country();
        Mat Access();
        int updateMap();
        void drawRoutes();
        void printVector();
        static void mouseAttacher(int ,int ,int ,int ,void *);
        void Mouse(int ,int ,int ,int);
        void mapGenerator();
        map <int, vector<Point>> getRouteVector();
};

#endif // MAP_HPP