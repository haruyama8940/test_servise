#!/usr/bin/env python
import rospy
from std_srvs.srv import SetBool
x=10
y=15

if __name__ == "__main__":
    rospy.wait_for_service('service_call')
    try:
        service_call = rospy.ServiceProxy('service_call', SetBool)
        service_call(True)
        print(x+y)
    except rospy.ServiceException, e:
        print ("Service call failed: %s" % e)