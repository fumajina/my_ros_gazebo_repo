#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <math.h>

int main(int argc,char** argv)
{
	ros::init(argc,argv,"arm_control");
	ros::NodeHandle nh;
	ros::Publisher joint_pub=nh.advertise<std_msgs::Float64>("2dof_robot_arm_assembly/Rev1_position_controller/command",1000);
	ros::Rate loop_rate(10);
        std_msgs::Float64 angle1;
	while(ros::ok()){
        	angle1.data=0;	
		joint_pub.publish(angle1);
		ros::spinOnce();
		loop_rate.sleep();
	}
}
