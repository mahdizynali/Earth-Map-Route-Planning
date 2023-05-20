#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
using namespace std;
using namespace cv;

vector <int> roadsPoint;

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
         cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
}

int main(int argc, char** argv)
{
    Mat img = imread("/home/maximum/Desktop/Iran-Map-Route-Planning/map.png");

    if ( img.empty() ) { 
        cout << "Error loading the image" << endl;
        return -1; 
    }
    
    setMouseCallback("My Window", CallBackFunc, NULL);
    imshow("My Window", img);
    waitKey(0);
    return 0;
}

