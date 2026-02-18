#include "../HeaderFiles/AirConditioning.H"
#include <iostream>

AirConditioning::AirConditioning(int target_temp, unsigned int id, std::string name, std::string manufacturer) : Device(id, name, manufacturer), target_temperature(target_temp) {}

void AirConditioning::interaction_event()
{
    if (!status)
    {
        std::cout << "Current device is inactive!" << std::endl;
        return;
    }

    std::cout << "Current Air Condition temperature: " << target_temperature << "°C" << std::endl;
    std::cout << "Set a new temperature (16 - 32 °C): ";
    int new_temp;
    std::cin >> new_temp;
    if (new_temp >= 16 && new_temp <= 32)
    {
        target_temperature = new_temp; // validation checks
        std::cout << "Target Temperature set to: " << target_temperature << "°C" << std::endl;
    }
    else
    {
        std::cout << "Invalid Temperature..Try again!" << std::endl;
    }
}

void AirConditioning::ViewInfo()
{
    Device::ViewInfo();

    std::cout << "Current Temperature: " << target_temperature << "°C \n"
              << std::endl;
}

void AirConditioning::EditDevice()
{

    std::cout << "Editing Air Condition" << std::endl;
    std::cout << "Set a new temperature (16 - 32 °C): ";
    int new_temp;
    std::cin >> new_temp;
    if (new_temp >= 16 && new_temp <= 32)
    {
        target_temperature = new_temp; // validation checks
        std::cout << "Target Temperature set to: " << target_temperature << "°C" << std::endl;
    }
    else
    {
        std::cout << "Invalid Temperature..Try again!" << std::endl;
    }
}