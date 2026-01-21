#ifndef PROJECTOR_H
#define PROJECTOR_H

#include <iostream>
#include <string>
#include "Device.H"

class Projector : public Device
{
private:
    std::string input_source;
    unsigned short brightness_level;

public:
    Projector(std::string input_src, unsigned short brightness_lvl, unsigned int id, std::string name, std::string manufacturer);

    void interaction_event() override;

    void ViewInfo() override;
};

#endif