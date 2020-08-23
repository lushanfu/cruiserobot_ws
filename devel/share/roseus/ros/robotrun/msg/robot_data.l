;; Auto-generated. Do not edit!


(when (boundp 'robotrun::robot_data)
  (if (not (find-package "ROBOTRUN"))
    (make-package "ROBOTRUN"))
  (shadow 'robot_data (find-package "ROBOTRUN")))
(unless (find-package "ROBOTRUN::ROBOT_DATA")
  (make-package "ROBOTRUN::ROBOT_DATA"))

(in-package "ROS")
;;//! \htmlinclude robot_data.msg.html


(defclass robotrun::robot_data
  :super ros::object
  :slots (_movingArmData _fixedArmData ))

(defmethod robotrun::robot_data
  (:init
   (&key
    ((:movingArmData __movingArmData) (instance robotrun::moving_arm :init))
    ((:fixedArmData __fixedArmData) (instance robotrun::fixed_arm :init))
    )
   (send-super :init)
   (setq _movingArmData __movingArmData)
   (setq _fixedArmData __fixedArmData)
   self)
  (:movingArmData
   (&rest __movingArmData)
   (if (keywordp (car __movingArmData))
       (send* _movingArmData __movingArmData)
     (progn
       (if __movingArmData (setq _movingArmData (car __movingArmData)))
       _movingArmData)))
  (:fixedArmData
   (&rest __fixedArmData)
   (if (keywordp (car __fixedArmData))
       (send* _fixedArmData __fixedArmData)
     (progn
       (if __fixedArmData (setq _fixedArmData (car __fixedArmData)))
       _fixedArmData)))
  (:serialization-length
   ()
   (+
    ;; robotrun/moving_arm _movingArmData
    (send _movingArmData :serialization-length)
    ;; robotrun/fixed_arm _fixedArmData
    (send _fixedArmData :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; robotrun/moving_arm _movingArmData
       (send _movingArmData :serialize s)
     ;; robotrun/fixed_arm _fixedArmData
       (send _fixedArmData :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; robotrun/moving_arm _movingArmData
     (send _movingArmData :deserialize buf ptr-) (incf ptr- (send _movingArmData :serialization-length))
   ;; robotrun/fixed_arm _fixedArmData
     (send _fixedArmData :deserialize buf ptr-) (incf ptr- (send _fixedArmData :serialization-length))
   ;;
   self)
  )

(setf (get robotrun::robot_data :md5sum-) "06f2154602946c9906cdc04acafe2b9f")
(setf (get robotrun::robot_data :datatype-) "robotrun/robot_data")
(setf (get robotrun::robot_data :definition-)
      "moving_arm movingArmData
fixed_arm  fixedArmData
================================================================================
MSG: robotrun/moving_arm
int64 hArmBagNum
int64 movingArmBagNum
int64 hIOLine_1
int64 hIOLine_2
int64 vIOLine
int64 hArmOnLineLock
int64 hArmOnLineUnlock
int64 hRotateAngle
int64 speed
int64 hTorsion
int64 vRorateAngle
int64 opArmDistance
int64 stayWiresDis

================================================================================
MSG: robotrun/fixed_arm
int64 hArmBagNum
int64 movingArmBagNum
int64 hIOLine_1
int64 hIOLine_2
int64 vIOLine
int64 hArmOnLineLock
int64 hArmOnLineUnlock
int64 hRotateAngle
int64 speed
int64 hTorsion
int64 vRorateAngle
int64 opArmDistance
int64 controlCabinetBagNum
int64 controlCabinetStayWireSensorDis
int64 gps
int64 batteryCapcity


")



(provide :robotrun/robot_data "06f2154602946c9906cdc04acafe2b9f")


