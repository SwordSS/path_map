#include "Utility.h"
#include "PathListener.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  PathListener path_listener;

  //path_listener.LoadPathTxt(PATH_TXT);
  ros::spin();
  return 0;
}