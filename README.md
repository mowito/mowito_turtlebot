# turtle_mowito

1) For mapping (don't forget to source the files)

$ export TURTLEBOT3_MODEL=waffle_pi 

$ roslaunch turtlebot3_gazebo turtlebot3_world.launch 

$ export TURTLEBOT3_MODEL=waffle_pi 

$ roslaunch turtlebot3_slam turtle_mowito_mapping.launch 

$ roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch  


2) For navigation with known map

$export TURTLEBOT3_MODEL=waffle_pi 

$ roslaunch turtlebot3_gazebo turtlebot3_world.launch 

$ export TURTLEBOT3_MODEL=waffle_pi 

$ roslaunch turtlebot3_slam turtle_mowito_nav_map.launch

3) For exploration(not working corrctly now)

$ export TURTLEBOT3_MODEL=waffle_pi 

$ roslaunch turtlebot3_gazebo turtlebot3_world.launch 

$ export TURTLEBOT3_MODEL=waffle_pi 

$ roslaunch turtlebot3_slam turtle_mowito_exploration.launch 




