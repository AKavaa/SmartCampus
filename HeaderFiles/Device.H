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
    bool isConnected;

public:
    // constructor to initialize parameters for Device
    Device(unsigned int id, std::string name, std::string manufacturer) : unique_number_id(id), device_name(name), manufacturer(manufacturer), status(false), isConnected(true) {}

    // destructor is initialised for safe polymorphic deletion and ensures correct clean up=
    virtual ~Device() {}

    // Getter method so user can interact with a device id
    // const so hte compiler wont change any data
    unsigned int Get_id() const
    {
        return unique_number_id;
    }

    // view info method, check each Device's information
    // approach using polymorphism
    virtual void ViewInfo()
    {

        std::cout << "ID:" << unique_number_id << std::endl;
        std::cout << "Name:" << device_name << std::endl;
        std::cout << "Manufacturer:" << manufacturer << std::endl;
        std::cout << "Status: " << (status ? "Active" : "Inactive \n") << std::endl; // if Status is true then output it Active, else Inactive
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

    bool CheckConnection()
    {
        return isConnected; // CheckConnection method
    }

    //  method to check the status
    void SetConnection(bool status)
    {
        isConnected = status;
    }

    // this method will be called and override each class with the appropriate output
    virtual void interaction_event() = 0;

    // this method will be called and override each class with the appropriate edits
    virtual void EditDevice() = 0;
};

#endif