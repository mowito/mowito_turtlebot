# turtle_mowito
 
All the mowito launch files have been put into a package named mowito_files. The remaining turtlebot files are for the turtlebot_3 descrption,urdf etc. 

## **For mapping (don't forget to source the files)**
```
$ export TURTLEBOT3_MODEL=waffle_pi 

$ roslaunch turtlebot3_gazebo turtlebot3_world.launch 
```
In a new terminal
```

$ export TURTLEBOT3_MODEL=waffle_pi 

$ roslaunch mowito_files turtle_mowito_mapping.launch  
```
In a new terminal
```

$ roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch  
```
## For navigation with known map(close all previous terminals) 
```
$ export TURTLEBOT3_MODEL=waffle_pi 

$ roslaunch turtlebot3_gazebo turtlebot3_world.launch 
```
In a new terminal
```
$ export TURTLEBOT3_MODEL=waffle_pi 

$ roslaunch mowito_files turtle_mowito_nav_map.launch
```
## For exploration(not working corrctly now, close all previous terminals)
```
$ export TURTLEBOT3_MODEL=waffle_pi 

$ roslaunch turtlebot3_gazebo turtlebot3_world.launch 
```
In a new terminal
```

$ export TURTLEBOT3_MODEL=waffle_pi 

$ roslaunch mowito_files turtle_mowito_exploration.launch 
```



