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
}