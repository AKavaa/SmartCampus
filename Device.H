#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string>
using namespace std;

class Device
{

protected:
    unsigned int unique_number_id;
    string device_name;
    string manufacturer;
    bool status;

public:
    // constructor to initialize parameters for Device
    Device(unsigned int id, string name, string manufacturer) : unique_number_id(id), device_name(name), manufacturer(manufacturer), status(false) {}

    // destructor is initialised for safe polymorphic deletion and ensures correct clean up=
    virtual ~Device() {}

    // view info method, check each Device's information
    virtual void ViewInfo()
    {

        cout << "====== Device Information =====" << endl;
        cout << "ID:" << unique_number_id << endl;
        cout << "Name:" << device_name << endl;
        cout << "Manufacturer:" << manufacturer << endl;
        cout << "Status: " << (status ? "Active" : "Inactive") << endl; // if Status is true then output it Active, else Inactive
        cout << "==============================" << endl;
    }

    // if device is activated the appropriate message is shown
    void Activate()
    {
        status = true;
        cout << device_name << " is activated..";
    }

    // if device is deactivated the appropriate message is shown
    void Deactivate()
    {
        status = false;
        cout << device_name << " is deactivated.. ";
    }

    // this method will be called and override each class with the appropriate output
    virtual void interaction_event() = 0;
};

#endif