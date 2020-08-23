;; Auto-generated. Do not edit!


(when (boundp 'robotrun::op_arm)
  (if (not (find-package "ROBOTRUN"))
    (make-package "ROBOTRUN"))
  (shadow 'op_arm (find-package "ROBOTRUN")))
(unless (find-package "ROBOTRUN::OP_ARM")
  (make-package "ROBOTRUN::OP_ARM"))
(unless (find-package "ROBOTRUN::OP_ARMREQUEST")
  (make-package "ROBOTRUN::OP_ARMREQUEST"))
(unless (find-package "ROBOTRUN::OP_ARMRESPONSE")
  (make-package "ROBOTRUN::OP_ARMRESPONSE"))

(in-package "ROS")





(defclass robotrun::op_armRequest
  :super ros::object
  :slots (_stopThreshold _travelDirection ))

(defmethod robotrun::op_armRequest
  (:init
   (&key
    ((:stopThreshold __stopThreshold) 0)
    ((:travelDirection __travelDirection) 0)
    )
   (send-super :init)
   (setq _stopThreshold (round __stopThreshold))
   (setq _travelDirection (round __travelDirection))
   self)
  (:stopThreshold
   (&optional __stopThreshold)
   (if __stopThreshold (setq _stopThreshold __stopThreshold)) _stopThreshold)
  (:travelDirection
   (&optional __travelDirection)
   (if __travelDirection (setq _travelDirection __travelDirection)) _travelDirection)
  (:serialization-length
   ()
   (+
    ;; int32 _stopThreshold
    4
    ;; int32 _travelDirection
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _stopThreshold
       (write-long _stopThreshold s)
     ;; int32 _travelDirection
       (write-long _travelDirection s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _stopThreshold
     (setq _stopThreshold (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _travelDirection
     (setq _travelDirection (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass robotrun::op_armResponse
  :super ros::object
  :slots (_feedmsg ))

(defmethod robotrun::op_armResponse
  (:init
   (&key
    ((:feedmsg __feedmsg) "")
    )
   (send-super :init)
   (setq _feedmsg (string __feedmsg))
   self)
  (:feedmsg
   (&optional __feedmsg)
   (if __feedmsg (setq _feedmsg __feedmsg)) _feedmsg)
  (:serialization-length
   ()
   (+
    ;; string _feedmsg
    4 (length _feedmsg)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _feedmsg
       (write-long (length _feedmsg) s) (princ _feedmsg s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _feedmsg
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _feedmsg (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass robotrun::op_arm
  :super ros::object
  :slots ())

(setf (get robotrun::op_arm :md5sum-) "1d3aaf0f5087764162ba59c4846dda0c")
(setf (get robotrun::op_arm :datatype-) "robotrun/op_arm")
(setf (get robotrun::op_arm :request) robotrun::op_armRequest)
(setf (get robotrun::op_arm :response) robotrun::op_armResponse)

(defmethod robotrun::op_armRequest
  (:response () (instance robotrun::op_armResponse :init)))

(setf (get robotrun::op_armRequest :md5sum-) "1d3aaf0f5087764162ba59c4846dda0c")
(setf (get robotrun::op_armRequest :datatype-) "robotrun/op_armRequest")
(setf (get robotrun::op_armRequest :definition-)
      "int32 stopThreshold
int32 travelDirection
---
string feedmsg
")

(setf (get robotrun::op_armResponse :md5sum-) "1d3aaf0f5087764162ba59c4846dda0c")
(setf (get robotrun::op_armResponse :datatype-) "robotrun/op_armResponse")
(setf (get robotrun::op_armResponse :definition-)
      "int32 stopThreshold
int32 travelDirection
---
string feedmsg
")



(provide :robotrun/op_arm "1d3aaf0f5087764162ba59c4846dda0c")


