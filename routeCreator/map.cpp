#include "map.hpp"

string image_address = "/home/mahdi/Desktop/Earth-Map-Route-Planning/routeCreator/map_image/Iran.png";

Country::Country() {
    mapGenerator();
    namedWindow("RouadCreator", 1);
    setMouseCallback("RouadCreator", mouseAttacher, this);
    updateMap();
}

void Country::mapGenerator() {
    countryMap = imread(image_address);
    tmpMap = countryMap;
    if (countryMap.empty()) { 
        cout<<"Error loading the map"<<endl;
        exit(0);
    }
}

Mat Country::Access() {
    return countryMap;
}

int Country::updateMap() {
    
    double refreshRate = 20.0 / 1000.0;
    while (true) {
        sleep_for(milliseconds((int)refreshRate * 1000));
        drawRoutes();       
        switch (waitKey(1)){
            
            case (int('n')):
                flagNewRoute = true;
                break;

            case (int('r')):
                flagRoadLine = false;
                route.release();
                countryMap.release();
                routeID = 0;
                routeVector.clear();
                countryMap = tmpMap;
                imshow("tt", countryMap);
                waitKey(0);
                // destroyAllWindows();
                break;

            case (int('q')):
                destroyAllWindows();
                return 0;

            case (int('c')):
                checkRoutes();
        }
    }
}

void Country::checkRoutes() {

    for(int j=0; j<=routeID; j++){
        cout<<"route ID : "<<j<<endl;
        cout<<"route Points : "<<endl;
        for(int i=0; i<(int)(routeVector[j].size()); i++){
            cout<<routeVector[j][i]<<endl;
        }
        cout<<"================\n";
    }
}

void Country::drawRoutes() {

    countryMap.copyTo(route);
    if (flagRoadLine) {
        circle(countryMap, routeVector[routeID][0], 8, Scalar(0, 255, 0), FILLED);
        line(countryMap, tmp, wheel, Scalar(255, 0, 0),3, LINE_8);
        tmp = wheel;
    } 
    imshow("RouadCreator", route);
}

void Country::Mouse(int event, int x, int y, int flags){

    if (flagNewRoute == 1) {
        if (event == EVENT_LBUTTONDOWN){
            routeVector[routeID].push_back(Point(x, y));
            tmp = Point(x+1,y+1);
            wheel = Point(x,y);
            flagRoadLine = true;
        }
        else if (event == EVENT_RBUTTONDOWN){
            routeID += 1;
            routeVector[routeID].push_back(Point(x, y));
            for(int i=0; i<routeID; i++){
                double distance = sqrt(pow(routeVector[i][0].x - x, 2) + pow(routeVector[i][0].y, 2));
                if(distance <= 8){
                    routeVector[routeID].push_back(Point(routeVector[i][0].x, routeVector[i][0].y));
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
        }
        updateMap();
    }
}

void Country::mouseAttacher(int event, int x, int y, int flags, void *data){
    Country *pointer = reinterpret_cast<Country* >(data);
    pointer -> Mouse(event, x, y, flags);
}
