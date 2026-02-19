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

    Device::ViewInfo(); // shows information about the device

    std::cout << "Camera viewing:" << device_name << std::endl;
    std::cout << "Camera Quality:" << camera_quality << std::endl;
    std::cout << "Power:" << power << std::endl;
}

void SecurityCamera::EditDevice()
{
    int choice;
    std::cout << "Editing Security Camera" << std::endl;
    std::cout << "Input new Camera resolution : " << std::endl;
    std::cout << "1. 4K" << std::endl;
    std::cout << "2. 1080p" << std::endl;
    std::cout << "3. 720p" << std::endl;
    std::cout << "Enter Input Source:";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        camera_quality = "4K";
        break;
    case 2:
        camera_quality = "1080p";
        break;
    case 3:
        camera_quality = "720p";
        break;

    default:
        std::cout << "Wrong input try again!" << std::endl;
        break;
    }

    std::cout << "Enter the new power source: " << std::endl;
    std::cout << "1. Battery" << std::endl;
    std::cout << "2. Wireless" << std::endl;
    std::cout << "3. Solar Battery" << std::endl;
    std::cout << "Enter Input Source:";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        power = "Battery";
        break;
    case 2:
        power = "Wireless";
        break;
    case 3:
        power = "Solar Battery";
        break;

    default:
        std::cout << "Wrong input try again!" << std::endl;
        break;
    }

    std::cout << "Changed succesfully saved!" << std::endl;
}
