#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to evoart_interfaces__srv__StartPark_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StartPark_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub parking_slot_number: i8,

}



impl Default for StartPark_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::StartPark_Request::default())
  }
}

impl rosidl_runtime_rs::Message for StartPark_Request {
  type RmwMsg = super::srv::rmw::StartPark_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        parking_slot_number: msg.parking_slot_number,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      parking_slot_number: msg.parking_slot_number,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      parking_slot_number: msg.parking_slot_number,
    }
  }
}


// Corresponds to evoart_interfaces__srv__StartPark_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StartPark_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for StartPark_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::StartPark_Response::default())
  }
}

impl rosidl_runtime_rs::Message for StartPark_Response {
  type RmwMsg = super::srv::rmw::StartPark_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
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


