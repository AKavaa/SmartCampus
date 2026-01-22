#include "../HeaderFiles/DoorLock.H"
#include <iostream>

DoorLock::DoorLock(bool locked, std::string last_opened_by, unsigned int id, std::string name, std::string manufacturer) : Device(id, name, manufacturer), locked(locked), last_opened_by(last_opened_by) {}

void DoorLock::interaction_event()
{
    std::cout << "Door Status: " << (locked ? "Locked" : "Unlocked") << std::endl;
    std::cout << "State your username: ";
    std::cout << "Last opened by: " << last_opened_by << std::endl;

    int choice;
    std::cout << "1. Lock Door | 2. Unlock Door" << std::endl;

    std::cin >> choice;

    if (choice == 1)
    {
        locked = true;
        std::cout << "Door Locked";
    }
    else if (choice == 2)
    {
        locked = false;
        std::cout << "Enter the username who unlocked the door: ";
        std::cin >> last_opened_by;
        std::cout << "Door was unlocked by: " << last_opened_by << std::endl;
    }
    else
    {
        std::cout << "Invalid input " << std::endl;
    }
}

void DoorLock::ViewInfo()
{
    Device::ViewInfo();
    std::cout << "Door Locked: " << (locked ? "Yes" : "No") << std::endl;
    std::cout << "Last opened by: " << last_opened_by << std::endl;
}