#ifndef SIMPLE_CPP_PYTHON_PUBLISH_SUBSCRIBE__SUBSCRIBER_NODE_HPP_
#define SIMPLE_CPP_PYTHON_PUBLISH_SUBSCRIBE__SUBSCRIBER_NODE_HPP_

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
using std::placeholders::_1;

class MySubscriber : public rclcpp::Node
{
  public:
    MySubscriber()
    : Node("subscriber_cpp")
    {
      subscription_ = this->create_subscription<std_msgs::msg::String>(
      "/my_topic", 10, std::bind(&MySubscriber::topic_callback, this, _1));
    }

  private:
    void topic_callback(const std_msgs::msg::String & msg) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

#endif  // SIMPLE_CPP_PYTHON_PUBLISH_SUBSCRIBE__SUBSCRIBER_NODE_HPP_