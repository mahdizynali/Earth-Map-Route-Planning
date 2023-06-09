#ifndef MAP_HPP
#define MAP_HPP

#include "config.hpp"
#include "planning.hpp"

class Country {

    private:
        Mat Center; 
        Mat countryMap;
        Point tmp;
        Point wheel;
        Point cityCenter[2];
        int tmpID = 1;
        int number = 0;
        int routeID = 0;
        int flagMouseCallBack = -1;
        bool flagRoadLine = false;
        bool flagCenterNumber = true;
        bool flagSelectCenter = false;
        map <int, vector<Point>> routeVector;
        Planner plr;
        

    public:
        Country();
        Mat Access();
        int updateMap();
        void drawRoutes();
        int selectCenter();
        void mapGenerator();
        void initializingConnectionRoutes();
        Point getTwoCenter();
        void Mouse(int ,int ,int ,int);
        map <int, vector<Point>> getRouteVector();
        static void mouseAttacher(int ,int ,int ,int ,void *);
};

#endif // MAP_HPP