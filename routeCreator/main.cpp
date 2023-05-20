#include "map.hpp"

void drawRoad(const Mat &map){
    const int width = 10;
    const int height = 10;

    if (flagCenter)
        rectangle(map, Point(cityCenter[0].x, cityCenter[0].y), Point(cityCenter[0].x+width, cityCenter[0].y+height),
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
}

int main() {



    namedWindow("RouadCreator", 1);
    setMouseCallback("RouadCreator", CallBackFunc, NULL);
    drawRoad(map);
    while(true){
        imshow("RouadCreator", map);
        waitKey(1);
    }
    return 0;
}
