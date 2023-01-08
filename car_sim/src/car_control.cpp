#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv,"car_control");
  ros::NodeHandle nh;
  ros::Publisher carvel_pub = nh.advertise<geometry_msgs::Twist>("test_robot2_assem/diff_drive_controller/cmd_vel", 10);
  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    geometry_msgs::Twist twist;
    twist.linear.x = 0.0;
    twist.linear.y = 0.0;
    twist.linear.z = 0.0;
    twist.angular.x = 0.0;
    twist.angular.y = 0.0;
    twist.angular.z = 1.0;

    carvel_pub.publish(twist);

    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
