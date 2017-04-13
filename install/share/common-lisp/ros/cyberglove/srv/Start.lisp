; Auto-generated. Do not edit!


(cl:in-package cyberglove-srv)


;//! \htmlinclude Start-request.msg.html

(cl:defclass <Start-request> (roslisp-msg-protocol:ros-message)
  ((start
    :reader start
    :initarg :start
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass Start-request (<Start-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Start-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Start-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name cyberglove-srv:<Start-request> is deprecated: use cyberglove-srv:Start-request instead.")))

(cl:ensure-generic-function 'start-val :lambda-list '(m))
(cl:defmethod start-val ((m <Start-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cyberglove-srv:start-val is deprecated.  Use cyberglove-srv:start instead.")
  (start m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Start-request>) ostream)
  "Serializes a message object of type '<Start-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'start) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Start-request>) istream)
  "Deserializes a message object of type '<Start-request>"
    (cl:setf (cl:slot-value msg 'start) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Start-request>)))
  "Returns string type for a service object of type '<Start-request>"
  "cyberglove/StartRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Start-request)))
  "Returns string type for a service object of type 'Start-request"
  "cyberglove/StartRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Start-request>)))
  "Returns md5sum for a message object of type '<Start-request>"
  "749d251204872700c0771978d6a77944")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Start-request)))
  "Returns md5sum for a message object of type 'Start-request"
  "749d251204872700c0771978d6a77944")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Start-request>)))
  "Returns full string definition for message of type '<Start-request>"
  (cl:format cl:nil "bool start~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Start-request)))
  "Returns full string definition for message of type 'Start-request"
  (cl:format cl:nil "bool start~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Start-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Start-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Start-request
    (cl:cons ':start (start msg))
))
;//! \htmlinclude Start-response.msg.html

(cl:defclass <Start-response> (roslisp-msg-protocol:ros-message)
  ((state
    :reader state
    :initarg :state
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass Start-response (<Start-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Start-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Start-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name cyberglove-srv:<Start-response> is deprecated: use cyberglove-srv:Start-response instead.")))

(cl:ensure-generic-function 'state-val :lambda-list '(m))
(cl:defmethod state-val ((m <Start-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cyberglove-srv:state-val is deprecated.  Use cyberglove-srv:state instead.")
  (state m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Start-response>) ostream)
  "Serializes a message object of type '<Start-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'state) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Start-response>) istream)
  "Deserializes a message object of type '<Start-response>"
    (cl:setf (cl:slot-value msg 'state) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Start-response>)))
  "Returns string type for a service object of type '<Start-response>"
  "cyberglove/StartResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Start-response)))
  "Returns string type for a service object of type 'Start-response"
  "cyberglove/StartResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Start-response>)))
  "Returns md5sum for a message object of type '<Start-response>"
  "749d251204872700c0771978d6a77944")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Start-response)))
  "Returns md5sum for a message object of type 'Start-response"
  "749d251204872700c0771978d6a77944")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Start-response>)))
  "Returns full string definition for message of type '<Start-response>"
  (cl:format cl:nil "bool state~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Start-response)))
  "Returns full string definition for message of type 'Start-response"
  (cl:format cl:nil "bool state~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Start-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Start-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Start-response
    (cl:cons ':state (state msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Start)))
  'Start-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Start)))
  'Start-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Start)))
  "Returns string type for a service object of type '<Start>"
  "cyberglove/Start")