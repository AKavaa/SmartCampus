#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "Projector.H"

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
    vector<unique_ptr<Device>> devices;

public:
    // calling this in main and the program will be running
    void RunProgram()
    {
        // Creating default objects and adding them into the device vector using a unique pointer
        // Unique pointers automatically manage memory and push_back adds the devices into the vector
        devices.push_back(make_unique<Projector>("HDMI", 25, 2, "ProjectorCool", "SONY"));
    }

    // will be showing the menu for the Smart Campus
    void ShowMenu()
    {
        cout << " ====== All the available devices ======" << endl;
        for (int i = 0; i < devices.size(); i++)
        {

            // move to the next section of the menu
            cout << "Device" << i + 1 << ":" << endl;
            devices[i]->ViewInfo(); // call ViewInfo function through a pointer, so the implementation is correct at runtime
        }
    }

    // user will be able to input and choose what to do inside the program
    void ChoiceHandling();
};

#endif