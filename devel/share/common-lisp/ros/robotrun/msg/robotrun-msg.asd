
(cl:in-package :asdf)

(defsystem "robotrun-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "fixed_arm" :depends-on ("_package_fixed_arm"))
    (:file "_package_fixed_arm" :depends-on ("_package"))
    (:file "img" :depends-on ("_package_img"))
    (:file "_package_img" :depends-on ("_package"))
    (:file "moving_arm" :depends-on ("_package_moving_arm"))
    (:file "_package_moving_arm" :depends-on ("_package"))
    (:file "robot_data" :depends-on ("_package_robot_data"))
    (:file "_package_robot_data" :depends-on ("_package"))
  ))