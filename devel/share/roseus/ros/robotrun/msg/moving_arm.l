;; Auto-generated. Do not edit!


(when (boundp 'robotrun::moving_arm)
  (if (not (find-package "ROBOTRUN"))
    (make-package "ROBOTRUN"))
  (shadow 'moving_arm (find-package "ROBOTRUN")))
(unless (find-package "ROBOTRUN::MOVING_ARM")
  (make-package "ROBOTRUN::MOVING_ARM"))

(in-package "ROS")
;;//! \htmlinclude moving_arm.msg.html


(defclass robotrun::moving_arm
  :super ros::object
  :slots (_hArmBagNum _movingArmBagNum _hIOLine_1 _hIOLine_2 _vIOLine _hArmOnLineLock _hArmOnLineUnlock _hRotateAngle _speed _hTorsion _vRorateAngle _opArmDistance _stayWiresDis ))

(defmethod robotrun::moving_arm
  (:init
   (&key
    ((:hArmBagNum __hArmBagNum) 0)
    ((:movingArmBagNum __movingArmBagNum) 0)
    ((:hIOLine_1 __hIOLine_1) 0)
    ((:hIOLine_2 __hIOLine_2) 0)
    ((:vIOLine __vIOLine) 0)
    ((:hArmOnLineLock __hArmOnLineLock) 0)
    ((:hArmOnLineUnlock __hArmOnLineUnlock) 0)
    ((:hRotateAngle __hRotateAngle) 0)
    ((:speed __speed) 0)
    ((:hTorsion __hTorsion) 0)
    ((:vRorateAngle __vRorateAngle) 0)
    ((:opArmDistance __opArmDistance) 0)
    ((:stayWiresDis __stayWiresDis) 0)
    )
   (send-super :init)
   (setq _hArmBagNum (round __hArmBagNum))
   (setq _movingArmBagNum (round __movingArmBagNum))
   (setq _hIOLine_1 (round __hIOLine_1))
   (setq _hIOLine_2 (round __hIOLine_2))
   (setq _vIOLine (round __vIOLine))
   (setq _hArmOnLineLock (round __hArmOnLineLock))
   (setq _hArmOnLineUnlock (round __hArmOnLineUnlock))
   (setq _hRotateAngle (round __hRotateAngle))
   (setq _speed (round __speed))
   (setq _hTorsion (round __hTorsion))
   (setq _vRorateAngle (round __vRorateAngle))
   (setq _opArmDistance (round __opArmDistance))
   (setq _stayWiresDis (round __stayWiresDis))
   self)
  (:hArmBagNum
   (&optional __hArmBagNum)
   (if __hArmBagNum (setq _hArmBagNum __hArmBagNum)) _hArmBagNum)
  (:movingArmBagNum
   (&optional __movingArmBagNum)
   (if __movingArmBagNum (setq _movingArmBagNum __movingArmBagNum)) _movingArmBagNum)
  (:hIOLine_1
   (&optional __hIOLine_1)
   (if __hIOLine_1 (setq _hIOLine_1 __hIOLine_1)) _hIOLine_1)
  (:hIOLine_2
   (&optional __hIOLine_2)
   (if __hIOLine_2 (setq _hIOLine_2 __hIOLine_2)) _hIOLine_2)
  (:vIOLine
   (&optional __vIOLine)
   (if __vIOLine (setq _vIOLine __vIOLine)) _vIOLine)
  (:hArmOnLineLock
   (&optional __hArmOnLineLock)
   (if __hArmOnLineLock (setq _hArmOnLineLock __hArmOnLineLock)) _hArmOnLineLock)
  (:hArmOnLineUnlock
   (&optional __hArmOnLineUnlock)
   (if __hArmOnLineUnlock (setq _hArmOnLineUnlock __hArmOnLineUnlock)) _hArmOnLineUnlock)
  (:hRotateAngle
   (&optional __hRotateAngle)
   (if __hRotateAngle (setq _hRotateAngle __hRotateAngle)) _hRotateAngle)
  (:speed
   (&optional __speed)
   (if __speed (setq _speed __speed)) _speed)
  (:hTorsion
   (&optional __hTorsion)
   (if __hTorsion (setq _hTorsion __hTorsion)) _hTorsion)
  (:vRorateAngle
   (&optional __vRorateAngle)
   (if __vRorateAngle (setq _vRorateAngle __vRorateAngle)) _vRorateAngle)
  (:opArmDistance
   (&optional __opArmDistance)
   (if __opArmDistance (setq _opArmDistance __opArmDistance)) _opArmDistance)
  (:stayWiresDis
   (&optional __stayWiresDis)
   (if __stayWiresDis (setq _stayWiresDis __stayWiresDis)) _stayWiresDis)
  (:serialization-length
   ()
   (+
    ;; int64 _hArmBagNum
    8
    ;; int64 _movingArmBagNum
    8
    ;; int64 _hIOLine_1
    8
    ;; int64 _hIOLine_2
    8
    ;; int64 _vIOLine
    8
    ;; int64 _hArmOnLineLock
    8
    ;; int64 _hArmOnLineUnlock
    8
    ;; int64 _hRotateAngle
    8
    ;; int64 _speed
    8
    ;; int64 _hTorsion
    8
    ;; int64 _vRorateAngle
    8
    ;; int64 _opArmDistance
    8
    ;; int64 _stayWiresDis
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _hArmBagNum
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _hArmBagNum (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _hArmBagNum) (= (length (_hArmBagNum . bv)) 2)) ;; bignum
              (write-long (ash (elt (_hArmBagNum . bv) 0) 0) s)
              (write-long (ash (elt (_hArmBagNum . bv) 1) -1) s))
             ((and (class _hArmBagNum) (= (length (_hArmBagNum . bv)) 1)) ;; big1
              (write-long (elt (_hArmBagNum . bv) 0) s)
              (write-long (if (>= _hArmBagNum 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _hArmBagNum s)(write-long (if (>= _hArmBagNum 0) 0 #xffffffff) s)))
     ;; int64 _movingArmBagNum
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _movingArmBagNum (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _movingArmBagNum) (= (length (_movingArmBagNum . bv)) 2)) ;; bignum
              (write-long (ash (elt (_movingArmBagNum . bv) 0) 0) s)
              (write-long (ash (elt (_movingArmBagNum . bv) 1) -1) s))
             ((and (class _movingArmBagNum) (= (length (_movingArmBagNum . bv)) 1)) ;; big1
              (write-long (elt (_movingArmBagNum . bv) 0) s)
              (write-long (if (>= _movingArmBagNum 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _movingArmBagNum s)(write-long (if (>= _movingArmBagNum 0) 0 #xffffffff) s)))
     ;; int64 _hIOLine_1
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _hIOLine_1 (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _hIOLine_1) (= (length (_hIOLine_1 . bv)) 2)) ;; bignum
              (write-long (ash (elt (_hIOLine_1 . bv) 0) 0) s)
              (write-long (ash (elt (_hIOLine_1 . bv) 1) -1) s))
             ((and (class _hIOLine_1) (= (length (_hIOLine_1 . bv)) 1)) ;; big1
              (write-long (elt (_hIOLine_1 . bv) 0) s)
              (write-long (if (>= _hIOLine_1 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _hIOLine_1 s)(write-long (if (>= _hIOLine_1 0) 0 #xffffffff) s)))
     ;; int64 _hIOLine_2
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _hIOLine_2 (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _hIOLine_2) (= (length (_hIOLine_2 . bv)) 2)) ;; bignum
              (write-long (ash (elt (_hIOLine_2 . bv) 0) 0) s)
              (write-long (ash (elt (_hIOLine_2 . bv) 1) -1) s))
             ((and (class _hIOLine_2) (= (length (_hIOLine_2 . bv)) 1)) ;; big1
              (write-long (elt (_hIOLine_2 . bv) 0) s)
              (write-long (if (>= _hIOLine_2 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _hIOLine_2 s)(write-long (if (>= _hIOLine_2 0) 0 #xffffffff) s)))
     ;; int64 _vIOLine
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _vIOLine (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _vIOLine) (= (length (_vIOLine . bv)) 2)) ;; bignum
              (write-long (ash (elt (_vIOLine . bv) 0) 0) s)
              (write-long (ash (elt (_vIOLine . bv) 1) -1) s))
             ((and (class _vIOLine) (= (length (_vIOLine . bv)) 1)) ;; big1
              (write-long (elt (_vIOLine . bv) 0) s)
              (write-long (if (>= _vIOLine 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _vIOLine s)(write-long (if (>= _vIOLine 0) 0 #xffffffff) s)))
     ;; int64 _hArmOnLineLock
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _hArmOnLineLock (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _hArmOnLineLock) (= (length (_hArmOnLineLock . bv)) 2)) ;; bignum
              (write-long (ash (elt (_hArmOnLineLock . bv) 0) 0) s)
              (write-long (ash (elt (_hArmOnLineLock . bv) 1) -1) s))
             ((and (class _hArmOnLineLock) (= (length (_hArmOnLineLock . bv)) 1)) ;; big1
              (write-long (elt (_hArmOnLineLock . bv) 0) s)
              (write-long (if (>= _hArmOnLineLock 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _hArmOnLineLock s)(write-long (if (>= _hArmOnLineLock 0) 0 #xffffffff) s)))
     ;; int64 _hArmOnLineUnlock
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _hArmOnLineUnlock (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _hArmOnLineUnlock) (= (length (_hArmOnLineUnlock . bv)) 2)) ;; bignum
              (write-long (ash (elt (_hArmOnLineUnlock . bv) 0) 0) s)
              (write-long (ash (elt (_hArmOnLineUnlock . bv) 1) -1) s))
             ((and (class _hArmOnLineUnlock) (= (length (_hArmOnLineUnlock . bv)) 1)) ;; big1
              (write-long (elt (_hArmOnLineUnlock . bv) 0) s)
              (write-long (if (>= _hArmOnLineUnlock 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _hArmOnLineUnlock s)(write-long (if (>= _hArmOnLineUnlock 0) 0 #xffffffff) s)))
     ;; int64 _hRotateAngle
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _hRotateAngle (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _hRotateAngle) (= (length (_hRotateAngle . bv)) 2)) ;; bignum
              (write-long (ash (elt (_hRotateAngle . bv) 0) 0) s)
              (write-long (ash (elt (_hRotateAngle . bv) 1) -1) s))
             ((and (class _hRotateAngle) (= (length (_hRotateAngle . bv)) 1)) ;; big1
              (write-long (elt (_hRotateAngle . bv) 0) s)
              (write-long (if (>= _hRotateAngle 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _hRotateAngle s)(write-long (if (>= _hRotateAngle 0) 0 #xffffffff) s)))
     ;; int64 _speed
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _speed (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _speed) (= (length (_speed . bv)) 2)) ;; bignum
              (write-long (ash (elt (_speed . bv) 0) 0) s)
              (write-long (ash (elt (_speed . bv) 1) -1) s))
             ((and (class _speed) (= (length (_speed . bv)) 1)) ;; big1
              (write-long (elt (_speed . bv) 0) s)
              (write-long (if (>= _speed 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _speed s)(write-long (if (>= _speed 0) 0 #xffffffff) s)))
     ;; int64 _hTorsion
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _hTorsion (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _hTorsion) (= (length (_hTorsion . bv)) 2)) ;; bignum
              (write-long (ash (elt (_hTorsion . bv) 0) 0) s)
              (write-long (ash (elt (_hTorsion . bv) 1) -1) s))
             ((and (class _hTorsion) (= (length (_hTorsion . bv)) 1)) ;; big1
              (write-long (elt (_hTorsion . bv) 0) s)
              (write-long (if (>= _hTorsion 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _hTorsion s)(write-long (if (>= _hTorsion 0) 0 #xffffffff) s)))
     ;; int64 _vRorateAngle
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _vRorateAngle (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _vRorateAngle) (= (length (_vRorateAngle . bv)) 2)) ;; bignum
              (write-long (ash (elt (_vRorateAngle . bv) 0) 0) s)
              (write-long (ash (elt (_vRorateAngle . bv) 1) -1) s))
             ((and (class _vRorateAngle) (= (length (_vRorateAngle . bv)) 1)) ;; big1
              (write-long (elt (_vRorateAngle . bv) 0) s)
              (write-long (if (>= _vRorateAngle 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _vRorateAngle s)(write-long (if (>= _vRorateAngle 0) 0 #xffffffff) s)))
     ;; int64 _opArmDistance
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _opArmDistance (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _opArmDistance) (= (length (_opArmDistance . bv)) 2)) ;; bignum
              (write-long (ash (elt (_opArmDistance . bv) 0) 0) s)
              (write-long (ash (elt (_opArmDistance . bv) 1) -1) s))
             ((and (class _opArmDistance) (= (length (_opArmDistance . bv)) 1)) ;; big1
              (write-long (elt (_opArmDistance . bv) 0) s)
              (write-long (if (>= _opArmDistance 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _opArmDistance s)(write-long (if (>= _opArmDistance 0) 0 #xffffffff) s)))
     ;; int64 _stayWiresDis
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _stayWiresDis (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _stayWiresDis) (= (length (_stayWiresDis . bv)) 2)) ;; bignum
              (write-long (ash (elt (_stayWiresDis . bv) 0) 0) s)
              (write-long (ash (elt (_stayWiresDis . bv) 1) -1) s))
             ((and (class _stayWiresDis) (= (length (_stayWiresDis . bv)) 1)) ;; big1
              (write-long (elt (_stayWiresDis . bv) 0) s)
              (write-long (if (>= _stayWiresDis 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _stayWiresDis s)(write-long (if (>= _stayWiresDis 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _hArmBagNum
#+(or :alpha :irix6 :x86_64)
      (setf _hArmBagNum (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _hArmBagNum (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _movingArmBagNum
#+(or :alpha :irix6 :x86_64)
      (setf _movingArmBagNum (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _movingArmBagNum (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _hIOLine_1
#+(or :alpha :irix6 :x86_64)
      (setf _hIOLine_1 (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _hIOLine_1 (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _hIOLine_2
#+(or :alpha :irix6 :x86_64)
      (setf _hIOLine_2 (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _hIOLine_2 (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _vIOLine
#+(or :alpha :irix6 :x86_64)
      (setf _vIOLine (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _vIOLine (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _hArmOnLineLock
#+(or :alpha :irix6 :x86_64)
      (setf _hArmOnLineLock (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _hArmOnLineLock (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _hArmOnLineUnlock
#+(or :alpha :irix6 :x86_64)
      (setf _hArmOnLineUnlock (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _hArmOnLineUnlock (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _hRotateAngle
#+(or :alpha :irix6 :x86_64)
      (setf _hRotateAngle (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _hRotateAngle (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _speed
#+(or :alpha :irix6 :x86_64)
      (setf _speed (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _speed (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _hTorsion
#+(or :alpha :irix6 :x86_64)
      (setf _hTorsion (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _hTorsion (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _vRorateAngle
#+(or :alpha :irix6 :x86_64)
      (setf _vRorateAngle (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _vRorateAngle (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _opArmDistance
#+(or :alpha :irix6 :x86_64)
      (setf _opArmDistance (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _opArmDistance (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _stayWiresDis
#+(or :alpha :irix6 :x86_64)
      (setf _stayWiresDis (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _stayWiresDis (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(setf (get robotrun::moving_arm :md5sum-) "9b792f6978c8450748856eee9a6a014b")
(setf (get robotrun::moving_arm :datatype-) "robotrun/moving_arm")
(setf (get robotrun::moving_arm :definition-)
      "int64 hArmBagNum
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

")



(provide :robotrun/moving_arm "9b792f6978c8450748856eee9a6a014b")


