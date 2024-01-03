#ifndef SIMPLE_CPP_PYTHON_PUBLISH_SUBSCRIBE__PUBLISHER_NODE_HPP_
#define SIMPLE_CPP_PYTHON_PUBLISH_SUBSCRIBE__PUBLISHER_NODE_HPP_

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class MyPublisher : public rclcpp::Node
{
  public:
    MyPublisher() : Node("publisher_cpp"), count_(0)
    {
      publisher_ = this->create_publisher<std_msgs::msg::String>("/my_topic", 10);
      timer_ = this->create_wall_timer(
        1000ms,
        std::bind(&MyPublisher::timer_callback,
        this));
    }

  private:
    // Pointer to the timer
    rclcpp::TimerBase::SharedPtr timer_;
    // Pointer to the publisher
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;

    void timer_callback()
    {
      auto message = std_msgs::msg::String();
      message.data = "Hello, world! " + std::to_string(count_++);
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_->publish(message);
    }

};

#endif  // SIMPLE_CPP_PYTHON_PUBLISH_SUBSCRIBE__PUBLISHER_NODE_HPP_