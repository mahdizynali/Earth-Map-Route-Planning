#include "map.hpp"

Country::Country(string address) {

    countryMap = imread(address);
    if (ountryMap.empty()) { 
        cout<<"Error loading the map"<<endl;
    }
    namedWindow("RouadCreator", 1);
    setMouseCallback("RouadCreator", mouseAttacher, this);
    routeVector[0].push_back(Point(0,0));
    updateMap();
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

            case (int('m')):
                flagNewRoute *= -1;
                break;

            case (int('r')):
                route.release();
                break;

            case (int('q')):
                destroyAllWindows();
                return 0;
        }
    }
}

void Country::drawRoutes() {
    countryMap.copyTo(route);
    if (flagNewRoute) {
        // cout<<"r : "<<routeVector[routeID]<<endl;
        circle(countryMap, routeVector[routeID][0], 8, Scalar(0, 255, 0), FILLED);
        for(int i=0; i < (int)(wheel.size()); i++){
            line(route, tmp, wheel[i], Scalar(255, 0, 0),3, LINE_8);
            tmp = wheel[i];
        }
    }
    
    imshow("RouadCreator", route);
}


void Country::Mouse(int event, int x, int y, int flags){

    if (flagNewRoute == 1) {

        if (event == EVENT_LBUTTONDOWN){
            flagRoadLine = true;
            routeVector[routeID].push_back(Point(x, y));
            cout << "RightButton position (" << x << ", " << y << ")" << endl;
        }
        else if (event == EVENT_RBUTTONDOWN){
            flagRoadLine = false;
            routeID += 1;
            routeVector[routeID].push_back(Point(x, y));
            cout << "LeftButton position (" << x << ", " << y << ")" << endl;
        }
        else if (event == EVENT_MOUSEMOVE) {
            if (flagRoadLine == true){
                wheel.push_back(Point(x,y));
            }
        }
        updateMap();
    }
}

void Country::mouseAttacher(int event, int x, int y, int flags, void *data){
    Country *pointer = reinterpret_cast<Country* >(data);
    pointer -> Mouse(event, x, y, flags);
}
