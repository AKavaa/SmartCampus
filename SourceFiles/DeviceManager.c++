#include "../HeaderFiles/DeviceManager.h"
#include "../HeaderFiles/Projector.H"
#include "../HeaderFiles/Device.H"
#include "../HeaderFiles/SecurityCamera.H"
#include "../HeaderFiles/Projector.H"
#include "../HeaderFiles/AirConditioning.H"
#include "../HeaderFiles/RoomLighting.H"
#include "../HeaderFiles/DeviceManager.h"

#include <iostream>

// Creating default objects and adding them into the device vector using a unique pointer
// Unique pointers automatically manage memory and push_back adds the devices into the vector
void DeviceManager::RunProgram()
{

    devices.push_back(std::make_unique<Projector>("HDMI", 25, 1, "ProjectorCool", "SONY"));
    devices.push_back(std::make_unique<SecurityCamera>("FULL HD", "200 wat", 2, "Secure-Cam", "LOGITECH"));

    int choice = 0;

    ShowMenu();
    std::cin >> choice;

    ChoiceHandling(choice);
    // checks users input and based on what the user presses the specific output is shown
}

void DeviceManager::ShowMenu()
{

    std::cout << "====== Smart Campus Menu ======" << std::endl;
    std::cout << "1. View all devices" << std::endl;
    std::cout << "2. Exit" << std::endl;
    std::cout << "Choose an option:";
}

void DeviceManager::ChoiceHandling(int choice)
{
    switch (choice)
    {
    case 1:
        std::cout << "====== Device Information ====== \n"
                  << std::endl;
        // looping to show all the devices
        for (int i = 0; i < devices.size(); i++)
        {
            devices[i]->ViewInfo();
        }
        std::cout << "==============================" << std::endl;
        break;

    case 2:
        std::cout << "Program Exited.." << std::endl;
        exit(0);
        return;
        break;

    default:
        std::cout
            << "Invalid Choice..Please try again!"
            << std::endl;
        break;
    }
}