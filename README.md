# mowito_turtlebot

All the mowito launch files have been put into a package named mowito_turtlebot. The remaining turtlebot files are for the turtlebot_3 descrption,urdf etc. 

## setting it up

Setup the mowito's packages from this link
https://mowito-navstack.readthedocs.io/en/latest/Installation.html

create catkin workspace clone the repo and build it.

```
source /opt/ros/melodic/setup.bash
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
git clone https://github.com/akshay-antony/turtle_mowito.git 
cd ~/catkin_ws
rosdep install --from-paths src --ignore-src -r -y
catkin_make
```

## **For mapping (don't forget to source the files)**
```
export TURTLEBOT3_MODEL=waffle_pi 

roslaunch turtlebot3_gazebo turtlebot3_world.launch 
```
In a new terminal
```

export TURTLEBOT3_MODEL=waffle_pi 

roslaunch mowito_turtlebot turtle_mowito_mapping.launch  
```
In a new terminal
```

roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch  
```
## For navigation with known map(close all previous terminals) 
```
export TURTLEBOT3_MODEL=waffle_pi 

roslaunch turtlebot3_gazebo turtlebot3_world.launch 
```
In a new terminal
```
export TURTLEBOT3_MODEL=waffle_pi 

roslaunch mowito_turtlebot turtle_mowito_nav_map.launch
```
## For exploration(not working corrctly now, close all previous terminals)
```
export TURTLEBOT3_MODEL=waffle_pi 

roslaunch turtlebot3_gazebo turtlebot3_world.launch 
```
In a new terminal
```

export TURTLEBOT3_MODEL=waffle_pi 

roslaunch mowito_turtlebot turtle_mowito_exploration.launch 
```



