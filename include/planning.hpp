#ifndef PLANNING_HPP
#define PLANNING_HPP

#include "config.hpp"

class Planner {

    private:

    public :
        void printVector(map <int, vector<Point>>, int);
        double calculate_G(map <int, vector<Point>>, int);
        double calculate_H();
        double pointDistance(const Point &, const Point &);
};

#endif //PLANNING_HPP