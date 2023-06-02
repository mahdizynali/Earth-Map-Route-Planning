#include "include/mapping.hpp"

string image_address = "/home/mahdi/Desktop/Earth-Map-Route-Planning/map_image/Iran.png";

// country class constructor
Country::Country() {
    mapGenerator();
    namedWindow("RouadCreator", 1);
    setMouseCallback("RouadCreator", mouseAttacher, this);
    updateMap();
}

// read image of map from file and creat matrix
void Country::mapGenerator() {
    countryMap = imread(image_address);
    if (countryMap.empty()) { 
        cout<<"Error loading the map"<<endl;
        exit(0);
    }
}

// map matrix accessor
Mat Country::Access() {
    return countryMap;
}

// return vector of routes as a map <int, vector<Point>>
map <int, vector<Point>> Country::getRouteVector() {
    return routeVector;
}

// calculate the distatnce of two points
double Country::pointDistance(const Point & p1, const Point & p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// return two center od selected city
Point Country::getTwoCenter() {
    return * twoCenter;
}

//update displaying frame base on refresh time and listen to keyboard commands
int Country::updateMap() {
    double refreshRate = 20.0 / 1000.0;
    while (true) {
        sleep_for(milliseconds((int)refreshRate * 1000));
        drawRoutes();       
        switch (waitKey(1)){
            
            case (int('n')):
                flagMouseCallBack *= -1;
                break;

            case (int('s')):
                if (flagMouseCallBack == 1)
                    flagMouseCallBack *= -1;
                selectCenter();
                break;

            case (int('r')):
                flagRoadLine = false;
                flagSelectCenter = false;
                flagMouseCallBack *= -1;
                route.release();
                mapGenerator();
                routeID = 0;
                routeVector.clear();
                break;

            case (int('q')):
                destroyAllWindows();
                return 0;

            case (int('p')):
                printVector();
        }
    }
}

// printout vectorialized rout map
void Country::printVector() {
    for(int j=0; j<=routeID; j++){
        cout<<"route ID : "<<j<<endl;
        cout<<"route Points : "<<endl;
        for(int i=0; i<(int)(routeVector[j].size()); i++){
            cout<<routeVector[j][i]<<endl;
        }
        cout<<"================\n";
    }
}

// select two city centers in order to planning
int Country::selectCenter() {
    if (routeVector.empty()) {
        cout << "There is no any city center !!\n";
        flagSelectCenter = false;
        return 0;
    }
    flagSelectCenter = true;
    return 1;
}

// draw city centers an routs base on mouse callback
void Country::drawRoutes() {
    countryMap.copyTo(route);
    if (flagRoadLine) {
        circle(countryMap, routeVector[routeID][0], 8, Scalar(0, 255, 0), FILLED);
        line(countryMap, tmp, wheel, Scalar(255, 0, 0),3, LINE_8);
        tmp = wheel;
    } 
    imshow("RouadCreator", route);
    
}

// mouse intraction function that commands to draw routs
void Country::Mouse(int event, int x, int y, int flags){
    if (flagMouseCallBack == 1) {
        if (event == EVENT_RBUTTONDOWN){
            routeVector[routeID].push_back(Point(x, y));
            tmp = Point(x+1,y+1);
            wheel = Point(x,y);
            flagRoadLine = true;
        }
        else if (event == EVENT_LBUTTONDOWN){
            if (flagRoadLine == true){
                routeID += 1;
                for(int i=0; i<routeID; i++){
                    double distance = pointDistance(routeVector[i][0], Point(x,y));
                    if((int)distance <= 10){
                        // cout<<distance<<"  true\n";
                        routeVector[routeID].push_back(routeVector[i][0]);
                    }
                    else {
                        routeVector[routeID].push_back(Point(x, y));
                    }
                    // cout<<"route : "<<i<<"  vec : "<<routeVector[i][0]<<endl;
                }
                // cout<<"=====\n";
            }
        }
        else if (event == EVENT_MOUSEMOVE) {
            if (flagRoadLine == true){
                wheel = Point(x,y);
                routeVector[routeID].push_back(wheel);
            }
        }
        else if (event == EVENT_MBUTTONDOWN) {
            flagRoadLine = false;
            flagMouseCallBack *= -1;
        }
    }

    else if (flagSelectCenter) {
        if (event == EVENT_LBUTTONDOWN) {
            for(int j=0; j<=routeID; j++){
                double distance = pointDistance(routeVector[j][0], Point(x,y));
                route.release();
                if (distance <= 8){
                    twoCenter[0] = routeVector[j][0];
                    circle(countryMap, twoCenter[0], 9, Scalar(50, 100, 150), 3);
                }
            }
        }
        if (event == EVENT_RBUTTONDOWN) {
            for(int j=0; j<=routeID; j++){
                double distance = pointDistance(routeVector[j][0], Point(x,y));
                if (distance <= 8){
                    twoCenter[1] = routeVector[j][0];
                    circle(countryMap, twoCenter[1], 9, Scalar(0, 0, 255), 3);
                }
            }
        }
    }
    updateMap();
}

// mouse callback attacher function
void Country::mouseAttacher(int event, int x, int y, int flags, void *data){
    Country *pointer = reinterpret_cast<Country* >(data);
    pointer -> Mouse(event, x, y, flags);
}
