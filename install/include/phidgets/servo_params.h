// Generated by gencpp from file phidgets/servo_params.msg
// DO NOT EDIT!


#ifndef PHIDGETS_MESSAGE_SERVO_PARAMS_H
#define PHIDGETS_MESSAGE_SERVO_PARAMS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace phidgets
{
template <class ContainerAllocator>
struct servo_params_
{
  typedef servo_params_<ContainerAllocator> Type;

  servo_params_()
    : header()
    , index(0)
    , engage(false)
    , position(0.0)
    , speed(0.0)
    , acceleration(0.0)  {
    }
  servo_params_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , index(0)
    , engage(false)
    , position(0.0)
    , speed(0.0)
    , acceleration(0.0)  {
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int32_t _index_type;
  _index_type index;

   typedef uint8_t _engage_type;
  _engage_type engage;

   typedef float _position_type;
  _position_type position;

   typedef float _speed_type;
  _speed_type speed;

   typedef float _acceleration_type;
  _acceleration_type acceleration;




  typedef boost::shared_ptr< ::phidgets::servo_params_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::phidgets::servo_params_<ContainerAllocator> const> ConstPtr;

}; // struct servo_params_

typedef ::phidgets::servo_params_<std::allocator<void> > servo_params;

typedef boost::shared_ptr< ::phidgets::servo_params > servo_paramsPtr;
typedef boost::shared_ptr< ::phidgets::servo_params const> servo_paramsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::phidgets::servo_params_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::phidgets::servo_params_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace phidgets

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'move_base_msgs': ['/opt/ros/indigo/share/move_base_msgs/cmake/../msg'], 'phidgets': ['/home/jayme/workspace/dextrus_ws/src/phidgets/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::phidgets::servo_params_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::phidgets::servo_params_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::phidgets::servo_params_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::phidgets::servo_params_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::phidgets::servo_params_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::phidgets::servo_params_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::phidgets::servo_params_<ContainerAllocator> >
{
  static const char* value()
  {
    return "024374e283ed15a7fe91b9826eb72877";
  }

  static const char* value(const ::phidgets::servo_params_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x024374e283ed15a7ULL;
  static const uint64_t static_value2 = 0xfe91b9826eb72877ULL;
};

template<class ContainerAllocator>
struct DataType< ::phidgets::servo_params_<ContainerAllocator> >
{
  static const char* value()
  {
    return "phidgets/servo_params";
  }

  static const char* value(const ::phidgets::servo_params_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::phidgets::servo_params_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
int32 index\n\
bool engage\n\
float32 position\n\
float32 speed\n\
float32 acceleration\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::phidgets::servo_params_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::phidgets::servo_params_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.index);
      stream.next(m.engage);
      stream.next(m.position);
      stream.next(m.speed);
      stream.next(m.acceleration);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct servo_params_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::phidgets::servo_params_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::phidgets::servo_params_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "index: ";
    Printer<int32_t>::stream(s, indent + "  ", v.index);
    s << indent << "engage: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.engage);
    s << indent << "position: ";
    Printer<float>::stream(s, indent + "  ", v.position);
    s << indent << "speed: ";
    Printer<float>::stream(s, indent + "  ", v.speed);
    s << indent << "acceleration: ";
    Printer<float>::stream(s, indent + "  ", v.acceleration);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PHIDGETS_MESSAGE_SERVO_PARAMS_H
