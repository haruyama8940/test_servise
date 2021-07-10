#!/usr/bin/env python                                                           
import rospy
from std_srvs.srv import SetBool, SetBoolResponse, SetBoolRequest

#class test_print:
    #print("class")

def callback_srv(data):
    resp = SetBoolResponse()
    req = SetBoolRequest()
    if data.data==True:
        resp.message = "called"
        resp.success = True
    else:
        resp.message = "ready"
        resp.success = False
        
    print(resp.message)
    print(req.data)
    return resp

if __name__ == "__main__":
    rospy.init_node("srv_server")
    srv = rospy.Service('service_call', SetBool, callback_srv)
    
    rospy.spin()
