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
        drawCityCenter();
        
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

void Country::drawCityCenter() {
    
    map.copyTo(Ccenter);
    if (flagCenter)
        circle(Ccenter, cityCenter, 8, Scalar(0, 255, 0), FILLED);
    
    imshow("RouadCreator", Ccenter);
}


void Country::Mouse(int event, int x, int y, int flags){

    // if (flagNewRoute == 1) {
        switch(event){

            case EVENT_LBUTTONDOWN :
                cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
                break;

            case EVENT_RBUTTONDOWN :
                cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
                break;

            case EVENT_MBUTTONDOWN :
                // cityCenter.push_back(Point(x,y));
                cityCenter.x = x;
                cityCenter.y = y;
                cout << "set a city center - position (" << x << ", " << y << ")" << endl;
                flagCenter = true;
                break;
        }
    // }
    // else {cout<<"Mouse Flag is Off !!"<<endl;}
    updateMap();
}

void Country::mouseAttacher(int event, int x, int y, int flags, void *data){
    Country *pointer = reinterpret_cast<Country* >(data);
    pointer -> Mouse(event, x, y, flags);
}
