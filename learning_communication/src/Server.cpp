#include <ros/ros.h>
#include <learning_communication/AddTwoInts.h>

bool add(learning_communication::AddTwoInts::Request &req, learning_communication::AddTwoInts::Response &res)
{
    res.sum = req.a + req.b;

    ROS_INFO("request:x=%ld,y=%ld", (long int)req.a, (long int)req.b);
    ROS_INFO("sending back response:[%ld]", (long int)res.sum);
}
