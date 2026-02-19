#include "../HeaderFiles/RoomLighting.H"

#include <iostream>

RoomLighting::RoomLighting(unsigned int brightness_lvl, unsigned int id, std::string name, std::string manufacturer) : Device(id, name, manufacturer), brightness_level(brightness_lvl) {}

void RoomLighting::interaction_event()
{

    if (!status)
    {
        std::cout << "Current device is inactive!" << std::endl;
        return;
    }

    std::cout << "Current Brightness level:" << brightness_level << "%" << std::endl;
    std::cout << "Set new brightness level (0-100%):";
    unsigned int new_brightness_level;
    std::cin >> new_brightness_level;

    if (new_brightness_level > 100 || new_brightness_level < 0)
    {
        std::cout << "Brightness is out of range, please try again!" << std::endl;
    }
    else
    {
        std::cout << "Brightness in range, Saving current input" << std::endl;
        brightness_level = new_brightness_level;

        std::cout << "New brightness level set to:" << brightness_level << std::endl;
    }
}

void RoomLighting::ViewInfo()
{
    Device::ViewInfo();
    std::cout << "Current brightness level: " << brightness_level << "%" << std::endl;
}

void RoomLighting::EditDevice()
{
    unsigned int new_brightness_level;
    std::cout << "Editing Room Lighting" << std::endl;
    std::cout << "Enter new brightness level(0-100%): ";
    std::cin >> new_brightness_level;

    if (new_brightness_level > 100 || new_brightness_level < 0)
    {
        std::cout << "Brightness is out of range, please try again!" << std::endl;
    }
    else
    {
        std::cout << "Brightness in range, Saving current input" << std::endl;
        brightness_level = new_brightness_level;

        std::cout << "New brightness level set to: " << brightness_level << "%" << std::endl;
    }
}