#include <ros/ros.h>
#include <std_srvs/SetBool.h>
#include <iostream>

using namespace::std;
bool serviceCallback(std_srvs::SetBool::Request &request, 
                     std_srvs::SetBool::Response &response)
{   
    //if(response.success==true)
    //{
        response.message = std::string("called");
        response.success = true;
        ROS_INFO("called");
    //}
    //else
    //{
    //    response.message = std::string("ready");
    //    response.success = false;
    //    ROS_INFO("ready");
    //}
    return true;
}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "c++_server");
    ros::NodeHandle nh;
    
    ros::ServiceServer service = nh.advertiseService("service_call", serviceCallback);
    ROS_INFO("!?");
    ros::spin();

    return 0;
}
  
    