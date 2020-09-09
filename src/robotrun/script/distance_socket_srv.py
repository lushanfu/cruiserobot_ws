#!/usr/bin/env python
#coding=utf-8
import rospy
from robotrun.msg import  obstacle
import socket
from threading import Thread
traveldirection=1
distance=100
obstacletype=-1
def rec_socket_msg():
    global distance
    global obstacletype
    print("start listen service")
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind(('192.168.3.33',9992))
    s.listen(5)
    while True:
        sock,addr=s.accept()
        while True:
            data=sock.recv(1024)
            if not data or data.decode('utf-8')=='exit':
                break
            rec=str(data.decode("utf-8"))
            obstacletype,distance=int(rec.split(':')[0]),float(rec.split(':')[1])
            sock.send(str(traveldirection))
            rospy.sleep(0.01)
        sock.close()
    
def talker():
    global distance
    global obstacletype
    pub = rospy.Publisher('obstacle_info', obstacle , queue_size=10)
    rospy.init_node('obstacle_info_talker', anonymous=True)
    rate = rospy.Rate(1) 
    
    while not rospy.is_shutdown():
        #rospy.loginfo('Talker: obstacle: direction is:{0},distance is :{1}, obstacle type is :{2},'.format(traveldirection,distance,obstacletype))
        pub.publish(obstacle(traveldirection,distance,obstacletype))
        rate.sleep()
def param_demo():
    rospy.init_node("obstacle_param")
    rate = rospy.Rate(10)
    while(not rospy.is_shutdown()):
        #get param
        parameter1 = rospy.get_param("/obstacle_type")
        parameter2 = rospy.get_param("/distance")
        rospy.loginfo('obstacle type is = %d', parameter1)
        rospy.loginfo('distance is = %d', parameter2)
        rospy.set_param('/obstacle_type',obstacletype)
        rospy.set_param('/distance',distance)

        # #delete param
        # rospy.delete_param('/param2')

        # #set param
        # rospy.set_param('/param2',2)
        
        # #check param
        # ifparam3 = rospy.has_param('/param3')
        # if(ifparam3):
        #     rospy.loginfo('/param3 exists')
        # else:
        #     rospy.loginfo('/param3 does not exist')

        # #get all param names
        # params = rospy.get_param_names()
        # rospy.loginfo('param list: %s', params)

        rate.sleep()
if __name__ == '__main__':
    t=Thread(target=rec_socket_msg)
    t.start()
    param_demo()
 