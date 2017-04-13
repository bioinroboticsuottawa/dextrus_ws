; Auto-generated. Do not edit!


(cl:in-package cyberglove-srv)


;//! \htmlinclude Calibration-request.msg.html

(cl:defclass <Calibration-request> (roslisp-msg-protocol:ros-message)
  ((path
    :reader path
    :initarg :path
    :type cl:string
    :initform ""))
)

(cl:defclass Calibration-request (<Calibration-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Calibration-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Calibration-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name cyberglove-srv:<Calibration-request> is deprecated: use cyberglove-srv:Calibration-request instead.")))

(cl:ensure-generic-function 'path-val :lambda-list '(m))
(cl:defmethod path-val ((m <Calibration-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cyberglove-srv:path-val is deprecated.  Use cyberglove-srv:path instead.")
  (path m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Calibration-request>) ostream)
  "Serializes a message object of type '<Calibration-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'path))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'path))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Calibration-request>) istream)
  "Deserializes a message object of type '<Calibration-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'path) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'path) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Calibration-request>)))
  "Returns string type for a service object of type '<Calibration-request>"
  "cyberglove/CalibrationRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Calibration-request)))
  "Returns string type for a service object of type 'Calibration-request"
  "cyberglove/CalibrationRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Calibration-request>)))
  "Returns md5sum for a message object of type '<Calibration-request>"
  "511f6c2530f3a6205ada1f7624754c20")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Calibration-request)))
  "Returns md5sum for a message object of type 'Calibration-request"
  "511f6c2530f3a6205ada1f7624754c20")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Calibration-request>)))
  "Returns full string definition for message of type '<Calibration-request>"
  (cl:format cl:nil "string path~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Calibration-request)))
  "Returns full string definition for message of type 'Calibration-request"
  (cl:format cl:nil "string path~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Calibration-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'path))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Calibration-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Calibration-request
    (cl:cons ':path (path msg))
))
;//! \htmlinclude Calibration-response.msg.html

(cl:defclass <Calibration-response> (roslisp-msg-protocol:ros-message)
  ((state
    :reader state
    :initarg :state
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass Calibration-response (<Calibration-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Calibration-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Calibration-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name cyberglove-srv:<Calibration-response> is deprecated: use cyberglove-srv:Calibration-response instead.")))

(cl:ensure-generic-function 'state-val :lambda-list '(m))
(cl:defmethod state-val ((m <Calibration-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cyberglove-srv:state-val is deprecated.  Use cyberglove-srv:state instead.")
  (state m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Calibration-response>) ostream)
  "Serializes a message object of type '<Calibration-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'state) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Calibration-response>) istream)
  "Deserializes a message object of type '<Calibration-response>"
    (cl:setf (cl:slot-value msg 'state) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Calibration-response>)))
  "Returns string type for a service object of type '<Calibration-response>"
  "cyberglove/CalibrationResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Calibration-response)))
  "Returns string type for a service object of type 'Calibration-response"
  "cyberglove/CalibrationResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Calibration-response>)))
  "Returns md5sum for a message object of type '<Calibration-response>"
  "511f6c2530f3a6205ada1f7624754c20")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Calibration-response)))
  "Returns md5sum for a message object of type 'Calibration-response"
  "511f6c2530f3a6205ada1f7624754c20")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Calibration-response>)))
  "Returns full string definition for message of type '<Calibration-response>"
  (cl:format cl:nil "bool state~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Calibration-response)))
  "Returns full string definition for message of type 'Calibration-response"
  (cl:format cl:nil "bool state~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Calibration-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Calibration-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Calibration-response
    (cl:cons ':state (state msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Calibration)))
  'Calibration-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Calibration)))
  'Calibration-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Calibration)))
  "Returns string type for a service object of type '<Calibration>"
  "cyberglove/Calibration")