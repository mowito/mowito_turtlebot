# turtle_mowito

## **For mapping (don't forget to source the files)**
```
$ export TURTLEBOT3_MODEL=waffle_pi 

$ roslaunch turtlebot3_gazebo turtlebot3_world.launch 
```
In a new terminal
```

$ export TURTLEBOT3_MODEL=waffle_pi 

$ roslaunch turtlebot3_slam turtle_mowito_mapping.launch 
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

$ roslaunch turtlebot3_slam turtle_mowito_nav_map.launch
```
## For exploration(not working corrctly now, close all previous terminals)
```
$ export TURTLEBOT3_MODEL=waffle_pi 

$ roslaunch turtlebot3_gazebo turtlebot3_world.launch 
```
In a new terminal
```

$ export TURTLEBOT3_MODEL=waffle_pi 

$ roslaunch turtlebot3_slam turtle_mowito_exploration.launch 
```



