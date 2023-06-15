#include "include/planning.hpp"

// calculate the distatnce of two points
double Planner::pointDistance(const Point & p1, const Point & p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// initializing Connection Routes vector
void Planner::initializingConnectionRoutes(map <int, vector<Point>> routeVector, int routeID) {

    for(int i=0; i<=routeID; i++) {
        cout<<"id : "<<i<<endl;
        for(int j=0; j<(int)(routeVector[i].size()); j++){
            cout<<routeVector[i][j]<<endl;
            // connectionRoutes[make_pair(routeID, tmpID)].push_back(routeVector[routeID][i]);
        } 
        cout<<"==========\n\n";
    }

    for(int i=0; i<=routeID; i++) {
        for(int j=0; j<=routeID; j++) {
            if (routeVector[i][0] == routeVector[j].back()) {
                cout<<i<<"   "<<j<<"\n\n";
            }
        }
    }
    // // Find connections between IDs
    // map<int, vector<int>> connections;

    // for (const auto& entry : routeVector) {
    //     int id = entry.first;
    //     const vector<Point>& points = entry.second;

    //     // Iterate over other IDs
    //     for (const auto& otherEntry : routeVector) {
    //         int otherId = otherEntry.first;
    //         const vector<Point>& otherPoints = otherEntry.second;

    //         // Skip if the same ID
    //         if (id == otherId)
    //             continue;

    //         // Check if there is a connection
    //         for (const auto& point : points) {
    //             if (find(otherPoints.begin(), otherPoints.end(), point) != otherPoints.end()) {
    //                 // Connection found
    //                 connections[id].push_back(otherId);
    //                 break;
    //             }
    //         }
    //     }
    // }
    
    // // Print the connections
    // for (const auto& entry : connections) {
    //     int id = entry.first;
    //     const vector<int>& connectedIds = entry.second;

    //     cout << "ID " << id << " is connected to: ";
    //     for (int connectedId : connectedIds) {
    //         cout << connectedId << " ";
    //     }
    //     cout << endl;
    // }
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