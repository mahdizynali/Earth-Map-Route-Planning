#include "map.hpp"

Iran iran;
bool flagCenter = false;
vector <Point> roadsPoint;
vector <Point> cityCenter;

void drawRoad() {
    const int width = 10;
    const int height = 10;

    if (flagCenter)
        rectangle(iran.Access(), Point(cityCenter[0].x, cityCenter[0].y), Point(cityCenter[0].x+width, cityCenter[0].y+height),
        Scalar(0, 255, 0),1, LINE_8);
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata){

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

int main() {

    

    namedWindow("RouadCreator", 1);
    setMouseCallback("RouadCreator", CallBackFunc, NULL);
    return 0;
}
