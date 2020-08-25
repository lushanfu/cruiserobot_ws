#! /usr/bin/env python
# -*- coding: utf-8 -*-
import requests
import rospy
import json
from robotrun.srv import *

def handler_fun(req):
    anchor=req.anchor
    rospy.loginfo("request anchor postion is {0}!".format(anchor))
    data={"session":0,"id":2,"call":{"service":"rpc","method":"login"},"params":{"userName":"admin","password":"09F9CBF101CFE6760C1D3D9B6BCA064F","random":"PEN9BN","ip":"127.0.0.1","port":80}}
    url="http://192.168.3.68/SDK/UNIV_API"
    ss=requests.session()
    res = ss.post(url=url, json=data)
    if res.status_code!=200:
         req.status=-1
         return camera_motionResponse(-1)
    sessionId=json.loads(res.text)["params"]["session"]
    json1 = {"session": sessionId, "id": 2, "call": {"service": "ptz", "method": "setPresentParam"},
                     "params": {"action": "run", "preset": {"presetNum": anchor, "presetName": "预置点{0}".format(str(anchor))}}}
    res = ss.post(url=url, json=json1)
    if res.status_code!=200:
         
         return camera_motionResponse(-2)
    
    return camera_motionResponse(0)




def camera_srv():
    rospy.init_node('camera_motion_node')
    rospy.loginfo('init runtime over')
    rospy.Service("camera_motion",camera_motion,handler_fun)
    rospy.spin()

if __name__=='__main__':
    camera_srv()

