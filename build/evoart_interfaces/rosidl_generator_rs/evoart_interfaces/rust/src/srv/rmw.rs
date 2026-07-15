#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "evoart_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__evoart_interfaces__srv__StartPark_Request() -> *const std::ffi::c_void;
}

#[link(name = "evoart_interfaces__rosidl_generator_c")]
extern "C" {
    fn evoart_interfaces__srv__StartPark_Request__init(msg: *mut StartPark_Request) -> bool;
    fn evoart_interfaces__srv__StartPark_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<StartPark_Request>, size: usize) -> bool;
    fn evoart_interfaces__srv__StartPark_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<StartPark_Request>);
    fn evoart_interfaces__srv__StartPark_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<StartPark_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<StartPark_Request>) -> bool;
}

// Corresponds to evoart_interfaces__srv__StartPark_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StartPark_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub parking_slot_number: i8,

}



impl Default for StartPark_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !evoart_interfaces__srv__StartPark_Request__init(&mut msg as *mut _) {
        panic!("Call to evoart_interfaces__srv__StartPark_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for StartPark_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { evoart_interfaces__srv__StartPark_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { evoart_interfaces__srv__StartPark_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { evoart_interfaces__srv__StartPark_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for StartPark_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for StartPark_Request where Self: Sized {
  const TYPE_NAME: &'static str = "evoart_interfaces/srv/StartPark_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__evoart_interfaces__srv__StartPark_Request() }
  }
}


#[link(name = "evoart_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__evoart_interfaces__srv__StartPark_Response() -> *const std::ffi::c_void;
}

#[link(name = "evoart_interfaces__rosidl_generator_c")]
extern "C" {
    fn evoart_interfaces__srv__StartPark_Response__init(msg: *mut StartPark_Response) -> bool;
    fn evoart_interfaces__srv__StartPark_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<StartPark_Response>, size: usize) -> bool;
    fn evoart_interfaces__srv__StartPark_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<StartPark_Response>);
    fn evoart_interfaces__srv__StartPark_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<StartPark_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<StartPark_Response>) -> bool;
}

// Corresponds to evoart_interfaces__srv__StartPark_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StartPark_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for StartPark_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !evoart_interfaces__srv__StartPark_Response__init(&mut msg as *mut _) {
        panic!("Call to evoart_interfaces__srv__StartPark_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for StartPark_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { evoart_interfaces__srv__StartPark_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { evoart_interfaces__srv__StartPark_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { evoart_interfaces__srv__StartPark_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for StartPark_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for StartPark_Response where Self: Sized {
  const TYPE_NAME: &'static str = "evoart_interfaces/srv/StartPark_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__evoart_interfaces__srv__StartPark_Response() }
  }
}






#[link(name = "evoart_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__evoart_interfaces__srv__StartPark() -> *const std::ffi::c_void;
}

// Corresponds to evoart_interfaces__srv__StartPark
#[allow(missing_docs, non_camel_case_types)]
pub struct StartPark;

impl rosidl_runtime_rs::Service for StartPark {
    type Request = StartPark_Request;
    type Response = StartPark_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__evoart_interfaces__srv__StartPark() }
    }
}


