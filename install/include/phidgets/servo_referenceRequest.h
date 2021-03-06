// Generated by gencpp from file phidgets/servo_referenceRequest.msg
// DO NOT EDIT!


#ifndef PHIDGETS_MESSAGE_SERVO_REFERENCEREQUEST_H
#define PHIDGETS_MESSAGE_SERVO_REFERENCEREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace phidgets
{
template <class ContainerAllocator>
struct servo_referenceRequest_
{
  typedef servo_referenceRequest_<ContainerAllocator> Type;

  servo_referenceRequest_()
    : index(0)
    , engage(false)
    , position(0.0)
    , speed(0.0)
    , acceleration(0.0)  {
    }
  servo_referenceRequest_(const ContainerAllocator& _alloc)
    : index(0)
    , engage(false)
    , position(0.0)
    , speed(0.0)
    , acceleration(0.0)  {
    }



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




  typedef boost::shared_ptr< ::phidgets::servo_referenceRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::phidgets::servo_referenceRequest_<ContainerAllocator> const> ConstPtr;

}; // struct servo_referenceRequest_

typedef ::phidgets::servo_referenceRequest_<std::allocator<void> > servo_referenceRequest;

typedef boost::shared_ptr< ::phidgets::servo_referenceRequest > servo_referenceRequestPtr;
typedef boost::shared_ptr< ::phidgets::servo_referenceRequest const> servo_referenceRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::phidgets::servo_referenceRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::phidgets::servo_referenceRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace phidgets

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'move_base_msgs': ['/opt/ros/indigo/share/move_base_msgs/cmake/../msg'], 'phidgets': ['/home/jayme/workspace/dextrus_ws/src/phidgets/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::phidgets::servo_referenceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::phidgets::servo_referenceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::phidgets::servo_referenceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::phidgets::servo_referenceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::phidgets::servo_referenceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::phidgets::servo_referenceRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::phidgets::servo_referenceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "10aec6261d178a540f640abc7e85af3d";
  }

  static const char* value(const ::phidgets::servo_referenceRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x10aec6261d178a54ULL;
  static const uint64_t static_value2 = 0x0f640abc7e85af3dULL;
};

template<class ContainerAllocator>
struct DataType< ::phidgets::servo_referenceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "phidgets/servo_referenceRequest";
  }

  static const char* value(const ::phidgets::servo_referenceRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::phidgets::servo_referenceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 index\n\
bool engage\n\
float32 position\n\
float32 speed\n\
float32 acceleration\n\
";
  }

  static const char* value(const ::phidgets::servo_referenceRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::phidgets::servo_referenceRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.index);
      stream.next(m.engage);
      stream.next(m.position);
      stream.next(m.speed);
      stream.next(m.acceleration);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct servo_referenceRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::phidgets::servo_referenceRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::phidgets::servo_referenceRequest_<ContainerAllocator>& v)
  {
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

#endif // PHIDGETS_MESSAGE_SERVO_REFERENCEREQUEST_H
