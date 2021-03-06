// Generated by gencpp from file robotrun/robot_data.msg
// DO NOT EDIT!


#ifndef ROBOTRUN_MESSAGE_ROBOT_DATA_H
#define ROBOTRUN_MESSAGE_ROBOT_DATA_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <robotrun/moving_arm.h>
#include <robotrun/fixed_arm.h>

namespace robotrun
{
template <class ContainerAllocator>
struct robot_data_
{
  typedef robot_data_<ContainerAllocator> Type;

  robot_data_()
    : movingArmData()
    , fixedArmData()  {
    }
  robot_data_(const ContainerAllocator& _alloc)
    : movingArmData(_alloc)
    , fixedArmData(_alloc)  {
  (void)_alloc;
    }



   typedef  ::robotrun::moving_arm_<ContainerAllocator>  _movingArmData_type;
  _movingArmData_type movingArmData;

   typedef  ::robotrun::fixed_arm_<ContainerAllocator>  _fixedArmData_type;
  _fixedArmData_type fixedArmData;





  typedef boost::shared_ptr< ::robotrun::robot_data_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robotrun::robot_data_<ContainerAllocator> const> ConstPtr;

}; // struct robot_data_

typedef ::robotrun::robot_data_<std::allocator<void> > robot_data;

typedef boost::shared_ptr< ::robotrun::robot_data > robot_dataPtr;
typedef boost::shared_ptr< ::robotrun::robot_data const> robot_dataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robotrun::robot_data_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robotrun::robot_data_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace robotrun

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'robotrun': ['/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::robotrun::robot_data_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robotrun::robot_data_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robotrun::robot_data_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robotrun::robot_data_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotrun::robot_data_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotrun::robot_data_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robotrun::robot_data_<ContainerAllocator> >
{
  static const char* value()
  {
    return "06f2154602946c9906cdc04acafe2b9f";
  }

  static const char* value(const ::robotrun::robot_data_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x06f2154602946c99ULL;
  static const uint64_t static_value2 = 0x06cdc04acafe2b9fULL;
};

template<class ContainerAllocator>
struct DataType< ::robotrun::robot_data_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robotrun/robot_data";
  }

  static const char* value(const ::robotrun::robot_data_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robotrun::robot_data_<ContainerAllocator> >
{
  static const char* value()
  {
    return "moving_arm movingArmData\n\
fixed_arm  fixedArmData\n\
================================================================================\n\
MSG: robotrun/moving_arm\n\
int64 hArmBagNum\n\
int64 movingArmBagNum\n\
int64 hIOLine_1\n\
int64 hIOLine_2\n\
int64 vIOLine\n\
int64 hArmOnLineLock\n\
int64 hArmOnLineUnlock\n\
int64 hRotateAngle\n\
int64 speed\n\
int64 hTorsion\n\
int64 vRorateAngle\n\
int64 opArmDistance\n\
int64 stayWiresDis\n\
\n\
================================================================================\n\
MSG: robotrun/fixed_arm\n\
int64 hArmBagNum\n\
int64 movingArmBagNum\n\
int64 hIOLine_1\n\
int64 hIOLine_2\n\
int64 vIOLine\n\
int64 hArmOnLineLock\n\
int64 hArmOnLineUnlock\n\
int64 hRotateAngle\n\
int64 speed\n\
int64 hTorsion\n\
int64 vRorateAngle\n\
int64 opArmDistance\n\
int64 controlCabinetBagNum\n\
int64 controlCabinetStayWireSensorDis\n\
int64 gps\n\
int64 batteryCapcity\n\
\n\
";
  }

  static const char* value(const ::robotrun::robot_data_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robotrun::robot_data_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.movingArmData);
      stream.next(m.fixedArmData);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct robot_data_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robotrun::robot_data_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robotrun::robot_data_<ContainerAllocator>& v)
  {
    s << indent << "movingArmData: ";
    s << std::endl;
    Printer< ::robotrun::moving_arm_<ContainerAllocator> >::stream(s, indent + "  ", v.movingArmData);
    s << indent << "fixedArmData: ";
    s << std::endl;
    Printer< ::robotrun::fixed_arm_<ContainerAllocator> >::stream(s, indent + "  ", v.fixedArmData);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOTRUN_MESSAGE_ROBOT_DATA_H
