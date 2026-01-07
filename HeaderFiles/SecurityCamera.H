#ifndef SECURITYCAMERA_H
#define SECURITYCAMERA_H

#include "Device.H"
#include <string>
using namespace std;

class SecurityCamera : public Device
{
private:
    string camera_quality;
    string power;

public:
    SecurityCamera(string cam_quality, string pwr, unsigned int id, string name, string manufacturer) : Device(id, name, manufacturer), camera_quality(cam_quality), power(pwr) {}

    void interaction_event() override
    {
        if (!status)
        {
            cout << "Current device is inactive!" << endl;
            return;
        }
        else
        {
            cout << "Now viewing camera:" << device_name;
        }
    }
};

#endif