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

    devices.push_back(std::make_unique<SecurityCamera>("FULL HD", "200 wat", 1, "Secure-Cam", "LOGITECH"));
    devices.push_back(std::make_unique<AirConditioning>(20, 2, "AirConditioning", "AUX"));
    devices.push_back(std::make_unique<Projector>("HDMI", 25, 3, "ProjectorCool", "SONY"));
    devices.push_back(std::make_unique<RoomLighting>(50, 4, "MainRoomLighting", "Phillips"));

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
    std::cout << "2. Interact with a device" << std::endl;
    std::cout << "3. Exit" << std::endl;
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
    {
        unsigned int target_device;
        std::cout << "Enter the number ID (1-4) of the device you want to interact with: ";
        std::cin >> target_device;

        bool device_found = false;

        for (int i = 0; i < devices.size(); i++)
        {
            // devices[i]->ViewInfo();

            // Getter check if the device is the correct one
            if (devices[i]->Get_id() == target_device)
            {
                std::cout << "\n Interacting with device ID: " << target_device << std::endl;
                devices[i]->interaction_event(); // the device will trigger the inputed interaction event

                device_found = true;
                break;
            }
        }

        if (!device_found)
        {
            std::cout << "Device with ID: " << target_device << " was not found." << std::endl;
        }
        break;
    }

    case 3:
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