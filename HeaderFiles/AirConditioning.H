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
    AirConditioning(int target_temp, unsigned int id, std::string name, std::string manufacturer) : Device(id, name, manufacturer), target_temperature(target_temp) {}

    void interaction_event() override
    {
        if (!status)
        {
            std::cout << "Current device is inactive!" << std::endl;
            return;
        }
        else
        {
            std::cout << "Current Air Condition temperature: " << target_temperature << "°C" << std::endl;
            std::cout << "Set a new temperature: ";
            std::cin >> target_temperature;
            std::cout << "Target Temperature set to: " << target_temperature << "°C" << std::endl;
        }
    }
};

#endif