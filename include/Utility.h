#ifndef UTILITY_H_
#define UTILITY_H_

#include "ros/ros.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <nav_msgs/Path.h>
#include <string>

#define PATH_TXT "/home/yyj/path_map.txt"

struct Point
{
    double x;
    double y;

    Point()
    {
        x = 0.0;
        y = 0.0;
    }

    Point(double x_, double y_)
    {
        x = x_;
        y = y_;
    }
};

#endif