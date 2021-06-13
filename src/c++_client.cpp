#include <ros/ros.h>
#include <std_srvs/SetBool.h>
#include <iostream>

using namespace::std;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "c++_client");
    ros::NodeHandle nh;
    
    //ros::ServiceServer service = nh.advertiseService("service_call", serviceCallback);
    ros::ServiceClient client = nh.serviceClient<std_srvs::SetBool>("service_call");
    ROS_INFO("!?");
    std_srvs::SetBoolResponse response;
    std_srvs::SetBoolRequest request;
    //auto srvs = client.call(response,request);
        if(client.call(response,request))
    {
        ROS_INFO("hikamani");
    }
    else
    {
        ROS_ERROR("Failed");
    }
    ros::spin();

    return 0;
}
  