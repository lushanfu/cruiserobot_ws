; Auto-generated. Do not edit!


(cl:in-package robotrun-srv)


;//! \htmlinclude op_arm-request.msg.html

(cl:defclass <op_arm-request> (roslisp-msg-protocol:ros-message)
  ((stopThreshold
    :reader stopThreshold
    :initarg :stopThreshold
    :type cl:integer
    :initform 0)
   (travelDirection
    :reader travelDirection
    :initarg :travelDirection
    :type cl:integer
    :initform 0))
)

(cl:defclass op_arm-request (<op_arm-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <op_arm-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'op_arm-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robotrun-srv:<op_arm-request> is deprecated: use robotrun-srv:op_arm-request instead.")))

(cl:ensure-generic-function 'stopThreshold-val :lambda-list '(m))
(cl:defmethod stopThreshold-val ((m <op_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotrun-srv:stopThreshold-val is deprecated.  Use robotrun-srv:stopThreshold instead.")
  (stopThreshold m))

(cl:ensure-generic-function 'travelDirection-val :lambda-list '(m))
(cl:defmethod travelDirection-val ((m <op_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotrun-srv:travelDirection-val is deprecated.  Use robotrun-srv:travelDirection instead.")
  (travelDirection m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <op_arm-request>) ostream)
  "Serializes a message object of type '<op_arm-request>"
  (cl:let* ((signed (cl:slot-value msg 'stopThreshold)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'travelDirection)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <op_arm-request>) istream)
  "Deserializes a message object of type '<op_arm-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'stopThreshold) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'travelDirection) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<op_arm-request>)))
  "Returns string type for a service object of type '<op_arm-request>"
  "robotrun/op_armRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'op_arm-request)))
  "Returns string type for a service object of type 'op_arm-request"
  "robotrun/op_armRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<op_arm-request>)))
  "Returns md5sum for a message object of type '<op_arm-request>"
  "1d3aaf0f5087764162ba59c4846dda0c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'op_arm-request)))
  "Returns md5sum for a message object of type 'op_arm-request"
  "1d3aaf0f5087764162ba59c4846dda0c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<op_arm-request>)))
  "Returns full string definition for message of type '<op_arm-request>"
  (cl:format cl:nil "int32 stopThreshold~%int32 travelDirection~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'op_arm-request)))
  "Returns full string definition for message of type 'op_arm-request"
  (cl:format cl:nil "int32 stopThreshold~%int32 travelDirection~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <op_arm-request>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <op_arm-request>))
  "Converts a ROS message object to a list"
  (cl:list 'op_arm-request
    (cl:cons ':stopThreshold (stopThreshold msg))
    (cl:cons ':travelDirection (travelDirection msg))
))
;//! \htmlinclude op_arm-response.msg.html

(cl:defclass <op_arm-response> (roslisp-msg-protocol:ros-message)
  ((feedmsg
    :reader feedmsg
    :initarg :feedmsg
    :type cl:string
    :initform ""))
)

(cl:defclass op_arm-response (<op_arm-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <op_arm-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'op_arm-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robotrun-srv:<op_arm-response> is deprecated: use robotrun-srv:op_arm-response instead.")))

(cl:ensure-generic-function 'feedmsg-val :lambda-list '(m))
(cl:defmethod feedmsg-val ((m <op_arm-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotrun-srv:feedmsg-val is deprecated.  Use robotrun-srv:feedmsg instead.")
  (feedmsg m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <op_arm-response>) ostream)
  "Serializes a message object of type '<op_arm-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'feedmsg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'feedmsg))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <op_arm-response>) istream)
  "Deserializes a message object of type '<op_arm-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'feedmsg) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'feedmsg) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<op_arm-response>)))
  "Returns string type for a service object of type '<op_arm-response>"
  "robotrun/op_armResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'op_arm-response)))
  "Returns string type for a service object of type 'op_arm-response"
  "robotrun/op_armResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<op_arm-response>)))
  "Returns md5sum for a message object of type '<op_arm-response>"
  "1d3aaf0f5087764162ba59c4846dda0c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'op_arm-response)))
  "Returns md5sum for a message object of type 'op_arm-response"
  "1d3aaf0f5087764162ba59c4846dda0c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<op_arm-response>)))
  "Returns full string definition for message of type '<op_arm-response>"
  (cl:format cl:nil "string feedmsg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'op_arm-response)))
  "Returns full string definition for message of type 'op_arm-response"
  (cl:format cl:nil "string feedmsg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <op_arm-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'feedmsg))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <op_arm-response>))
  "Converts a ROS message object to a list"
  (cl:list 'op_arm-response
    (cl:cons ':feedmsg (feedmsg msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'op_arm)))
  'op_arm-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'op_arm)))
  'op_arm-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'op_arm)))
  "Returns string type for a service object of type '<op_arm>"
  "robotrun/op_arm")