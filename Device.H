#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string>

class Device
{

protected:
    unsigned int unique_number_id;
    std::string device_name;
    std::string manufacturer;
    bool status;

public:
    // constructor to initialize parameters for Device
    Device(unsigned int id, std::string name, std::string manufacturer) : unique_number_id(id), device_name(name), manufacturer(manufacturer), status(false) {}

    // destructor is initialised for safe polymorphic deletion and ensures correct clean up=
    virtual ~Device() {}

    // view info method, check each Device's information
    virtual void ViewInfo()
    {

        std::cout << "====== Device Information =====" << std::endl;
        std::cout << "ID:" << unique_number_id << std::endl;
        std::cout << "Name:" << device_name << std::endl;
        std::cout << "Manufacturer:" << manufacturer << std::endl;
        std::cout << "Status: " << (status ? "Active" : "Inactive") << std::endl; // if Status is true then output it Active, else Inactive
        std::cout << "==============================" << std::endl;
    }

    // if device is activated the appropriate message is shown
    void Activate()
    {
        status = true;
        std::cout << device_name << " is activated..";
    }

    // if device is deactivated the appropriate message is shown
    void Deactivate()
    {
        status = false;
        std::cout << device_name << " is deactivated.. ";
    }

    // this method will be called and override each class with the appropriate output
    virtual void interaction_event() = 0;
};

#endif