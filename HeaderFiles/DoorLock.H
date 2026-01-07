
#ifndef DOORLOCK
#define DOORLOCK

#include <iostream>
#include <string>
#include "Device.H"

class DoorLock : public Device
{
private:
    bool locked;
    std::string last_opened;

public:
    DoorLock(bool locked, std::string last_opened, unsigned int id, std::string name, std::string manufacturer) : Device(id, name, manufacturer), locked(locked), last_opened(last_opened) {}

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