cmake_minimum_required(VERSION 2.8.3)
project(phidgets)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  genmsg
  message_generation
  roscpp_serialization
  actionlib
  geometry_msgs
  nav_msgs
  move_base_msgs
  rviz
  sensor_msgs
  sound_play
  tf
  image_transport
  libphidgets
)

## System dependencies are found with CMake's conventions
#find_package(Boost REQUIRED COMPONENTS system)
find_package(Boost REQUIRED)

find_package(OpenCV REQUIRED)
#include_directories(  ${catkin_INCLUDE_DIRS}  ${OpenCV_INCLUDE_DIRS} )
#target_link_libraries ( my_exec ${OpenCV_LIBRARIES} ${catkin_LIBRARIES} )


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
add_message_files(
   FILES
   manager_params.msg
   accelerometer_params.msg
   encoder_params.msg
   interface_kit_params.msg
   ir_params.msg
   joystick_params.msg
   led_params.msg
   motor_params.msg
   pantilt_params.msg
   phsensor_params.msg
   pid_params.msg
   rfid_params.msg
   servo_params.msg
   spatial_params.msg
   stepper_params.msg
   textlcd_params.msg
)

## Generate services in the 'srv' folder
add_service_files(
   FILES
   interface_kit.srv
   lidar_control.srv
   pid.srv
   servo_reference.srv
)

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
generate_messages(
   DEPENDENCIES
   geometry_msgs move_base_msgs nav_msgs sensor_msgs std_msgs
)

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES phidgets_cat
#  CATKIN_DEPENDS actionlib geometry_msgs nav_msgs roscpp rviz sensor_msgs sound_play std_msgs tf
#  DEPENDS system_lib
  CATKIN_DEPENDS message_runtime message_generation
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(phidgets_cat
#   src/${PROJECT_NAME}/phidgets_cat.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
#add_dependencies(high_speed_encoder ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
# add_executable(phidgets_cat_node src/phidgets_cat_node.cpp)

#add_executable(advanced_servo src/advanced_servo.cpp)
#add_executable(advanced_servo_client src/advanced_servo_client.cpp)
add_executable(high_speed_encoder src/high_speed_encoder.cpp)
add_executable(high_speed_encoder_client src/high_speed_encoder_client.cpp)
#add_executable(motor_control_hc src/motor_control_hc.cpp)
#add_executable(motor_control_hc_client src/motor_control_hc_client.cpp)
#add_executable(interface_kit src/interface_kit.cpp)
#add_executable(interface_kit_client src/interface_kit_client.cpp)
#add_executable(accelerometer src/accelerometer.cpp)
#add_executable(accelerometer_client src/accelerometer_client.cpp)
add_executable(manager src/manager.cpp)
add_executable(manager_client src/manager_client.cpp)
#add_executable(stepper src/stepper.cpp)
#add_executable(stepper_client src/stepper_client.cpp)
#add_executable(odometry src/odometry.cpp)
#add_executable(joystick src/joystick.cpp)
#add_executable(lidar src/lidar.cpp)
#add_executable(lidar_client src/lidar_client.cpp)
#add_executable(joystick_motor_control src/joystick_motor_control.cpp)
#add_executable(joystick_servo_control src/joystick_servo_control.cpp)
#add_executable(servo_glimpse src/servo_glimpse.cpp)
#add_executable(rfid src/rfid.cpp)
#add_executable(rfid_client src/rfid_client.cpp)
#add_executable(textlcd src/textlcd.cpp)
#add_executable(textlcd_client src/textlcd_client.cpp)
#add_executable(phsensor src/phsensor.cpp)
#add_executable(phsensor_client src/phsensor_client.cpp)
#add_executable(spatial src/spatial.cpp)
#add_executable(spatial_client src/spatial_client.cpp)
#add_executable(led src/led.cpp)
#add_executable(led_client src/led_client.cpp)
#add_executable(ir src/ir.cpp)
#add_executable(ir_client src/ir_client.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(high_speed_encoder ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(high_speed_encoder_client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(manager ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(manager_client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

#target_link_libraries(advanced_servo ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(advanced_servo_client ${catkin_LIBRARIES} ${Boost_LIBRARIES})
target_link_libraries(high_speed_encoder ${catkin_LIBRARIES} ${Boost_LIBRARIES})
target_link_libraries(high_speed_encoder_client ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(motor_control_hc ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(motor_control_hc_client ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(interface_kit ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(interface_kit_client ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(accelerometer ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(accelerometer_client ${catkin_LIBRARIES} ${Boost_LIBRARIES})
target_link_libraries(manager ${catkin_LIBRARIES} ${Boost_LIBRARIES})
target_link_libraries(manager_client ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(stepper ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(stepper_client ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(odometry ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(joystick ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(lidar ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(lidar_client ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(joystick_motor_control ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(joystick_servo_control ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(servo_glimpse ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(rfid ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(rfid_client ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(textlcd ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(textlcd_client ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(phsensor ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(phsensor_client ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(spatial ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(spatial_client ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(led ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(led_client ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(ir ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#target_link_libraries(ir_client ${catkin_LIBRARIES} ${Boost_LIBRARIES})

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS phidgets_cat phidgets_cat_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_phidgets_cat.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
