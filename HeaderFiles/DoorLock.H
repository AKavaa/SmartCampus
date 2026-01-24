
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
    DoorLock(bool locked, std::string last_opened_by, unsigned int id, std::string name, std::string manufacturer);

    void interaction_event() override;

    void ViewInfo() override;

    void EditDevice() override;
};

#endif