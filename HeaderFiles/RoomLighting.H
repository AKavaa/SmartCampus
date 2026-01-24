#ifndef ROOMLIGHTING_H
#define ROOMLIGHTING_H

#include <iostream>
#include <string>
#include "Device.H"

class RoomLighting : public Device
{
private:
    unsigned int brightness_level;

public:
    RoomLighting(unsigned int brightness_lvl, unsigned int id, std::string name, std::string manufacturer);

    void interaction_event() override;

    void ViewInfo() override;

    void EditDevice() override;
};

#endif