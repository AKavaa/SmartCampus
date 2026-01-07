#ifndef ROOMLIGHTING
#define ROOMLIGHTING

#include <iostream>
#include <string>
#include "Device.H"

class RoomLighting : public Device
{
private:
    unsigned int brightness_level;

public:
    RoomLighting(unsigned int brightness_lvl, unsigned int id, std::string name, std::string manufacturer) : Device(id, name, manufacturer), brightness_level(brightness_lvl) {}

    void interaction_event()
    {
        if (!status)
        {
            std::cout << "Current device is inactive!" << std::endl;
            return;
        }
        else
        {
            // add the appropriate statement
        }
    }
};

#endif