
#ifndef DOORLOCK_H
#define DOORLOCK_H

#include <iostream>
#include <string>
#include "Device.H"

class DoorLock : public Device
{
private:
    bool locked;
    std::string last_opened_by;

public:
    DoorLock(bool locked, std::string last_opened_by, unsigned int id, std::string name, std::string manufacturer) : Device(id, name, manufacturer), locked(locked), last_opened_by(last_opened_by) {}

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

    void Activate();
    void Deactivate();
};

#endif