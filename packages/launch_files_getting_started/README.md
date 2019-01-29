# What is this ?
The *launch\_files\_getting\_started* package is to introduce you to launch files.

# Table of contents
- [What is this ?](#what-is-this)
- [Table of contents](#table-of-contents)
- [Package information](#package-information)
  - [Creating the package](#creating-the-package)
  - [Code](#code)
    - [first_launch.launch](#firstlaunchlaunch)
- [Launching the files](#launching-the-files)

# Package information
## Creating the package
`cd` into the _src_ folder of your workspace
```bash
cd ~/ROS_workspaces/ros_ws/src/
```
Use `catkin_create_pkg` to create this package
```bash
catkin_create_pkg launch_files_getting_started
```

## Code
Code inside this package
### [first_launch.launch](./launch/first_launch.launch)
This is to launch all the basic nodes in the beginner packages.

You can refer the [roslaunch/XML documentation](http://wiki.ros.org/roslaunch/XML) for detailed explanation of the tags.

Start the following nodes:
- From **getting\_started\_pkg**:
  - ArgumentParser.py
  - AllLevelDebugger
  - DebuggerAll.py
- From **simple\_subscriber\_publisher**:
  - Simple_PY_Publisher.py
  - SimpleCPP_Publisher
  - Simple_PY_Subscriber.py
  - SimpleCPP_Subscriber
- Set the following environment variables:
  - ROSCONSOLE_CONFIG_FILE: Configuration file for C++ nodes
  - ROS_PYTHON_LOG_CONFIG_FILE: Configuration file for python nodes

Save the file

# Launching the files
To launch the files, run the following command. No need to launch `roscore` priory.
```bash
roslaunch launch_files_getting_started first_launch.launch
```