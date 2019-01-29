# What is this ?
The *simple\_msg\_srv\_def* package is to show how messages and services are declared in ROS

# Table of contents
- [What is this ?](#what-is-this)
- [Table of contents](#table-of-contents)
- [Package information](#package-information)
  - [Creating the package](#creating-the-package)
  - [Code](#code)
    - [EllipseSides.msg](#ellipsesidesmsg)
    - [EllipseArea.srv](#ellipseareasrv)

# Package information
## Creating the package
`cd` into the _src_ folder of your workspace
```bash
cd ~/ROS_workspaces/ros_ws/src/
```
Use `catkin_create_pkg` to create this package
```bash
catkin_create_pkg simple_msg_srv_def message_generation message_runtime std_msgs
```
Then `catkin_make` the workspace

## Code
Code inside the package
### [EllipseSides.msg](./msg/EllipseSides.msg)
This is to hold the major and minor axis lengths of an ellipse

The development is done as follows:
1. Create the variables in this file
    ```py
        float32 a   # Minor side length
        float32 b   # Major side length
    ```

This file is made using message description language

**Building it**

Follow the following steps:
1. Un-comment the lines in the **add_message_files** function
2. Un-comment the lines in the **generate_messages** function
3. Ensure that the following is there in **package.xml**
    ```xml
    <build_depend>message_generation</build_depend>
    <exec_depend>message_runtime</exec_depend>
    ```
4. Ensure that the following is there in **CMakeLists.txt**
    ```cpp
    find_package(catkin REQUIRED COMPONENTS
        message_generation
        message_runtime
        std_msgs
    )
    ```
5. `catkin_make` the workspace
6. Observe files in the `devel` directory in the workspace, namely:
    ```bash
    ~/ROS_workspaces/ros_ws/devel/include/simple_msg_srv_def/EllipseSides.h
    ~/ROS_workspaces/ros_ws/devel/lib/python2.7/dist-packages/simple_msg_srv_def/
    ```

All the source files are stored here

### [EllipseArea.srv](./srv/EllipseArea.srv)
This is a service for finding out the area of an ellipse

The development is done as follows:
1. Create the variables in this file
    ```bash
    simple_msg_srv_def/EllipseSides sides
    ---
    float32 area
    ```

This file is made using service description language

**Building it**

Follow the following steps:
1. Un-comment the lines in the **add_service_files** function
2. Ensure that the following is there in **package.xml**
    ```xml
    <build_depend>message_generation</build_depend>
    <exec_depend>message_runtime</exec_depend>
    ```
3. Ensure that the following is there in **CMakeLists.txt**
    ```cpp
    find_package(catkin REQUIRED COMPONENTS
        message_generation
        message_runtime
        std_msgs
    )
    ```
4. `catkin_make` the workspace
5. Observe files in the `devel` directory in the workspace, namely:
    ```bash
    ~/ROS_workspaces/ros_ws/devel/include/simple_msg_srv_def/
    ~/ROS_workspaces/ros_ws/devel/lib/python2.7/dist-packages/simple_msg_srv_def/srv/
    ```

All the source files are stored in this directory

