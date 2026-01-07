#ifndef ROOMLIGHTING
#define ROOMLIGHTING

#include <iostream>
#include <string>
#include "Device.H"
using namespace std;

class RoomLighting : public Device
{
private:
    unsigned int brightness_level;

public:
    RoomLighting(unsigned int brightness_lvl, unsigned int id, string name, string manufacturer) : Device(id, name, manufacturer), brightness_level(brightness_lvl) {}

    void interaction_event()
    {
        if (!status)
        {
            cout << "Current device is inactive!" << endl;
            return;
        }
        else
        {
            // add the appropriate statement
        }
    }
};

#endif