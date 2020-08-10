/**
 * Author : Sarthak Mittal
 * Utility node to read plans from txt files and call the executive/set_plan service
 */

#include <ros/ros.h>

#include <tf/transform_listener.h>
#include <geometry_msgs/Pose.h>
#include <mw_msgs/SetPlan.h>

#include <fstream>

int main(int argc, char **argv) {
  ros::init(argc, argv, "set_plan_client_node");

  if (argc != 2) {
    ROS_INFO("[set_plan_client]: usage: set_plan_client path/to/plan/file");
    return 1;
  }

  ros::NodeHandle n;

  ros::ServiceClient client = n.serviceClient<mw_msgs::SetPlan>("mission_executive/set_plan");

  std::ifstream plan_file;
  plan_file.open(argv[1]);

  if (!plan_file) {
    ROS_INFO("[set_plan_client]: Invalid plan file!");
    return 1; // terminate with error
  }


  mw_msgs::SetPlan srv;

  std::string line;
  int line_count = 0;
  while (std::getline(plan_file, line)) {
    geometry_msgs::Pose pose;
    line_count++;
    std::stringstream iss(line);
    int count = 0;
    double s1, s2, s3, word;
    while (iss >> word) {
      if (count == 0) {
        s1 = word;
      }
      if (count == 1) {
        s2 = word;
      }
      if (count == 2) {
        s3 = word;
      }
      count++;
    }
    if (count != 3) {
      ROS_INFO("[set_plan_client]: There is a problem with the input plan file format in line number %d", line_count);
      return 1;
    }

    pose.position.x = s1;
    pose.position.y = s2;
    pose.position.z = 0;

    tf2::Quaternion q;
    q.setRPY(0.0, 0.0, s3);
    q.normalize();
    pose.orientation.x = q[0];
    pose.orientation.y = q[1];
    pose.orientation.z = q[2];
    pose.orientation.w = q[3];

    srv.request.plan.header.stamp = ros::Time::now();
    srv.request.plan.header.frame_id = "map";
    srv.request.plan.poses.push_back(pose);

  }

  plan_file.close();

  if (client.call(srv)) {
    ROS_INFO("[set_plan_client]: set plan from '%s' was successful", argv[1]);
  } else {
    ROS_ERROR("[set_plan_client]: Failed to call service mission_executive/set_plan");
    return 1;
  }

  return 0;

}
