#ifndef SECURITYCAMERA_H
#define SECURITYCAMERA_H

#include "Device.H"
#include <string>

class SecurityCamera : public Device
{
private:
    std::string camera_quality;
    std::string power;

public:
    SecurityCamera(std::string cam_quality, std::string pwr, unsigned int id, std::string name, std::string manufacturer) : Device(id, name, manufacturer), camera_quality(cam_quality), power(pwr) {}

    void interaction_event() override
    {
        if (!status)
        {
            std::cout << "Current device is inactive!" << std::endl;
            return;
        }
        else
        {
            std::cout << "Now viewing camera:" << device_name;
        }
    }
};

#endif