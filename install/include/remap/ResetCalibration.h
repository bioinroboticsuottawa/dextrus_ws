// Generated by gencpp from file remap/ResetCalibration.msg
// DO NOT EDIT!


#ifndef REMAP_MESSAGE_RESETCALIBRATION_H
#define REMAP_MESSAGE_RESETCALIBRATION_H

#include <ros/service_traits.h>


#include <remap/ResetCalibrationRequest.h>
#include <remap/ResetCalibrationResponse.h>


namespace remap
{

struct ResetCalibration
{

typedef ResetCalibrationRequest Request;
typedef ResetCalibrationResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct ResetCalibration
} // namespace remap


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::remap::ResetCalibration > {
  static const char* value()
  {
    return "65b5a0f951bad2a491fc17152c517af8";
  }

  static const char* value(const ::remap::ResetCalibration&) { return value(); }
};

template<>
struct DataType< ::remap::ResetCalibration > {
  static const char* value()
  {
    return "remap/ResetCalibration";
  }

  static const char* value(const ::remap::ResetCalibration&) { return value(); }
};


// service_traits::MD5Sum< ::remap::ResetCalibrationRequest> should match 
// service_traits::MD5Sum< ::remap::ResetCalibration > 
template<>
struct MD5Sum< ::remap::ResetCalibrationRequest>
{
  static const char* value()
  {
    return MD5Sum< ::remap::ResetCalibration >::value();
  }
  static const char* value(const ::remap::ResetCalibrationRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::remap::ResetCalibrationRequest> should match 
// service_traits::DataType< ::remap::ResetCalibration > 
template<>
struct DataType< ::remap::ResetCalibrationRequest>
{
  static const char* value()
  {
    return DataType< ::remap::ResetCalibration >::value();
  }
  static const char* value(const ::remap::ResetCalibrationRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::remap::ResetCalibrationResponse> should match 
// service_traits::MD5Sum< ::remap::ResetCalibration > 
template<>
struct MD5Sum< ::remap::ResetCalibrationResponse>
{
  static const char* value()
  {
    return MD5Sum< ::remap::ResetCalibration >::value();
  }
  static const char* value(const ::remap::ResetCalibrationResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::remap::ResetCalibrationResponse> should match 
// service_traits::DataType< ::remap::ResetCalibration > 
template<>
struct DataType< ::remap::ResetCalibrationResponse>
{
  static const char* value()
  {
    return DataType< ::remap::ResetCalibration >::value();
  }
  static const char* value(const ::remap::ResetCalibrationResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // REMAP_MESSAGE_RESETCALIBRATION_H
