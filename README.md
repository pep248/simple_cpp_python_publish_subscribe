# simple_cpp_python_publish_subscribe
This repo provides and example of a minimal hybrid C++ Python publish-subscribe package working with ROS2 distributions.

Here you can find the commands to run both the C++ and the Python nodes.
Do remember that you can combine a publisher and a subscriber from C++ and python indistinctly. 

## C++

The ROS2 nodes can be found inside the ´src/´ folder while the publisher and subscriber classes can be found in the ´include/simple_cpp_python_publish_subscribe/´ folder.

They can be both run using the following command to execute the launchfile:
```
ros2 launch simple_cpp_python_publish_subscribe minimal_cpp_launch. Launch. Py 
```

Or they can manually execute in different terminals using the following commands:
```
# publisher
ros2 run simple_cpp_python_publish_subscribe publisher_cpp
# subscriber
ros2 run simple_cpp_python_publish_subscribe subscriber_cpp
```


## Python

The ROS2 nodes can be found inside the ´script/´ folder while the publisher and subscriber classes can be found in the ´simple_cpp_python_publish_subscribe/src/´ folder.

They can be both run using the following command to execute the launchfile:
```
ros2 launch simple_cpp_python_publish_subscribe minimal_py_launch.launch.py 
```

Or they can manually executed in different termianls using the following commands:
```
# publisher
ros2 run simple_cpp_python_publish_subscribe publisher.py 
# subscriber
ros2 run simple_cpp_python_publish_subscribe subscriber.py
```



