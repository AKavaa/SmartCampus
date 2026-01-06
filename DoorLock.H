
#ifndef DOORLOCK
#define DOORLOCK

#include <iostream>
#include <string>
#include "Device.H"
using namespace std;

class DoorLock : public Device
{
private:
    bool locked;
    string last_opened;

public:
    DoorLock(bool locked, string last_opened, unsigned int id, string name, string manufacturer) : Device(id, name, manufacturer), locked(locked), last_opened(last_opened) {}

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