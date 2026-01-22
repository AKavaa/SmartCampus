#include "../HeaderFiles/DeviceManager.h"
#include "../HeaderFiles/Projector.H"
#include "../HeaderFiles/Device.H"
#include "../HeaderFiles/SecurityCamera.H"
#include "../HeaderFiles/Projector.H"
#include "../HeaderFiles/AirConditioning.H"
#include "../HeaderFiles/RoomLighting.H"
#include "../HeaderFiles/DoorLock.H"
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
    devices.push_back(std::make_unique<DoorLock>(true, "Admin", 5, "FrontDoor", "Braga"));

    int choice = 0;

    ShowMenu();
    std::cin >> choice;
    ChoiceHandling(choice);
    // checks users input and based on what the user presses the specific output is shown
}

void InteractDeviceMenu()
{
    std::cout << "[ID:1 - SecurityCamera]" << std::endl;
    std::cout << "[ID:2 - AirConditioning]" << std::endl;
    std::cout << "[ID:3 - Projector]" << std::endl;
    std::cout << "[ID:4 - RoomLighting]" << std::endl;
    std::cout << "[ID:5 - DoorLock]" << std::endl;
}
void DeviceManager::ActivateAllDevices()
{

    // using auto for cleaner syntax and for the compiler to work out the element type in runtime
    for (auto &dev : devices)
    {
        dev->Activate();
        std::cout << "All devices are activated!" << std::endl;
    }
}

void DeviceManager::DeactivateAllDevices()
{

    // using auto for cleaner syntax and for the compiler to work out the element type in runtime
    for (auto &dev : devices)
    {
        dev->Deactivate();
        std::cout << "All devices are deactivated!" << std::endl;
    }
}

void DeviceManager::ShowMenu()
{

    std::cout << "\n\n====== Smart Campus Menu ======" << std::endl;
    std::cout << "1. View all devices" << std::endl;
    std::cout << "2. Interact with a device" << std::endl;
    std::cout << "3. Activate all devices" << std::endl;
    std::cout << "4. Deactivate all devices" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Choose an option:";
}

void DeviceManager::ChoiceHandling(int choice)
{
    switch (choice)
    {
    case 1:
        std::cout << " \n====== Device Information ====== \n"
                  << std::endl;
        // looping to show all the devices
        for (int i = 0; i < devices.size(); i++)
        {
            devices[i]->ViewInfo();
            std::cout << "----------------------------" << std::endl;
        }

        break;

    case 2:
    {
        unsigned int target_device;
        InteractDeviceMenu();
        std::cout << "Enter the number ID (1-5) of the device you want to interact with: ";
        std::cin >> target_device;

        bool device_found = false;

        for (int i = 0; i < devices.size(); i++)
        {
            // devices[i]->ViewInfo();

            // Getter check if the device is the correct one
            if (devices[i]->Get_id() == target_device)
            {
                std::cout << "Interacting with device ID: " << target_device << std::endl;
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
        ActivateAllDevices();
        break;

    case 4:
        DeactivateAllDevices();
        break;

    case 5:
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