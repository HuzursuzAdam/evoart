#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to velodyne_msgs__msg__VelodynePacket
/// Raw Velodyne LIDAR packet.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VelodynePacket {
    /// packet timestamp
    pub stamp: builtin_interfaces::msg::Time,

    /// packet contents
    #[cfg_attr(feature = "serde", serde(with = "serde_big_array::BigArray"))]
    pub data: [u8; 1206],

}



impl Default for VelodynePacket {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::VelodynePacket::default())
  }
}

impl rosidl_runtime_rs::Message for VelodynePacket {
  type RmwMsg = super::msg::rmw::VelodynePacket;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
        data: msg.data,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
        data: msg.data,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
      data: msg.data,
    }
  }
}


// Corresponds to velodyne_msgs__msg__VelodyneScan
/// Velodyne LIDAR scan packets.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VelodyneScan {
    /// standard ROS message header
    pub header: std_msgs::msg::Header,

    /// vector of raw packets
    pub packets: Vec<super::msg::VelodynePacket>,

}



impl Default for VelodyneScan {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::VelodyneScan::default())
  }
}

impl rosidl_runtime_rs::Message for VelodyneScan {
  type RmwMsg = super::msg::rmw::VelodyneScan;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        packets: msg.packets
          .into_iter()
          .map(|elem| super::msg::VelodynePacket::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        packets: msg.packets
          .iter()
          .map(|elem| super::msg::VelodynePacket::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      packets: msg.packets
          .into_iter()
          .map(super::msg::VelodynePacket::from_rmw_message)
          .collect(),
    }
  }
}


