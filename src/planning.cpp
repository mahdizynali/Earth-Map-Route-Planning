#include "include/planning.hpp"

// calculate the distatnce of two points
double Planner::pointDistance(const Point & p1, const Point & p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// printout vectorialized rout map
void Planner::printVector (map <int, vector<Point>> routeVector, int routeID){
    if (routeVector.empty())
        cout << "vector is empty !!\n";
    
    else {
    for(int j=0; j<=routeID; j++){
        cout<<"route ID : "<<j<<endl;
        cout<<"route Points : "<<endl;
        for(int i=0; i<(int)(routeVector[j].size()); i++){
            cout<<routeVector[j][i]<<endl;
        }
        cout<<"================\n";
    }
    }
}

// calculate G for a-star
double Planner::calculate_G (map <int, vector<Point>> routeVector, int routeID){

    if (routeVector.empty())
        cout << "vector is empty !!\n";
    
    else {
        for(int i=0; i<=routeID; i++){

        }
    } 
    return 0;
}