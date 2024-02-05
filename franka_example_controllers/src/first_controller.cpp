#include <ros/ros.h>
#include <cmath>

#include "std_msgs/String.h"
#include <sensor_msgs/JointState.h>


int main(int argc, char **argv) {
    // Initialize the ROS node
    ros::init(argc, argv, "first_controller");

    auto nh = std::make_shared<ros::NodeHandle>("~");
    ros::Publisher joint_publisher;

    joint_publisher = nh->advertise<sensor_msgs::JointState>("joint_states", 10);

    ros::Rate loopRate(10);

    float desPos=0;

    sensor_msgs::JointState JSmsg;
    JSmsg.name[0] = "joint8";

    // Enter the ROS event loop
    while (ros::ok())
    {
        desPos = desPos+0.01;

        // Populate joint positions
        JSmsg.position[0]= desPos;  // Joint 1 position in radians

        // Populate header
        JSmsg.header.stamp = ros::Time::now();
        joint_publisher.publish(JSmsg);

        // Sleep to achieve the specified loop rate
        loopRate.sleep();

        // Spin once to process callbacks
        ros::spinOnce();
    }

    return 0;
}



