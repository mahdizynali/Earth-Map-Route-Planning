#ifndef MAP_HPP
#define MAP_HPP

#include "config.hpp"

class Country {

    private:
        Mat route; 
        Point tmp;
        Point wheel;
        Mat countryMap;
        int routeID = 0;
        Point twoCenter[2];
        bool flagRoadLine = false;
        int flagMouseCallBack = -1;
        bool flagSelectCenter = false;
        map <int, vector<Point>> routeVector;

    public:
        Country();
        Mat Access();
        int updateMap();
        void drawRoutes();
        void printVector();
        int selectCenter();
        void mapGenerator();
        Point getTwoCenter();
        void Mouse(int ,int ,int ,int);
        map <int, vector<Point>> getRouteVector();
        double pointDistance(const Point &, const Point &);
        static void mouseAttacher(int ,int ,int ,int ,void *);
};

#endif // MAP_HPP