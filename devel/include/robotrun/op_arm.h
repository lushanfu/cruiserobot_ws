// Generated by gencpp from file robotrun/op_arm.msg
// DO NOT EDIT!


#ifndef ROBOTRUN_MESSAGE_OP_ARM_H
#define ROBOTRUN_MESSAGE_OP_ARM_H

#include <ros/service_traits.h>


#include <robotrun/op_armRequest.h>
#include <robotrun/op_armResponse.h>


namespace robotrun
{

struct op_arm
{

typedef op_armRequest Request;
typedef op_armResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct op_arm
} // namespace robotrun


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::robotrun::op_arm > {
  static const char* value()
  {
    return "1d3aaf0f5087764162ba59c4846dda0c";
  }

  static const char* value(const ::robotrun::op_arm&) { return value(); }
};

template<>
struct DataType< ::robotrun::op_arm > {
  static const char* value()
  {
    return "robotrun/op_arm";
  }

  static const char* value(const ::robotrun::op_arm&) { return value(); }
};


// service_traits::MD5Sum< ::robotrun::op_armRequest> should match 
// service_traits::MD5Sum< ::robotrun::op_arm > 
template<>
struct MD5Sum< ::robotrun::op_armRequest>
{
  static const char* value()
  {
    return MD5Sum< ::robotrun::op_arm >::value();
  }
  static const char* value(const ::robotrun::op_armRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::robotrun::op_armRequest> should match 
// service_traits::DataType< ::robotrun::op_arm > 
template<>
struct DataType< ::robotrun::op_armRequest>
{
  static const char* value()
  {
    return DataType< ::robotrun::op_arm >::value();
  }
  static const char* value(const ::robotrun::op_armRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::robotrun::op_armResponse> should match 
// service_traits::MD5Sum< ::robotrun::op_arm > 
template<>
struct MD5Sum< ::robotrun::op_armResponse>
{
  static const char* value()
  {
    return MD5Sum< ::robotrun::op_arm >::value();
  }
  static const char* value(const ::robotrun::op_armResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::robotrun::op_armResponse> should match 
// service_traits::DataType< ::robotrun::op_arm > 
template<>
struct DataType< ::robotrun::op_armResponse>
{
  static const char* value()
  {
    return DataType< ::robotrun::op_arm >::value();
  }
  static const char* value(const ::robotrun::op_armResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ROBOTRUN_MESSAGE_OP_ARM_H
