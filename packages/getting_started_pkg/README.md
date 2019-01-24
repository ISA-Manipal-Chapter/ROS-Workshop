# What is this ?
The *getting\_started\_pkg* is the package that must be used to get started with ROS

# Table of contents
- [What is this ?](#what-is-this)
- [Table of contents](#table-of-contents)
- [Package information](#package-information)
  - [Creating the package](#creating-the-package)
  - [Simple Nodes](#simple-nodes)
    - [ArgsParser.cpp](#argsparsercpp)
    - [ArgumentParser.py](#argumentparserpy)
- [Running the nodes](#running-the-nodes)

# Package information
## Creating the package
`cd` into the _src_ folder of your workspace
```bash
cd ~/ROS_workspaces/ros_ws/src/
```
Use `catkin_create_pkg` to create the package
```bash
catkin_create_pkg getting_started_pkg roscpp rospy std_msgs
```
Then `catkin_make` the workspace
## Simple Nodes
Code inside the package
### [ArgsParser.cpp](./src/ArgsParser.cpp)
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

The, run `catkin_make` in your workspace directory

**Running it**

```bash
rosrun getting_started_pkg Args_CPP_Parser -a1 Arg1_value --argument2
```

### [ArgumentParser.py](./scripts/ArgumentParser.py)
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

