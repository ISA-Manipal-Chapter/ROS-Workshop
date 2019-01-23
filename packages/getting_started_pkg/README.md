# What is this ?
The *getting\_started\_pkg* is the package that must be used to get started with ROS

# Table of contents
- [What is this ?](#what-is-this)
- [Table of contents](#table-of-contents)
- [Code within the package](#code-within-the-package)
  - [Simple Nodes](#simple-nodes)
    - [ArgsParser.cpp](#argsparsercpp)
    - [ArgsParser.py](#argsparserpy)
- [Running the nodes](#running-the-nodes)

# Code within the package
## Simple Nodes
### ArgsParser.cpp
This is to publish the arguments received by the nodes during execution.

The development is done as follows:
1. Include all header files
2. Have the main function which takes arguments from the command line
3. Initialize the node using the `ros::init` function.
    - [ros::init](http://docs.ros.org/api/roscpp/html/namespaceros.html#a7f5c939b8a0548ca9057392cc78d7ecb) function documentation
4. Print information about all arguments
    - ROS_INFO_STREAM is used to print messages on the console
5. End program and return 0

After that, update the CMakeLists.txt file with the following:
1. **add_executable** to create the executable files:
    ```cpp
    add_executable(Args_CPP_Parser src/ArgsParser.cpp)
    ```
2. **target_link_libraries** to link the executable to libraries:
    ```cpp
    target_link_libraries(Args_CPP_Parser ${catkin_LIBRARIES})
    ```

**Running it**

```bash
rosrun getting_started_pkg Args_CPP_Parser -a1 Arg1_value --argument2
```

### ArgsParser.py
This is to publish the arguments received by the nodes during execution.

The development is done as follows:
1. Write the _shebang_ line: `#!/usr/bin/env python`
2. Import files
    - **rospy** for [rospy](http://docs.ros.org/melodic/api/rospy/html/) library
    - **sys** for system library
3. Initialize Node
4. Print information about the arguments passed

**Running it**

```bash
chmod a+x ArgumentParser.py
rosrun getting_started_pkg ArgumentParser.py
```

# Running the nodes
Firstly, before starting any other node, start the `roscore`
```bash
roscore
```

