#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
using namespace std;
using namespace cv;

vector <Point> roadsPoint;
vector <Point> cityCenter;

void drawRoad(){

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
    }
}

int main(int argc, char** argv)
{
    Mat img = imread("/home/maximum/Desktop/Iran-Map-Route-Planning/map.png");

    if ( img.empty() ) { 
        cout << "Error loading the image" << endl;
        return -1; 
    }

    namedWindow("RouadCreator", 1);
    setMouseCallback("RouadCreator", CallBackFunc, NULL);
    imshow("RouadCreator", img);
    waitKey(0);
    return 0;
}

