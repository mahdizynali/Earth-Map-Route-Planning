#include "include/planning.hpp"

// printout vectorialized rout map
void Planner::printVector(map <int, vector<Point>> routeVector, int routeID) {
    for(int j=0; j<=routeID; j++){
        cout<<"route ID : "<<j<<endl;
        cout<<"route Points : "<<endl;
        for(int i=0; i<(int)(routeVector[j].size()); i++){
            cout<<routeVector[j][i]<<endl;
        }
        cout<<"================\n";
    }
}