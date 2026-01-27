#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "Projector.H"
#include <string>
#include <memory>
#include <vector>
#include "Device.H"

// Room class that will store multiple devices
class Room
{

public:
    std::string room_name; // name of the room

    // Unique_ptr is used to automatically destroy the devices when the room is destroyed
    // and making sure that the devices are managed by the specific room
    std::vector<std::unique_ptr<Device>> room_devices;

    Room(std::string name) : room_name(name) {}
};

class DeviceManager
{

private:
    // stores all the devices using polymorphic container
    // this allows different device type to be stored a unique pointer
    // using the unique pointer allows automatic memory handling and ownership
    std::vector<std::unique_ptr<Device>> devices;

    // helps to create the room inside the DeviceManager
    std::vector<std::unique_ptr<Room>> room;

public:
    // calling this in main and the program will be running
    void RunProgram();
    void ActivateAllDevices();
    void DeactivateAllDevices();
    void AddDevice();
    void DeleteDevice();
    void EditDevice();
    void CheckConnection();
    void CheckConnectionList();
    void DeviceSearch();
    void CreateRoom();
    void ViewAllRooms();

    // will be showing the menu for the Smart Campus
    void ShowMenu();
    void ChoiceHandling(int choice);

    // user will be able to input and choose what to do inside the program
};

#endif