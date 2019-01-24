# What is this ?
The *simple\_subscriber\_publisher* is the package that introduces you to the concept of subscribers and publishers in ROS

# Table of contents
- [What is this ?](#what-is-this)
- [Table of contents](#table-of-contents)
- [Package information](#package-information)
  - [Creating the package](#creating-the-package)
  - [Simple Nodes](#simple-nodes)
    - [Simple_CPP_Publisher.cpp](#simplecpppublishercpp)
    - [Simple_CPP_Subscriber.cpp](#simplecppsubscribercpp)
    - [Simple_PY_Publisher.py](#simplepypublisherpy)
    - [Simple_PY_Subscriber.py](#simplepysubscriberpy)
- [Running the nodes](#running-the-nodes)

# Package information
## Creating the package
`cd` into the _src_ folder of your workspace
```bash
cd ~/ROS_workspaces/ros_ws/src/
```
Use `catkin_create_pkg` to create this package
```bash
catkin_create_pkg simple_subscriber_publisher roscpp rospy std_msgs
```
Then `catkin_make` the workspace
## Simple Nodes
Code inside the package
### [Simple_CPP_Publisher.cpp](./src/Simple_CPP_Publisher.cpp)
The publisher node made using C++

The procedure to develop this is as follows:
1. Include the header files
    - **ros/ros.h**: For ROS
    - **std_msgs/String.h**: For strings
2. Declare and define the main function
3. Initialize the node
4. Initialize the node handler
5. Advertise the topic, telling that the node will put data there
6. In a controller manner, publish messages

After that, update the CMakeLists.txt file with following:
- Add a **add_executable** for your node.
- Add a **target_link_libraries** for your node.

Run `catkin_make` in your workspace directory.

**Running it**
```bash
rosrun simple_subscriber_publisher SimpleCPP_Publisher
```

### [Simple_CPP_Subscriber.cpp](./src/Simple_CPP_Subscriber.cpp)
The subscriber node made using C++

The procedure to develop it is as follows:
1. Include the header files
2. Define a function callback
    - This function will be accepting the received message and will be called every time a message is received.
3. Declare and define the main function
4. Initialize the node
5. Initialize the node handler
6. Create a subscriber object to the function callback.
7. Spin the node

After that, update the CMakeLists.txt file with following:
- Add a **add_executable** for your node.
- Add a **target_link_libraries** for your node.

Run `catkin_make` in your workspace directory.

**Running it**
```bash
rosrun simple_subscriber_publisher SimpleCPP_Subscriber
```

### [Simple_PY_Publisher.py](./scripts/Simple_PY_Publisher.py)
The publisher node made using Python

The procedure to develop it is as follows:
1. The _shebang_ line
2. Import the libraries
    - **rospy**: For ROS
    - **std_msgs.msg.String**: For message (could be any message type).
3. Initialize the node
4. Create a publisher object
5. Create a rate handler
6. Create a message object and assign it data
7. Publish the message object

After saving the file, make it executable
```bash
cd ~/ROS_workspaces/ros_ws/src/simple_subscriber_publisher/scripts/
chmod u+x Simple_PY_Publisher.py
```

**Running it**
```bash
rosrun simple_subscriber_publisher Simple_PY_Publisher.py
```

### [Simple_PY_Subscriber.py](./src/Simple_PY_Subscriber.py)
The subscriber node made using Python

The procedure to develop it is as follows:
1. The _shebang_ line
2. Import the libraries
3. Create the callback function
4. Initialize the node
5. Create the subscriber object
6. Spin the node

After saving the file, make it executable
```bash
cd ~/ROS_workspaces/ros_ws/src/simple_subscriber_publisher/scripts/
chmod u+x Simple_PY_Subscriber.py
```

**Running it**
```bash
rosrun simple_subscriber_publisher Simple_PY_Subscriber.py
```

# Running the nodes
Firstly, before starting any other node, start the `roscore`
```bash
roscore
```
