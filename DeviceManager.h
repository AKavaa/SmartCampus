#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include <memory>
#include <vector>
#include "Device.H"

using namespace std;

class DeviceManager
{

private:
    // stores all the devices using polymorphic container
    // this allows different device type to be stored a unique pointer
    // using the unique pointer allows automatic memory handling and ownership
    std::vector<std::unique_ptr<Device>> devices;

public:
    // calling this in main and the program will be running
    void RunProgram();

    // will be showing the menu for the Smart Campus
    void ShowMenu();

    // user will be able to input and choose what to do inside the program
    void ChoiceHandling();
};

#endif