#!/usr/bin/env python
# coding:utf-8

import rospy
from robotrun.srv import *
import sys

def client_srv(anchor):
    rospy.init_node('camera_client')
   
    rospy.wait_for_service("camera_motion")
    try:
       
        camera_client = rospy.ServiceProxy("camera_motion",camera_motion)
        resp = camera_client.call(anchor)
        rospy.loginfo("Message From server:%d"%resp.status)
    except rospy.ServiceException, e:
        rospy.logwarn("Service call failed: %s"%e)


if __name__=="__main__":
    anchor=int(sys.argv[1])
    client_srv(anchor)