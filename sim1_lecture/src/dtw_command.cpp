#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

geometry_msgs::Twist twist;

int main(int argc,char **argv)
{
	ros::init(argc,argv,"dtw_command");
	ros::NodeHandle nh;
	ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("/dtw_robot/diff_drive_controller/cmd_vel",100);
	ros::Rate rate(1);

	while(ros::ok())
	{
	twist.linear.x=0.4;
	twist.angular.z=0.2;
	pub.publish(twist);
	ros::spinOnce();
	rate.sleep();
	}
	return 0;
}
