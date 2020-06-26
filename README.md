# turtle_mowito

for mapping
mapping  export TURTLEBOT3_MODEL=waffle_pi 

roslaunch turtlebot3_gazebo turtlebot3_world.launch 

export TURTLEBOT3_MODEL=waffle_pi 

roslaunch turtlebot3_slam turtle_mowito_mapping.launch 

roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch  


for navigation with known map

export TURTLEBOT3_MODEL=waffle_pi 

roslaunch turtlebot3_gazebo turtlebot3_world.launch 

export TURTLEBOT3_MODEL=waffle_pi 

roslaunch turtlebot3_slam turtle_mowito_nav_map.launch 

