#!/usr/bin/env python

'''  
This node extracts data from the cyberglove through serial connection and publishes them in the topics: 
- /cyberglove/calibrated/joint_states
- /cyberglove/raw/joint_states
'''

# TODO: Calibrate the values to be published in the topic /calibrated/joint_states or 
# take it out as we use only the topic /raw/joint_states to calculate the fingers' positions

import serial
import rospy
from sensor_msgs.msg import JointState

def gloveSerial():
	# Open serial port
	ser = serial.Serial('/dev/ttyS0', 115200) 
	ser.flush()	

	# ser.write('N 22\r') # Set the number of sensors
	# ser.readline()

	# ser.write('T 1152 1\r') # Set frequency to 100 Hz
	# ser.readline()

	# Publishes calibrated JointState messages
	cyberglove_pub = rospy.Publisher('/cyberglove/calibrated/joint_states', JointState, queue_size=2)
	
	# Publishes raw JointState messages
	cyberglove_raw_pub = rospy.Publisher('/cyberglove/raw/joint_states', JointState, queue_size=2)

	rospy.init_node('gloveSerial', anonymous=True)

	rate = rospy.Rate(100) # 100 Hz

	# initialises joint names (the order is important)
	jointstate_msg = JointState()   
	jointstate_raw_msg = JointState()	
	jointstate_msg.name.append("G_ThumbRotate")
    	jointstate_msg.name.append("G_ThumbMPJ")
    	jointstate_msg.name.append("G_ThumbIJ")
    	jointstate_msg.name.append("G_ThumbAb")
    	jointstate_msg.name.append("G_IndexMPJ")
    	jointstate_msg.name.append("G_IndexPIJ")
    	jointstate_msg.name.append("G_IndexDIJ")
    	jointstate_msg.name.append("G_MiddleMPJ")
    	jointstate_msg.name.append("G_MiddlePIJ")
    	jointstate_msg.name.append("G_MiddleDIJ")
    	jointstate_msg.name.append("G_MiddleIndexAb")
    	jointstate_msg.name.append("G_RingMPJ")
    	jointstate_msg.name.append("G_RingPIJ")
    	jointstate_msg.name.append("G_RingDIJ")
    	jointstate_msg.name.append("G_RingMiddleAb")
    	jointstate_msg.name.append("G_PinkieMPJ")
    	jointstate_msg.name.append("G_PinkiePIJ")
    	jointstate_msg.name.append("G_PinkieDIJ")
    	jointstate_msg.name.append("G_PinkieRingAb")
    	jointstate_msg.name.append("G_PalmArch")
    	jointstate_msg.name.append("G_WristPitch")
    	jointstate_msg.name.append("G_WristYaw")

	jointstate_raw_msg.name = jointstate_msg.name
	
	# Set the size of jointstate_msg.position[] (22 sensors)
	for i in range (0, 22):
		jointstate_msg.position.append(0)
		jointstate_raw_msg.position.append(0)

	while not rospy.is_shutdown():
		ser.write("G")
		ser.read() # First output 'G'
		for i in range (0, 22): # Sensors s1, s2,..., s22
			# The values sent by the glove are in the range [1;254]
			# We convert them to float in the range [0;1]
			glove_position = (ord(ser.read()) - 1.0) / 253.0
			jointstate_msg.position[i] = glove_position
			jointstate_raw_msg.position[i] = jointstate_msg.position[i]
		ser.read() # Last output nul
		cyberglove_pub.publish(jointstate_msg)
		cyberglove_raw_pub.publish(jointstate_raw_msg)	
		rate.sleep()

if __name__ == '__main__':
	
	# Print glove info 
	print("Gathering data from Cyberglove...");

	try:
		gloveSerial()
	except rospy.ROSInterruptException:
		pass
			







