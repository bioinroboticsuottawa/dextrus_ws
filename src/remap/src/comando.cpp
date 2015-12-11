//
// Created by rafaelpaiva on 11/12/15.
//

#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <sensor_msgs/JointState.h>
#include <algorithm>

const std::vector<std::string> joints = {std::string("G_MiddlePIJ"), std::string("G_MiddleMPJ"), std::string("G_MiddleDIJ")};
const std::vector<double> W = {0.676887279665986e02, 1.227465999478036e02, 0.431556298169175e02};

const double b = -0.385880301168764e02;

std_msgs::Float64 position;
bool next = false;

void receive(const sensor_msgs::JointStateConstPtr &msg) {
	if (next)
		return;
	double position = b;
	for (int i = 0; i < joints.size(); ++i) {
		long j = std::find(msg->name.begin(), msg->name.end(), joints[i]) - msg->name.begin();
		position += W[i] * msg->position[j];
		ROS_INFO("%lf, %lf", position, msg->position[j]);
	}
	ROS_INFO("Position: %lf", position);
	::position.data = position;
	next = true;
}

int main (int argc, char **argv)
{
	ros::init(argc, argv, "comando");
	ros::NodeHandle nh;

	ros::Publisher pub = nh.advertise<std_msgs::Float64>("/posicao", 32);
	ros::Subscriber sub = nh.subscribe("/cyberglove/raw/joint_states", 32, receive);

	ROS_INFO("Starting mapping...");

	while(ros::ok()) {
		if (next) {
			pub.publish(position);
			next = false;
		}
		ros::spinOnce();
	}

	ros::shutdown();

	ROS_INFO("Bye.");

	return 0;
}
