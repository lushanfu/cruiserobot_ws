
(cl:in-package :asdf)

(defsystem "robotrun-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "op_arm" :depends-on ("_package_op_arm"))
    (:file "_package_op_arm" :depends-on ("_package"))
  ))