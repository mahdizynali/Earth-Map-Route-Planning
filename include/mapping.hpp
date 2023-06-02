#ifndef MAP_HPP
#define MAP_HPP

#include "config.hpp"

class Country {

    private:
        Mat Center; 
        Mat countryMap;
        Point tmp;
        Point wheel;
        Point cityCenter[2];
        int routeID = 0;
        int flagMouseCallBack = -1;
        bool flagRoadLine = false;
        bool flagSelectCenter = false;
        map <int, vector<Point>> routeVector;

    public:
        Country();
        Mat Access();
        int updateMap();
        void drawRoutes();
        void drawCityCenter();
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