#include "../HeaderFiles/AirConditioning.H"
#include <iostream>

AirConditioning::AirConditioning(int target_temp, unsigned int id, std::string name, std::string manufacturer) : Device(id, name, manufacturer), target_temperature(target_temp) {}

void AirConditioning::ViewInfo()
{
    Device::ViewInfo();

    std::cout << "Current Temperature: " << target_temperature << "°C \n"
              << std::endl;
}