#include "map.hpp"

Iran::Iran() {

    Mat map = imread("/home/maximum/Desktop/Iran-Map-Route-Planning/map.png");
    if (map.empty()) { 
        cout<<"Error loading the map"<<endl;
        return -1; 
    }
}

Mat Iran::Access() {
    return map;
}

void Iran::updateMap() {

}


