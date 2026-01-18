#include "../HeaderFiles/DeviceManager.h"
#include "../HeaderFiles/Projector.H"
#include "../HeaderFiles/Device.H"
#include "../HeaderFiles/SecurityCamera.H"
#include "../HeaderFiles/Projector.H"
#include "../HeaderFiles/AirConditioning.H"
#include "../HeaderFiles/RoomLighting.H"
#include "../HeaderFiles/DeviceManager.h"

#include <iostream>
using namespace std;

// Creating default objects and adding them into the device vector using a unique pointer
// Unique pointers automatically manage memory and push_back adds the devices into the vector
void DeviceManager::RunProgram()
{

    devices.push_back(make_unique<Projector>("HDMI", 25, 2, "ProjectorCool", "SONY"));
    devices.push_back(make_unique<SecurityCamera>("FULL HD", "200 wat", 2, "Secure-Cam", "LOGITECH"));

    int choice = 0;

    ShowMenu();
    cin >> choice;

    ChoiceHandling(choice);
    // checks users input and based on what the user presses the specific output is shown
}

void DeviceManager::ShowMenu()
{

    cout << "====== Smart Campus Menu ======" << endl;
    cout << "1. View all devices" << endl;
    cout << "2. Exit" << endl;
    cout << "Choose an option:";
}

void DeviceManager::ChoiceHandling(int choice)
{
    switch (choice)
    {
    case 1:
        // looping to show all the devices
        for (int i = 0; i < devices.size(); i++)
        {
            devices[i]->ViewInfo();
        }
        break;

    case 2:
        cout << "Program Exited.." << endl;
        exit(0);
        break;

    default:
        cout
            << "Invalid Choice..Please try again!"
            << endl;
        break;
    }
}