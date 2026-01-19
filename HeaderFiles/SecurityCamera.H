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
    SecurityCamera(std::string cam_quality, std::string pwr, unsigned int id, std::string name, std::string manufacturer);

    void interaction_event() override
    {
        // std::cout << "Camera Interaction triggered" << std::endl;

        std::cout << "Camera viewing:" << device_name << std::endl;
        std::cout << "Camera Quality:" << camera_quality << std::endl;
        std::cout << "Power:" << power << std::endl;
    }

    void ViewInfo() override;
};
#endif