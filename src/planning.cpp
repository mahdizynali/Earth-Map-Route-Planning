#include "include/planning.hpp"

// calculate the distatnce of two points
double Planner::pointDistance(const Point & p1, const Point & p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// printout vectorialized rout map
void Planner::printVector (map <pair<int, int>, vector<Point>> connectionRoutes, int routeID){
    if (connectionRoutes.empty())
        cout << "vector is empty !!\n";
    
    else {

        for (const auto& entry : connectionRoutes) {
            std::cout << "Routes ID : (" << entry.first.first << " to " << entry.first.second << ")\n";
            std::cout << "Vector Values:\n";
            for (const auto& point : entry.second) {
                std::cout << "(" << point.x << ", " << point.y << ")\n";
            }
            std::cout << "\n";
        }
    }
}

// calculate G for a-star
void Planner::calculateDistance (map <int, vector<Point>> routeVector, int routeID){
    double sum = 0;
    if (routeVector.empty())
        cout << "vector is empty !!\n";
    
    else {
        for(int i=0; i<=routeID; i++){
            for(int j=0; j<(int)(routeVector[i].size()); j++){
                if(j + 1 >= (int)(routeVector[i].size()))
                    break;   
                sum += pointDistance(routeVector[i][j], routeVector[i][j + 1]);  
            }    
        route_distance[i] = sum;
        cout<<"distance route "<<i<<" to "<<i+1<<" : "<<route_distance[i]<<endl;
        sum = 0;
        }
    } 
}