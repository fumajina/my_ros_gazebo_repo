#include<ros/ros.h>
#include<string.h>

int main(int argc,char** argv)
{
	ros::init(argc,argv,"basic_logger");
	ros::NodeHandle nh;
	ros::Rate loop_rate(1);
	int count=0;
	while(ros::ok())
	{
		ROS_INFO("log:%d",count);
		ROS_WARN("log:%d",count);
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
