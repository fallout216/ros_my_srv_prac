#include "ros/ros.h"
#include "my_srv_prac/my_srv.h"
#include <cstdlib>


int main(int argc, char** argv){
  ros::init(argc, argv, "my_srv_client");
  if (argc != 4){
    ROS_INFO("There must be three int arguments.");
    return 1;
  }
  ros::NodeHandle nh;
  ros::ServiceClient client = nh.serviceClient<my_srv_prac::my_srv>("add_three_number_srv",10);
  my_srv_prac::my_srv srv;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  srv.request.c = atoll(argv[3]);
  
  if(client.call(srv)){
    ROS_INFO("The responsed sum is %ld",(long int)srv.response.sum);
  }else{
    ROS_ERROR("The service fails to return a response.");
    return 1;
  }
  return 0;
}
