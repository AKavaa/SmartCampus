#ifndef SECURITYCAMERA_H
#define SECURITYCAMERA_H

#include "Device.H"
#include <string>

// Security class, inherits attributes from Device class
class SecurityCamera : public Device
{
private:
    std::string camera_quality;
    std::string power;

public:
    // initialising constructor
    SecurityCamera(std::string cam_quality, std::string pwr, unsigned int id, std::string name, std::string manufacturer) : Device(id, name, manufacturer), camera_quality(cam_quality), power(pwr) {}

    void interaction_event() override
    {
    }

    void ViewInfo() {}
};
#endif