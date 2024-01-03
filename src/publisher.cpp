#include <simple_cpp_python_publish_subscribe/publisher_class.hpp>

int main(int argc, char *argv[]) 
{
  rclcpp::init(argc, argv);

  // Create an instance of your custom publisher class
  auto my_publisher = std::make_shared<MyPublisher>();

  // Create an executor and add the publisher to it
  auto executor = std::make_shared<rclcpp::executors::SingleThreadedExecutor>();
  executor->add_node(my_publisher);

  // Spin the executor
  executor->spin();

  rclcpp::shutdown();
  return 0;
}