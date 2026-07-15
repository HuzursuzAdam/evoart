#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to evoart_interfaces__msg__Obstacle
/// Engel Tipleri

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Obstacle::default())
  }
}

impl rosidl_runtime_rs::Message for Obstacle {
  type RmwMsg = super::msg::rmw::Obstacle;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        obstacle_type: msg.obstacle_type,
        distance: msg.distance,
        angle: msg.angle,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      obstacle_type: msg.obstacle_type,
      distance: msg.distance,
      angle: msg.angle,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      obstacle_type: msg.obstacle_type,
      distance: msg.distance,
      angle: msg.angle,
    }
  }
}


// Corresponds to evoart_interfaces__msg__TrafficLight
/// Işık Durumları

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TrafficLight::default())
  }
}

impl rosidl_runtime_rs::Message for TrafficLight {
  type RmwMsg = super::msg::rmw::TrafficLight;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        color: msg.color,
        confidence: msg.confidence,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      color: msg.color,
      confidence: msg.confidence,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      color: msg.color,
      confidence: msg.confidence,
    }
  }
}


// Corresponds to evoart_interfaces__msg__VehicleControl

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::VehicleControl::default())
  }
}

impl rosidl_runtime_rs::Message for VehicleControl {
  type RmwMsg = super::msg::rmw::VehicleControl;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        target_velocity: msg.target_velocity,
        steering_angle: msg.steering_angle,
        emergency_stop: msg.emergency_stop,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      target_velocity: msg.target_velocity,
      steering_angle: msg.steering_angle,
      emergency_stop: msg.emergency_stop,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      target_velocity: msg.target_velocity,
      steering_angle: msg.steering_angle,
      emergency_stop: msg.emergency_stop,
    }
  }
}


