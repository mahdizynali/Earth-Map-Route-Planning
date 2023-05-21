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
        imshow("RouadCreator", map);
        switch (waitKey(1)){

            case (int('m')):
                flagNewRoute *= -1;
                break;

            case (int('q')):
                destroyAllWindows();
                return 0;
        }
    }
}

void Country::drawCityCenter() {
    const int width = 10;
    const int height = 10;
    if (flagCenter)
        rectangle(map, Point(cityCenter[0].x, cityCenter[0].y), Point(cityCenter[0].x+width, cityCenter[0].y+height),
        Scalar(0, 255, 0),1, LINE_8);
}


void Country::Mouse(int event, int x, int y, int flags){

    if (flagNewRoute == 1) {
        switch(event){

            case EVENT_LBUTTONDOWN :
                cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
                break;

            case EVENT_RBUTTONDOWN :
                cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
                break;

            case EVENT_MBUTTONDOWN :
                cityCenter.push_back(Point(x,y));
                cout << "set a city center - position (" << x << ", " << y << ")" << endl;
                flagCenter = true;
                break;
        }
    }
    else {cout<<"Mouse Flag is Off !!"<<endl;}
    updateMap();
}

void Country::mouseAttacher(int event, int x, int y, int flags, void *data){
    Country *pointer = reinterpret_cast<Country* >(data);
    pointer -> Mouse(event, x, y, flags);
}
