//
// Created by rafaelpaiva on 09/12/15.
//

#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <sensor_msgs/JointState.h>
#include <yaml-cpp/yaml.h>
#include <fstream>
#include <algorithm>

class Leitor {
public:
	Leitor();
	~Leitor();

	void run();

	void receive(const sensor_msgs::JointStateConstPtr &ptr);

private:
	ros::NodeHandle _nh;
	ros::Publisher _pub;
	ros::Subscriber _sub;
	std::ofstream _file;
	std::string _step;

	bool _accept;
	int _read;
	std_msgs::Float64 _position;
	YAML::Node _register;
};

int main(int argc, char **argv)
{
	ros::init(argc, argv, "leitor");
	ros::start();

	ROS_INFO("Starting gathering the information");

	ros::Duration(5.0).sleep();

	Leitor leitor;

	leitor.run();

	ros::shutdown();

	return 0;
}

Leitor::Leitor() : _read(0) {

	_pub = _nh.advertise<std_msgs::Float64>("/posicao", 32);
	_sub = _nh.subscribe("/cyberglove/raw/joint_states", 32, &Leitor::receive, this);

	_file.open("./file.yaml", std::fstream::out);

}

Leitor::~Leitor() {
	ROS_INFO("Finished.");
	_file.close();

	_pub.shutdown();
	_sub.shutdown();
	ros::shutdown();
}

void Leitor::run() {
	ROS_INFO("Starting registering the hand");

	for (double pos = 0.0; pos <= 100.0; pos += 5.0) {
		if (!ros::ok())
			break;

		std::ostringstream os;
		os << pos;
		_step = os.str();

		ROS_INFO("Setting the position to %lf", pos);
		_accept = false;
		_position.data = pos;
		_pub.publish(_position);

		ros::spinOnce();

		ros::Duration(3.5).sleep();

		_accept = true;

		ROS_INFO("Gathering...");
		while (_read < 64 && ros::ok()) {
			ros::spinOnce();
		}
		ROS_INFO("OK.");
		_read = 0;
	}

	_file << _register;
}

void Leitor::receive(const sensor_msgs::JointStateConstPtr &ptr) {
	if (!_accept)
		return;

	YAML::Node joint;

	joint["G_MiddleMPJ"] = 0.0;
	joint["G_MiddlePIJ"] = 0.0;
	joint["G_MiddleDIJ"] = 0.0;

	YAML::iterator it;
	for (it = joint.begin(); it != joint.end(); ++it) {
		long pos = std::find(ptr->name.begin(), ptr->name.end(), it->first.as<std::string>()) - ptr->name.begin();
		it->second = ptr->position[pos];
	}

	_register[_step][_read] = joint;

	++_read;
}
