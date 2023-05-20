#include "map.hpp"

Iran::Iran() {

    Mat map = imread("/home/maximum/Desktop/Iran-Map-Route-Planning/Iran.png");
    if (map.empty()) { 
        cout<<"Error loading the map"<<endl;
        return -1; 
    }
}

Mat Iran::Access() {
    return map;
}

void Iran::updateMap() {
    imshow("RouadCreator", map);
    waitKey(10);
}

void Iran::drawCityCenter() {
    const int width = 10;
    const int height = 10;
    if (flagCenter)
        rectangle(iran.Access(), Point(cityCenter[0].x, cityCenter[0].y), Point(cityCenter[0].x+width, cityCenter[0].y+height),
        Scalar(0, 255, 0),1, LINE_8);
}

void Iran::mouseAttacher(int event, int x, int y, int flags, void *data){
    Iran *pointer = reinterpret_cast<Iran* >(data);
    pointer -> Mouse(event, x, y, flags);
}

void Iran::Mouse(int event, int x, int y, int flags){

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
    updateMap();
}