#include "map.hpp"

Country::Country(string address) {

    map = imread(address);
    if (map.empty()) { 
        cout<<"Error loading the map"<<endl;
    }
    namedWindow("RouadCreator", 1);
    setMouseCallback("RouadCreator", mouseAttacher, this);
    cityCenter.push_back(Point(0,0));
    // tmp = cityCenter.back();
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
                destroyAllWindows();
                break;

            case (int('q')):
                destroyAllWindows();
                return 0;
        }
    }
}

void Country::drawRoutes() {

    map.copyTo(roads);
    if (flagNewRoute) {
        circle(map, cityCenter.back(), 8, Scalar(0, 255, 0), FILLED);
        for(int i=0; i < (int)(wheel.size()); i++){
            line(roads, tmp, wheel[i], Scalar(255, 0, 0),3, LINE_8);
            tmp = wheel[i];
        }
    }
    
    imshow("RouadCreator", roads);
}


void Country::Mouse(int event, int x, int y, int flags){

    if (flagNewRoute == 1) {

        mousePoint.x = x;
        mousePoint.y = y;
        if (event == EVENT_LBUTTONDOWN){

            flagRoads = true;
            cityCenter.push_back(Point(x,y));
            cout << "RightButton position (" << x << ", " << y << ")" << endl;
        }
        else if (event == EVENT_RBUTTONDOWN){
            flagRoads = false;
            cityCenter.push_back(Point(x,y));
            cout << "LeftButton position (" << x << ", " << y << ")" << endl;
        }
        else if (event == EVENT_MOUSEMOVE) {
            if (flagRoads == true)
                wheel.push_back(Point(x,y));
        }
        updateMap();
    }
}

void Country::mouseAttacher(int event, int x, int y, int flags, void *data){
    Country *pointer = reinterpret_cast<Country* >(data);
    pointer -> Mouse(event, x, y, flags);
}
