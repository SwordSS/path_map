#include "PathListener.h"

PathListener::PathListener()
{
    path_seq = 0;
    point_vec.clear();
    is_write = false;
    path_sub = n.subscribe<nav_msgs::Path>("wheel_path", 1000, &PathListener::DataCallback,this);
}

PathListener::~PathListener()
{
    if(!is_write) return;
    output_file.open(PATH_TXT,std::ios::out);

    if(output_file.is_open())
    {
        output_file << point_vec.size() << "\n";
        for(auto menber:point_vec)
        {
            output_file << std::fixed <<menber.x<<" "<< menber.y<<"\n";
        }
    }
    output_file.close();
}

void PathListener::LoadPathTxt(std::string txt_path)
{
    input_file.open(txt_path,std::ios::in);
    point_vec.clear();
    
    std::string line_str;
    while(!input_file.eof())
    {
        getline(input_file,line_str,'\n');
        std::stringstream ss(line_str);
        while(!ss.eof())
        {
            std::string str_x;
            std::string str_y;
            ss >> str_x >> str_y;

            std::cout << "str_x : " << str_x << "str_y : "<< str_y<< std::endl;
            // Point()
            // point_vec.emplace_back();
        }
    }
}

// 接收到订阅的消息后，会进入消息回调函数
void PathListener::DataCallback(const nav_msgs::Path::ConstPtr& msg_ptr)
{
    if(msg_ptr->header.seq > path_seq)
    {
        path_seq = msg_ptr->header.seq;
        point_vec.clear();
        point_vec.resize(msg_ptr->poses.size());

        for(int i=0;i<msg_ptr->poses.size();i++)
        {
            auto position = msg_ptr->poses[i].pose.position;
            Point point(position.x,position.y);
            point_vec[i] = point;
        }

        std::cout << point_vec.size() << std::endl;
    }
}