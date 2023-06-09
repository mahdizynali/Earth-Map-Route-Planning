#ifndef PLANNING_HPP
#define PLANNING_HPP

#include "config.hpp"

class Planner {

    private:
        map <int, double> route_distance;

    public :
        void printVector(map <pair<int, int>, vector<Point>>, int);
        void calculateDistance(map <int, vector<Point>>, int);
        double calculate_H();
        double pointDistance(const Point &, const Point &);
};

#endif //PLANNING_HPP