#ifndef AIRCONDITIONING_H
#define AIRCONDITIONING_H

#include <iostream>
#include <string>
#include "Device.H"

class AirConditioning : public Device
{
private:
    unsigned int target_temperature;

public:
    AirConditioning(int target_temp, unsigned int id, std::string name, std::string manufacturer);

    void interaction_event() override;

    void ViewInfo() override;
};

#endif