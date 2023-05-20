#ifndef MAP_HPP
#define MAP_HPP
#include <opencv2/opencv.hpp>

class Iran {

    private:
        Mat map;

    public:
        Iran();
        void fieldCreate();
        Mat Access();
};

#endif // MAP_HPP