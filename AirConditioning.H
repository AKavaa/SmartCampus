#ifndef AIRCONDITIONING_H
#define AIRCONDITIONING_H

#include <iostream>
#include <string>
#include "Device.H"
using namespace std;

class AirConditioning : public Device
{
private:
    unsigned int target_temperature;

public:
    AirConditioning(int target_temp, unsigned int id, string name, string manufacturer) : Device(id, name, manufacturer), target_temperature(target_temp) {}

    void interaction_event() override
    {
        if (!status)
        {
            cout << "Current device is inactive!" << endl;
            return;
        }
        else
        {
            cout << "Current Air Condition temperature: " << target_temperature << "°C" << endl;
            cout << "Set a new temperature: ";
            cin >> target_temperature;
            cout << "Target Temperature set to: " << target_temperature << "°C" << endl;
        }
    }
};

#endif