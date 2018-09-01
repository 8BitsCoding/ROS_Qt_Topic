#include "ros/ros.h"
#include "std_msgs/String.h"

#include "ros_tutorials_topic/MsgTutorial.h"


void chatterCallback( const ros_tutorials_topic::MsgTutorial::ConstPtr& msg)
{
  ROS_INFO("receive msg = %d", msg->stamp.sec);
  ROS_INFO("receive msg = %d", msg->stamp.nsec);
  ROS_INFO("receive msg = %d", msg->data);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "topic_subscriber");
  ros::NodeHandle nh;

  ros::Subscriber ros_tutorials_sub = nh.subscribe("ros_tutorial_msg", 100, chatterCallback);

  ros::spin();

  return 0;
}
