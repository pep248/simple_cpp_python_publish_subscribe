#include <simple_cpp_python_publish_subscribe/subscriber_class.hpp>

int main(int argc, char *argv[]) 
{
  rclcpp::init(argc, argv);

  // Create an instance of your custom subscriber class
  auto my_subscriber = std::make_shared<MySubscriber>();

  // Create an executor and add the subscriber to it
  auto executor = std::make_shared<rclcpp::executors::SingleThreadedExecutor>();
  executor->add_node(my_subscriber);

  // Spin the executor
  executor->spin();

  rclcpp::shutdown();
  return 0;
}