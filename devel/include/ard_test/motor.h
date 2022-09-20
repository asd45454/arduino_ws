// Generated by gencpp from file ard_test/motor.msg
// DO NOT EDIT!


#ifndef ARD_TEST_MESSAGE_MOTOR_H
#define ARD_TEST_MESSAGE_MOTOR_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ard_test
{
template <class ContainerAllocator>
struct motor_
{
  typedef motor_<ContainerAllocator> Type;

  motor_()
    : state(0)  {
    }
  motor_(const ContainerAllocator& _alloc)
    : state(0)  {
  (void)_alloc;
    }



   typedef int32_t _state_type;
  _state_type state;





  typedef boost::shared_ptr< ::ard_test::motor_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ard_test::motor_<ContainerAllocator> const> ConstPtr;

}; // struct motor_

typedef ::ard_test::motor_<std::allocator<void> > motor;

typedef boost::shared_ptr< ::ard_test::motor > motorPtr;
typedef boost::shared_ptr< ::ard_test::motor const> motorConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ard_test::motor_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ard_test::motor_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ard_test::motor_<ContainerAllocator1> & lhs, const ::ard_test::motor_<ContainerAllocator2> & rhs)
{
  return lhs.state == rhs.state;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ard_test::motor_<ContainerAllocator1> & lhs, const ::ard_test::motor_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ard_test

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::ard_test::motor_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ard_test::motor_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ard_test::motor_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ard_test::motor_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ard_test::motor_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ard_test::motor_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ard_test::motor_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7a2f37ef2ba405f0c7a15cc72663d6f0";
  }

  static const char* value(const ::ard_test::motor_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7a2f37ef2ba405f0ULL;
  static const uint64_t static_value2 = 0xc7a15cc72663d6f0ULL;
};

template<class ContainerAllocator>
struct DataType< ::ard_test::motor_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ard_test/motor";
  }

  static const char* value(const ::ard_test::motor_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ard_test::motor_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 state\n"
;
  }

  static const char* value(const ::ard_test::motor_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ard_test::motor_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.state);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct motor_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ard_test::motor_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ard_test::motor_<ContainerAllocator>& v)
  {
    s << indent << "state: ";
    Printer<int32_t>::stream(s, indent + "  ", v.state);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARD_TEST_MESSAGE_MOTOR_H
