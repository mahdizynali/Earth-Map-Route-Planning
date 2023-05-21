#include "map.hpp"

Country::Country(string address) {

    map = imread(address);
    if (map.empty()) { 
        cout<<"Error loading the map"<<endl;
    }
    namedWindow("RouadCreator", 1);
    setMouseCallback("RouadCreator", mouseAttacher, this);
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

            // case (int('m')):
            //     flagNewRoute *= -1;
            //     break;

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
    Point tmp;
    tmp = cityCenter;
    map.copyTo(roads);
    if (flagRoads) {
        circle(roads, cityCenter, 8, Scalar(0, 255, 0), FILLED);
        for(int i=0; i<wheel.size(); i++){
            // circle(roads, wheel[i], 3, Scalar(255, 0, 0), FILLED);
            line(roads, tmp, wheel[i], Scalar(255, 0, 0),3, LINE_8);
            tmp = wheel[i];
        }
    }
    
    imshow("RouadCreator", roads);
}


void Country::Mouse(int event, int x, int y, int flags){

    // if (flagNewRoute == 1) {
    
    mousePoint.x = x;
    mousePoint.y = y;
    if (event == EVENT_LBUTTONDOWN){
        cityCenter.x = x;
        cityCenter.y = y;
        flagRoads = true;
        cout << "position (" << x << ", " << y << ")" << endl;
    }
    else if (event == EVENT_RBUTTONDOWN){
        flagRoads = false;
        cout << "position (" << x << ", " << y << ")" << endl;
    }
    else if (event == EVENT_MOUSEMOVE) {
        if (flagRoads == true)
            wheel.push_back(Point(x,y));
    }
        // switch(event){

        //     case EVENT_LBUTTONDOWN :
        //         mousePoint.x = x;
        //         mousePoint.y = y;
        //         flagRoads = true;
        //         cout << "position (" << x << ", " << y << ")" << endl;
        //         break;

        //     case EVENT_RBUTTONDOWN :
        //         cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
        //         break;

        //     case EVENT_MBUTTONDOWN :
        //         cout << "set a city center - position (" << x << ", " << y << ")" << endl;
        //         break;

        //     case EVENT_MOUSEMOVE :
        //         cout << "wheel - position (" << x << ", " << y << ")" << endl;
        //         break;
        // }
    // }
    // else {cout<<"Mouse Flag is Off !!"<<endl;}
    updateMap();
}

void Country::mouseAttacher(int event, int x, int y, int flags, void *data){
    Country *pointer = reinterpret_cast<Country* >(data);
    pointer -> Mouse(event, x, y, flags);
}
