
(cl:in-package :asdf)

(defsystem "cyberglove-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Start" :depends-on ("_package_Start"))
    (:file "_package_Start" :depends-on ("_package"))
    (:file "Calibration" :depends-on ("_package_Calibration"))
    (:file "_package_Calibration" :depends-on ("_package"))
  ))