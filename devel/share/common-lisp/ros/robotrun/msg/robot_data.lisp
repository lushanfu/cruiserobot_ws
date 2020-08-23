; Auto-generated. Do not edit!


(cl:in-package robotrun-msg)


;//! \htmlinclude robot_data.msg.html

(cl:defclass <robot_data> (roslisp-msg-protocol:ros-message)
  ((movingArmData
    :reader movingArmData
    :initarg :movingArmData
    :type robotrun-msg:moving_arm
    :initform (cl:make-instance 'robotrun-msg:moving_arm))
   (fixedArmData
    :reader fixedArmData
    :initarg :fixedArmData
    :type robotrun-msg:fixed_arm
    :initform (cl:make-instance 'robotrun-msg:fixed_arm)))
)

(cl:defclass robot_data (<robot_data>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <robot_data>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'robot_data)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robotrun-msg:<robot_data> is deprecated: use robotrun-msg:robot_data instead.")))

(cl:ensure-generic-function 'movingArmData-val :lambda-list '(m))
(cl:defmethod movingArmData-val ((m <robot_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotrun-msg:movingArmData-val is deprecated.  Use robotrun-msg:movingArmData instead.")
  (movingArmData m))

(cl:ensure-generic-function 'fixedArmData-val :lambda-list '(m))
(cl:defmethod fixedArmData-val ((m <robot_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotrun-msg:fixedArmData-val is deprecated.  Use robotrun-msg:fixedArmData instead.")
  (fixedArmData m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <robot_data>) ostream)
  "Serializes a message object of type '<robot_data>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'movingArmData) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'fixedArmData) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <robot_data>) istream)
  "Deserializes a message object of type '<robot_data>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'movingArmData) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'fixedArmData) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<robot_data>)))
  "Returns string type for a message object of type '<robot_data>"
  "robotrun/robot_data")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'robot_data)))
  "Returns string type for a message object of type 'robot_data"
  "robotrun/robot_data")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<robot_data>)))
  "Returns md5sum for a message object of type '<robot_data>"
  "06f2154602946c9906cdc04acafe2b9f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'robot_data)))
  "Returns md5sum for a message object of type 'robot_data"
  "06f2154602946c9906cdc04acafe2b9f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<robot_data>)))
  "Returns full string definition for message of type '<robot_data>"
  (cl:format cl:nil "moving_arm movingArmData~%fixed_arm  fixedArmData~%================================================================================~%MSG: robotrun/moving_arm~%int64 hArmBagNum~%int64 movingArmBagNum~%int64 hIOLine_1~%int64 hIOLine_2~%int64 vIOLine~%int64 hArmOnLineLock~%int64 hArmOnLineUnlock~%int64 hRotateAngle~%int64 speed~%int64 hTorsion~%int64 vRorateAngle~%int64 opArmDistance~%int64 stayWiresDis~%~%================================================================================~%MSG: robotrun/fixed_arm~%int64 hArmBagNum~%int64 movingArmBagNum~%int64 hIOLine_1~%int64 hIOLine_2~%int64 vIOLine~%int64 hArmOnLineLock~%int64 hArmOnLineUnlock~%int64 hRotateAngle~%int64 speed~%int64 hTorsion~%int64 vRorateAngle~%int64 opArmDistance~%int64 controlCabinetBagNum~%int64 controlCabinetStayWireSensorDis~%int64 gps~%int64 batteryCapcity~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'robot_data)))
  "Returns full string definition for message of type 'robot_data"
  (cl:format cl:nil "moving_arm movingArmData~%fixed_arm  fixedArmData~%================================================================================~%MSG: robotrun/moving_arm~%int64 hArmBagNum~%int64 movingArmBagNum~%int64 hIOLine_1~%int64 hIOLine_2~%int64 vIOLine~%int64 hArmOnLineLock~%int64 hArmOnLineUnlock~%int64 hRotateAngle~%int64 speed~%int64 hTorsion~%int64 vRorateAngle~%int64 opArmDistance~%int64 stayWiresDis~%~%================================================================================~%MSG: robotrun/fixed_arm~%int64 hArmBagNum~%int64 movingArmBagNum~%int64 hIOLine_1~%int64 hIOLine_2~%int64 vIOLine~%int64 hArmOnLineLock~%int64 hArmOnLineUnlock~%int64 hRotateAngle~%int64 speed~%int64 hTorsion~%int64 vRorateAngle~%int64 opArmDistance~%int64 controlCabinetBagNum~%int64 controlCabinetStayWireSensorDis~%int64 gps~%int64 batteryCapcity~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <robot_data>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'movingArmData))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'fixedArmData))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <robot_data>))
  "Converts a ROS message object to a list"
  (cl:list 'robot_data
    (cl:cons ':movingArmData (movingArmData msg))
    (cl:cons ':fixedArmData (fixedArmData msg))
))
