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

            case (int('r')):
                flagRoadLine = false;
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

// draw city centers an routs base on mouse callback
void Country::drawRoutes() {
    countryMap.copyTo(route);
    if (flagRoadLine && flagInsideCenter == false) {
        circle(countryMap, routeVector[routeID][0], 8, Scalar(0, 255, 0), FILLED);
        line(countryMap, tmp, wheel, Scalar(255, 0, 0),3, LINE_8);
        tmp = wheel;
    } 
    imshow("RouadCreator", route);
}

// mouse intraction function that commands to draw routs
void Country::Mouse(int event, int x, int y, int flags){
    if (flagMouseCallBack == 1) {
        if (event == EVENT_LBUTTONDOWN){
            routeVector[routeID].push_back(Point(x, y));
            tmp = Point(x+1,y+1);
            wheel = Point(x,y);
            flagRoadLine = true;
        }
        else if (event == EVENT_RBUTTONDOWN){
            if (flagRoadLine == true){
                routeID += 1;
                routeVector[routeID].push_back(Point(x, y));
                flagInsideCenter = false;
                for(int i=0; i<routeID; i++){
                    double distance = sqrt(pow(routeVector[i][0].x - x, 2) + pow(routeVector[i][0].y - y, 2));
                    if(distance <= 8){
                        flagInsideCenter = true;
                        routeVector[routeID].push_back(Point(routeVector[i][0].x, routeVector[i][0].y));
                    }
                }
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
        updateMap();
    }
}

// mouse callback attacher function
void Country::mouseAttacher(int event, int x, int y, int flags, void *data){
    Country *pointer = reinterpret_cast<Country* >(data);
    pointer -> Mouse(event, x, y, flags);
}
