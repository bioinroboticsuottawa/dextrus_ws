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
	std_msgs::Float64 _position;
	YAML::Node _joint, _register;
};

int main(int argc, char **argv)
{
	ros::init(argc, argv, "leitor");

	Leitor leitor;

	leitor.run();

	return 0;
}

Leitor::Leitor() {
	ros::Publisher _pub = _nh.advertise<std_msgs::Float64>("posicao", 32);
	ros::Subscriber _sub = _nh.subscribe("/cyberglove/raw/joint_states", 32, &Leitor::receive, this);

	_file.open("./file.yaml", std::fstream::out);

	_joint["G_MiddleMPJ"] = 0.0;
	_joint["G_MiddlePIJ"] = 0.0;
	_joint["G_MiddleDIJ"] = 0.0;

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

	std::ostringstream os;

	for (double pos = 0.0; pos <= 100.0; pos += 5.0) {
		os.clear();
		os << pos;
		_step = os.str();

		ROS_INFO("Setting the position to %lf", pos);
		_accept = false;
		_position.data = pos;
		_pub.publish(_position);

		ros::spinOnce();

		ros::Duration(1.0).sleep();

		_accept = true;

		for (int i = 0; i < 64; ++i) {
			ros::spinOnce();
		}
	}

	_file << _register;
}

void Leitor::receive(const sensor_msgs::JointStateConstPtr &ptr) {
	if (!_accept)
		return;

	YAML::iterator it;
	for (it = _joint.begin(); it != _joint.end(); ++it) {
		long pos = std::find(ptr->name.begin(), ptr->name.end(), it->first.as<std::string>()) - ptr->name.begin();
		it->second = ptr->position[pos];
	}

	_register[_step].push_back(_joint);
}
