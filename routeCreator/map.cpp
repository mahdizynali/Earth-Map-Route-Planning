#include "map.hpp"

Country::Country() {

    Mat map = imread("/home/maximum/Desktop/Earth-Map-Route-Planning/Country.png");
    if (map.empty()) { 
        cout<<"Error loading the map"<<endl;
    }

    setMouseCallback("Country", mouseAttacher, this);
}

Mat Country::Access() {
    return map;
}

void Country::updateMap() {
    imshow("RouadCreator", map);
    waitKey(10);
}

void Country::drawCityCenter() {
    const int width = 10;
    const int height = 10;
    if (flagCenter)
        rectangle(map, Point(cityCenter[0].x, cityCenter[0].y), Point(cityCenter[0].x+width, cityCenter[0].y+height),
        Scalar(0, 255, 0),1, LINE_8);
}

void Country::mouseAttacher(int event, int x, int y, int flags, void *data){
    Country *pointer = reinterpret_cast<Country* >(data);
    pointer -> Mouse(event, x, y, flags);
}

void Country::Mouse(int event, int x, int y, int flags){

    if  ( event == EVENT_LBUTTONDOWN ){
        cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    else if  ( event == EVENT_RBUTTONDOWN ){
        cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    else if  ( event == EVENT_MBUTTONDOWN ){
        cityCenter.push_back(Point(x,y));
        cout << "set a city center - position (" << x << ", " << y << ")" << endl;
        flagCenter = true;
    }
    // updateMap();
}