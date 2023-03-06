#ifndef PATHLISTENER_H_
#define PATHLISTENER_H_

#include "Utility.h"

class PathListener
{
public:
    PathListener();
    ~PathListener();

    void LoadPathTxt(std::string txt_path);
private:
    void DataCallback(const nav_msgs::Path::ConstPtr& msg_ptr);
private:
    std::ifstream input_file;
    std::ofstream output_file;
    bool is_write;
    unsigned long path_seq;
    std::vector<Point> point_vec;
    ros::Subscriber path_sub;
    ros::NodeHandle n;
};

#endif