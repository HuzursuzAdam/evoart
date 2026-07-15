#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "evoart_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__evoart_interfaces__msg__Obstacle() -> *const std::ffi::c_void;
}

#[link(name = "evoart_interfaces__rosidl_generator_c")]
extern "C" {
    fn evoart_interfaces__msg__Obstacle__init(msg: *mut Obstacle) -> bool;
    fn evoart_interfaces__msg__Obstacle__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Obstacle>, size: usize) -> bool;
    fn evoart_interfaces__msg__Obstacle__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Obstacle>);
    fn evoart_interfaces__msg__Obstacle__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Obstacle>, out_seq: *mut rosidl_runtime_rs::Sequence<Obstacle>) -> bool;
}

// Corresponds to evoart_interfaces__msg__Obstacle
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Engel Tipleri

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Obstacle {

    // This member is not documented.
    #[allow(missing_docs)]
    pub obstacle_type: i8,

    /// Metre cinsinden
    pub distance: f32,

    /// Radyan veya derece cinsinden
    pub angle: f32,

}

impl Obstacle {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TYPE_CONE: i8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TYPE_PEDESTRIAN: i8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TYPE_VEHICLE: i8 = 2;

}


impl Default for Obstacle {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !evoart_interfaces__msg__Obstacle__init(&mut msg as *mut _) {
        panic!("Call to evoart_interfaces__msg__Obstacle__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Obstacle {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { evoart_interfaces__msg__Obstacle__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { evoart_interfaces__msg__Obstacle__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { evoart_interfaces__msg__Obstacle__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Obstacle {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Obstacle where Self: Sized {
  const TYPE_NAME: &'static str = "evoart_interfaces/msg/Obstacle";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__evoart_interfaces__msg__Obstacle() }
  }
}


#[link(name = "evoart_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__evoart_interfaces__msg__TrafficLight() -> *const std::ffi::c_void;
}

#[link(name = "evoart_interfaces__rosidl_generator_c")]
extern "C" {
    fn evoart_interfaces__msg__TrafficLight__init(msg: *mut TrafficLight) -> bool;
    fn evoart_interfaces__msg__TrafficLight__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TrafficLight>, size: usize) -> bool;
    fn evoart_interfaces__msg__TrafficLight__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TrafficLight>);
    fn evoart_interfaces__msg__TrafficLight__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TrafficLight>, out_seq: *mut rosidl_runtime_rs::Sequence<TrafficLight>) -> bool;
}

// Corresponds to evoart_interfaces__msg__TrafficLight
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Işık Durumları

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrafficLight {

    // This member is not documented.
    #[allow(missing_docs)]
    pub color: i8,

    /// Yapay zekanın emin olma oranı (0.0 - 1.0)
    pub confidence: f32,

}

impl TrafficLight {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RED: i8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const GREEN: i8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const YELLOW: i8 = 2;

}


impl Default for TrafficLight {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !evoart_interfaces__msg__TrafficLight__init(&mut msg as *mut _) {
        panic!("Call to evoart_interfaces__msg__TrafficLight__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TrafficLight {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { evoart_interfaces__msg__TrafficLight__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { evoart_interfaces__msg__TrafficLight__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { evoart_interfaces__msg__TrafficLight__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TrafficLight {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TrafficLight where Self: Sized {
  const TYPE_NAME: &'static str = "evoart_interfaces/msg/TrafficLight";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__evoart_interfaces__msg__TrafficLight() }
  }
}


#[link(name = "evoart_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__evoart_interfaces__msg__VehicleControl() -> *const std::ffi::c_void;
}

#[link(name = "evoart_interfaces__rosidl_generator_c")]
extern "C" {
    fn evoart_interfaces__msg__VehicleControl__init(msg: *mut VehicleControl) -> bool;
    fn evoart_interfaces__msg__VehicleControl__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<VehicleControl>, size: usize) -> bool;
    fn evoart_interfaces__msg__VehicleControl__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<VehicleControl>);
    fn evoart_interfaces__msg__VehicleControl__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<VehicleControl>, out_seq: *mut rosidl_runtime_rs::Sequence<VehicleControl>) -> bool;
}

// Corresponds to evoart_interfaces__msg__VehicleControl
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VehicleControl {
    /// İleri/geri hedef hız (m/s)
    pub target_velocity: f32,

    /// Direksiyon açısı (Radyan)
    pub steering_angle: f32,

    /// Acil durum freni (True/False)
    pub emergency_stop: bool,

}



impl Default for VehicleControl {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !evoart_interfaces__msg__VehicleControl__init(&mut msg as *mut _) {
        panic!("Call to evoart_interfaces__msg__VehicleControl__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for VehicleControl {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { evoart_interfaces__msg__VehicleControl__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { evoart_interfaces__msg__VehicleControl__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { evoart_interfaces__msg__VehicleControl__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for VehicleControl {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for VehicleControl where Self: Sized {
  const TYPE_NAME: &'static str = "evoart_interfaces/msg/VehicleControl";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__evoart_interfaces__msg__VehicleControl() }
  }
}


