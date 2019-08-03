#include "ros/ros.h"
#include "my_srv_prac/my_srv.h"


bool add_three_number(my_srv_prac::my_srv::Request& req, my_srv_prac::my_srv::Response& res){
  res.sum = req.a + req.b + req.c;
  ROS_INFO("Response is %ld",(long int)res.sum);
  return true;
}


//Using my_srv instead of my_srv_Request and my_srv_Response does not work for nh.advertiseService()
/* 
bool add_three_number(my_srv_prac::my_srv srv){
  srv.response.sum = srv.request.a + srv.request.b + srv.request.c;
  ROS_INFO("Response is %ld",(long int)srv.response.sum);
  return true;
}
*/

int main(int argc, char** argv){
  ros::init(argc, argv, "my_srv_server");
  ros::NodeHandle nh;
  ros::ServiceServer server = nh.advertiseService("add_three_number_srv", add_three_number);
  ROS_INFO("A server for the service %s is set up!", "add_three_number_srv");
  ros::spin();
  return 0;
}
