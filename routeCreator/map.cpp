#include "map.hpp"

Country::Country(string address) {

    map = imread(address);
    if (map.empty()) { 
        cout<<"Error loading the map"<<endl;
    }
    namedWindow("RouadCreator", 1);
    setMouseCallback("RouadCreator", mouseAttacher, this);
    cityCenter = Point(0,0);
    updateMap();
}

Mat Country::Access() {
    return map;
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

    map.copyTo(route);
    if (flagNewRoute) {
        circle(map, Point(cityCenter.x, cityCenter.y), 8, Scalar(0, 255, 0), FILLED);
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
            cityCenter.x = x;
            cityCenter.y = y;
            routeVector.push_back(make_pair(routeID, Point(cityCenter.x, cityCenter.y)));
            cout << "RightButton position (" << x << ", " << y << ")" << endl;
        }
        else if (event == EVENT_RBUTTONDOWN){
            flagRoadLine = false;
            cityCenter.x = x;
            cityCenter.y = y;
            cout << "LeftButton position (" << x << ", " << y << ")" << endl;
        }
        else if (event == EVENT_MOUSEMOVE) {
            if (flagRoadLine == true)
                wheel.push_back(Point(x,y));
        }
        updateMap();
    }
}

void Country::mouseAttacher(int event, int x, int y, int flags, void *data){
    Country *pointer = reinterpret_cast<Country* >(data);
    pointer -> Mouse(event, x, y, flags);
}
