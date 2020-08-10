/**
 * Author : Sarthak Mittal
 * Utility node to read routes from yaml files and call the executive/set_route service
 */

#include <ros/ros.h>
#include <geometry_msgs/Pose.h>
#include "mw_msgs/SetRoute.h"
#include <yaml-cpp/yaml.h>


int main(int argc, char **argv) {
  ros::init(argc, argv, "set_route_client_node");

  if (argc != 2) {
    ROS_INFO("usage: set_route_client path/to/route/file");
    return 1;
  }

  ros::NodeHandle n;

  ros::ServiceClient client = n.serviceClient<mw_msgs::SetRoute>("mission_executive/set_route");

  // reading the yaml file
  YAML::Node route_file = YAML::LoadFile(argv[1]);

  mw_msgs::SetRoute srv;

  // setting radii and other parasm
  if (ros::param::has("/global_planner/simple_planner/radii"))
  {
    ros::param::set("/global_planner/simple_planner/radii", route_file["radii"][0].as<double>());
    double radius;
    ros::param::get("/global_planner/simple_planner/radii", radius);
    std::cout<<"[set_route_client]: radii has been set to "<<radius<<std::endl;
  } 
  else {
    std::cout <<"[set_route_client]: /global_planner/simple_planner/radii not available"<<std::endl;
  }
  // setting service request params
  srv.request.route.id = route_file["id"].as<unsigned int>();
  srv.request.route.header.stamp = ros::Time::now();
  srv.request.route.header.frame_id = "map";
  for (int i = 0; i < route_file["waypoints"].size(); i++) {
    geometry_msgs::PoseStamped pose;
    pose.header.stamp = ros::Time::now();
    pose.header.frame_id = "map";
    pose.pose.position.x = route_file["waypoints"][i][0].as<double>();
    pose.pose.position.y = route_file["waypoints"][i][1].as<double>();
    pose.pose.position.z = 0;
    srv.request.route.waypoints.push_back(pose);
  }

  if (client.call(srv)) {
    ROS_INFO("[set_route_client]: set route from '%s'", argv[1]);
  } else {
    ROS_ERROR("Failed to call service mission_executive/set_route");
    return 1;
  }

  return 0;

}
