#!/usr/bin/env python
import rospy
from std_srvs.srv import SetBool, SetBoolRequest,SetBoolResponse

if __name__ == "__main__":
    rospy.wait_for_service('service_call')
    req=SetBoolRequest
    resp=SetBoolResponse
    try:
        service_call = rospy.ServiceProxy('service_call', SetBool)
        service_call(False)
        #print(x+y)
    except rospy.ServiceException, e:
        print ("Service call failed: %s" % e)
