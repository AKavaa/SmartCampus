#include "../HeaderFiles/Projector.H"
#include <iostream>

Projector::Projector(std::string input_src, unsigned short brightness_lvl, unsigned int id, std::string name, std::string manufacturer) : Device(id, name, manufacturer), input_source(input_src), brightness_level(brightness_lvl) {}

void Projector::ViewInfo()
{

    Device::ViewInfo();

    std::cout
        << "Source input :" << input_source << std::endl;
    std::cout << "Brightness input :" << brightness_level << "%" << "\n"
              << std::endl;
}
