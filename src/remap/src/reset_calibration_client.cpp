#include <ros/ros.h>
#include <remap/ResetCalibration.h>

int main(int argc, char **argv) {

	ros::init(argc, argv, "reset_calibration_client");
	if (argc != 2) {
		ROS_ERROR("Failed to call service reset_calibration");
		ROS_INFO("usage: reset_calibration_client r");
		return 1;
	}
	
	ros::NodeHandle nh;
	ros::ServiceClient client = nh.serviceClient<remap::ResetCalibration>("reset_calibration");
	remap::ResetCalibration srv;
	srv.request.resetRequest = argv[1][0];
	
	if (client.call(srv)) 
		ROS_INFO("Calibration was reset successfully!");
	else {
		ROS_ERROR("Failed to call service reset_calibration");
		ROS_INFO("To reset calibration: rosrun remap reset_calibration_client r");
		return 1;
	}

	return 0;		
}
