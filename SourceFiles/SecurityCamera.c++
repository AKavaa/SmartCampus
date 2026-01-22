#include "../HeaderFiles/SecurityCamera.H"
#include <iostream>

SecurityCamera::SecurityCamera(std::string cam_quality, std::string pwr, unsigned int id, std::string name, std::string manufacturer)
    : Device(id, name, manufacturer), camera_quality(cam_quality), power(pwr)
{
}

void SecurityCamera::interaction_event()
{

    std::cout << " Now viewing camera" << std::endl;
}

void SecurityCamera::ViewInfo()
{

    Device::ViewInfo(); // shows other details of a the device

    if (!status)
    {
        std::cout << "Current device is inactive!" << std::endl;
        return;
    }

    std::cout << "Camera viewing:" << device_name << std::endl;
    std::cout << "Camera Quality:" << camera_quality << std::endl;
    std::cout << "Power:" << power << std::endl;
}
