#include <sstream>
#include "ros/ros.h"
#include <std_msgs/String.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Publisher");
    ros::NodeHandle n;
    //*创建一个Publisher,发布名为chatter的topic,消息类型为std_msgs::String
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "Hello World!" << count;
        msg.data = ss.str();
        chatter_pub.publish(msg);
        ROS_INFO("%s", msg.data.c_str());
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }
    return 0;
}
