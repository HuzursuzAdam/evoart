#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "velodyne_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__velodyne_msgs__msg__VelodynePacket() -> *const std::ffi::c_void;
}

#[link(name = "velodyne_msgs__rosidl_generator_c")]
extern "C" {
    fn velodyne_msgs__msg__VelodynePacket__init(msg: *mut VelodynePacket) -> bool;
    fn velodyne_msgs__msg__VelodynePacket__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<VelodynePacket>, size: usize) -> bool;
    fn velodyne_msgs__msg__VelodynePacket__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<VelodynePacket>);
    fn velodyne_msgs__msg__VelodynePacket__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<VelodynePacket>, out_seq: *mut rosidl_runtime_rs::Sequence<VelodynePacket>) -> bool;
}

// Corresponds to velodyne_msgs__msg__VelodynePacket
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Raw Velodyne LIDAR packet.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VelodynePacket {
    /// packet timestamp
    pub stamp: builtin_interfaces::msg::rmw::Time,

    /// packet contents
    #[cfg_attr(feature = "serde", serde(with = "serde_big_array::BigArray"))]
    pub data: [u8; 1206],

}



impl Default for VelodynePacket {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !velodyne_msgs__msg__VelodynePacket__init(&mut msg as *mut _) {
        panic!("Call to velodyne_msgs__msg__VelodynePacket__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for VelodynePacket {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { velodyne_msgs__msg__VelodynePacket__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { velodyne_msgs__msg__VelodynePacket__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { velodyne_msgs__msg__VelodynePacket__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for VelodynePacket {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for VelodynePacket where Self: Sized {
  const TYPE_NAME: &'static str = "velodyne_msgs/msg/VelodynePacket";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__velodyne_msgs__msg__VelodynePacket() }
  }
}


#[link(name = "velodyne_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__velodyne_msgs__msg__VelodyneScan() -> *const std::ffi::c_void;
}

#[link(name = "velodyne_msgs__rosidl_generator_c")]
extern "C" {
    fn velodyne_msgs__msg__VelodyneScan__init(msg: *mut VelodyneScan) -> bool;
    fn velodyne_msgs__msg__VelodyneScan__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<VelodyneScan>, size: usize) -> bool;
    fn velodyne_msgs__msg__VelodyneScan__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<VelodyneScan>);
    fn velodyne_msgs__msg__VelodyneScan__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<VelodyneScan>, out_seq: *mut rosidl_runtime_rs::Sequence<VelodyneScan>) -> bool;
}

// Corresponds to velodyne_msgs__msg__VelodyneScan
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Velodyne LIDAR scan packets.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VelodyneScan {
    /// standard ROS message header
    pub header: std_msgs::msg::rmw::Header,

    /// vector of raw packets
    pub packets: rosidl_runtime_rs::Sequence<super::super::msg::rmw::VelodynePacket>,

}



impl Default for VelodyneScan {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !velodyne_msgs__msg__VelodyneScan__init(&mut msg as *mut _) {
        panic!("Call to velodyne_msgs__msg__VelodyneScan__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for VelodyneScan {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { velodyne_msgs__msg__VelodyneScan__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { velodyne_msgs__msg__VelodyneScan__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { velodyne_msgs__msg__VelodyneScan__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for VelodyneScan {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for VelodyneScan where Self: Sized {
  const TYPE_NAME: &'static str = "velodyne_msgs/msg/VelodyneScan";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__velodyne_msgs__msg__VelodyneScan() }
  }
}


