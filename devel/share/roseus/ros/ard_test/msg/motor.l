;; Auto-generated. Do not edit!


(when (boundp 'ard_test::motor)
  (if (not (find-package "ARD_TEST"))
    (make-package "ARD_TEST"))
  (shadow 'motor (find-package "ARD_TEST")))
(unless (find-package "ARD_TEST::MOTOR")
  (make-package "ARD_TEST::MOTOR"))

(in-package "ROS")
;;//! \htmlinclude motor.msg.html


(defclass ard_test::motor
  :super ros::object
  :slots (_state ))

(defmethod ard_test::motor
  (:init
   (&key
    ((:state __state) 0)
    )
   (send-super :init)
   (setq _state (round __state))
   self)
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:serialization-length
   ()
   (+
    ;; int32 _state
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _state
       (write-long _state s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _state
     (setq _state (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get ard_test::motor :md5sum-) "7a2f37ef2ba405f0c7a15cc72663d6f0")
(setf (get ard_test::motor :datatype-) "ard_test/motor")
(setf (get ard_test::motor :definition-)
      "int32 state

")



(provide :ard_test/motor "7a2f37ef2ba405f0c7a15cc72663d6f0")


