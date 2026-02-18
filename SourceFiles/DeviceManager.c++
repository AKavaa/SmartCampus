#include "../HeaderFiles/DeviceManager.h"
#include "../HeaderFiles/Projector.H"
#include "../HeaderFiles/Device.H"
#include "../HeaderFiles/SecurityCamera.H"
#include "../HeaderFiles/AirConditioning.H"
#include "../HeaderFiles/RoomLighting.H"
#include "../HeaderFiles/DoorLock.H"

#include <iostream>
#include <fstream>
#include <sstream>

// Creating default objects and adding them into the device vector using a unique pointer
// Unique pointers automatically manage memory and push_back adds the devices into the vector
void DeviceManager::RunProgram()
{

    LoadFromFile(); // Load the devices from the file

    devices.push_back(std::make_unique<SecurityCamera>("FULL HD", "200 WAT", 1, "Security-Camera", "LOGITECH"));
    devices.push_back(std::make_unique<AirConditioning>(20, 2, "Air-Conditioning", "AUX"));
    devices.push_back(std::make_unique<Projector>("HDMI", 25, 3, "Projector", "SONY"));
    devices.push_back(std::make_unique<RoomLighting>(50, 4, "Main-Room-Lighting", "PHILLIPS"));
    devices.push_back(std::make_unique<DoorLock>(true, "Admin", 5, "Front-Door", "BRAGA"));

    int choice = 0;

    // While loops helps the program to live inside the memory, It ensures after every correct input
    // the program will return to a fresh start instead of exiting
    while (true)
    {
        ShowMenu();

        // reads the input
        if (!(std::cin >> choice))
        {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            // Resets the input system if the user mistypes (example. letters instead of numbers)
            std::cin.clear();
            // cleans the input buffer so it is preventing the user skipping the next inputs (id, name, brand)
            std::cin.ignore(1000, '\n');
            continue;
        }

        std::cin.ignore(1000, '\n');

        ChoiceHandling(choice);
    }
}

// DESIGN PATTERN: factory method
//  The system reads and extract information from the file
//  and this function is acting as a factory, deciding which device will be
//  initialiased based on the string read from the file
void DeviceManager::LoadFromFile()
{
    std::ifstream file("Devices.txt");
    if (!file)
    {
        return;
    }

    std::string line, rName, type, ID, dName, brand, extraInfo;

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        std::stringstream ss(line);
        std::getline(ss, rName, '|');
        std::getline(ss, type, '|');
        std::getline(ss, ID, '|');
        std::getline(ss, dName, '|');
        std::getline(ss, brand, '|');
        std::getline(ss, extraInfo);

        // This is the conversion of int into the string so there is no logical errors
        int dev_id = std::stoi(ID); // stoi -> convert integer(int) to string
        Room *target_room = nullptr;

        // Create a Room or finding a room
        // searching existing room
        for (auto &r : room)
        {
            if (r->room_name == rName)
            {
                target_room = r.get();
                break;
            }
        }
        // create a room if it doesnt exists
        if (!target_room)
        {
            room.push_back(std::make_unique<Room>(rName));
            target_room = room.back().get(); // if room is not found a new one is created
        }
        // add specific device into room
        if (type == "SecurityCamera")
            target_room->room_devices.push_back(std::make_unique<SecurityCamera>(extraInfo, "300W", dev_id, dName, brand));
        else if (type == "AirConditioning")
            target_room->room_devices.push_back(std::make_unique<AirConditioning>(std::stoi(extraInfo), dev_id, dName, brand));
        else if (type == "Projector")
            target_room->room_devices.push_back(std::make_unique<Projector>(extraInfo, 50, dev_id, dName, brand));
        else if (type == "RoomLighting")
            target_room->room_devices.push_back(std::make_unique<RoomLighting>(std::stoi(extraInfo), dev_id, dName, brand));
        else if (type == "DoorLock")
            target_room->room_devices.push_back(std::make_unique<DoorLock>(true, extraInfo, dev_id, dName, brand));
    }
}

void DeviceManager::RemoveRoomDevice()
{
    std::string roomName;
    std::cout << "Type the name of the room you want to remove the device from: (eg.SecurityRoom, Reception, MainHall):";
    std::getline(std::cin, roomName);

    Room *target_room = nullptr;

    for (auto &r : room)
    {
        if (r->room_name == roomName)
        {
            target_room = r.get();
            break;
        }
    }

    // Room doesnt exist
    if (!target_room)
    {
        std::cout << "Room doesnt exist!" << std::endl;
        return;
    }

    int target_id;
    std::cout << "Enter the ID of the device you want to remove from" << roomName << ": ";
    std::cin >> target_id;

    bool found = false;
    for (auto device = target_room->room_devices.begin(); device != target_room->room_devices.end();)
    {
        // dereferencing the device iterator to get the unique pointer and after accessing the device object
        if ((*device)->Get_id() == target_id)
        {
            device = target_room->room_devices.erase(device); // deletes the specific device which has the id that the user inputted, frees memory

            std::cout << "Device with ID: " << target_id << " was deleted succesfully!" << std::endl;
            found = true;
        }
        else
        {
            device++; // iterator advances to the next device, not possibility of crash
        }
    }
    if (!found)
    {
        std::cout << "Couldn't find a device with ID " << target_id << "inside " << roomName << "." << std::endl;
    }
}

void DeviceManager::AddRoomDevice()
{

    std::string roomName;
    std::cout << "Type the name of the room you want to add the device (eg.SecurityRoom, Reception, MainHall):";
    std::getline(std::cin, roomName);

    Room *target_room = nullptr;

    // searching for the room, if the room exists the user proceeds with adding the device to the room
    for (auto &r : room)
    {
        if (r->room_name == roomName)
        {
            target_room = r.get();
            break;
        }
    }

    // if the room doesnt exists the user needs to create it first to add the device
    if (!target_room)
    {
        std::cout << "Room doesnt exist! Please create a room!" << std::endl;
        return;
    }
    int device_type;

    std::cout << "[ID:1 - SecurityCamera]" << std::endl;
    std::cout << "[ID:2 - AirConditioning]" << std::endl;
    std::cout << "[ID:3 - Projector]" << std::endl;
    std::cout << "[ID:4 - RoomLighting]" << std::endl;
    std::cout << "[ID:5 - DoorLock]" << std::endl;
    std::cout << "Insert the ID of the device you want to add: ";
    std::cin >> device_type;
    if (device_type < 1 || device_type > 5)
    {
        std::cout << "Invalid device type! Please try again!" << std::endl;
        return;
    }
    int id;
    std::string device_name, device_brand;
    std::cout << "Device ID:";
    std::cin >> id;
    std::cout << "Device Name:";
    std::cin >> device_name;
    std::cout << "Device Brand:";
    std::cin >> device_brand;

    switch (device_type)
    {
    case 1:
        target_room->room_devices.push_back(std::make_unique<SecurityCamera>("720p", "100 wat", id, device_name, device_brand));
        break;

    case 2:
        target_room->room_devices.push_back(std::make_unique<AirConditioning>(22, id, device_name, device_brand));
        break;
    case 3:
        target_room->room_devices.push_back(std::make_unique<Projector>("wireless", 30, id, device_name, device_brand));
        break;
    case 4:
        target_room->room_devices.push_back(std::make_unique<RoomLighting>(40, id, device_name, device_brand));
        break;
    case 5:
        target_room->room_devices.push_back(std::make_unique<DoorLock>(true, "user", id, device_name, device_brand));
        break;
    default:
        std::cout << "Incorrect selection of a device" << std::endl;
        break;
    }
    std::cout << "Device added succesfully!" << std::endl;
}

void DeviceManager::ViewAllRooms()
{
    if (room.empty())
    {
        std::cout << "There are no devices inside the rooms yet.." << std::endl;
        return;
    }

    std::cout << "ROOM VIEW" << std::endl;

    // loop through each room
    for (auto &room : room)
    {
        std::cout << "ROOM: " << room->room_name << std::endl;

        if (room->room_devices.empty())
        {
            std::cout << "Room currenly empty!" << std::endl;
        }
        else
        {
            for (auto &device : room->room_devices)
            {
                device->ViewInfo();
                std::cout << "-----------------------------------------" << std::endl;
            }
        }
    }
}

void DeviceManager::CreateRoom()
{

    std::string room_name;
    std::cout << "Enter the name of the room you want to add: ";
    std::getline(std::cin, room_name);

    room.push_back(std::make_unique<Room>(room_name));

    std::cout << "ROOM " << room_name << " was added succesfully!" << std::endl;
}

// DESIGN PATTERN: Hybrid search
//  this function is treating the Global/Default devices and the room devices
//  as unified hierarchy, which it is looping/searching through the devices to find the target ID
void DeviceManager::DeviceSearch()
{
    int deviceSearch_id;
    std::cout << "[ID:1 - SecurityCamera]" << std::endl;
    std::cout << "[ID:2 - AirConditioning]" << std::endl;
    std::cout << "[ID:3 - Projector]" << std::endl;
    std::cout << "[ID:4 - RoomLighting]" << std::endl;
    std::cout << "[ID:5 - DoorLock]" << std::endl;
    std::cout << "Enter the ID of the device you want to search:";
    std::cin >> deviceSearch_id;
    if (deviceSearch_id < 1 || deviceSearch_id > 5)
    {
        std::cout << "Invalid device type! Please try again!" << std::endl;
        return;
    }

    Device *target_device = nullptr; // capture a device if found

    // bool device_found = false;

    // checks the default devices
    for (auto &dev : devices)
    {

        if (dev->Get_id() == deviceSearch_id)
        {
            target_device = dev.get(); // points to the global/default device
            break;
        }
    }

    if (target_device == nullptr)
    {
        for (auto &r : room)
        {
            for (auto &d : r->room_devices)
            {
                if (d->Get_id() == deviceSearch_id)
                {
                    target_device = d.get();
                    std::cout << "Device found in: " << r->room_name << std::endl;
                }
            }
            if (target_device != nullptr) // device found the search is stopped
                break;
        }
    }

    if (target_device != nullptr)
    {

        int search_choice;
        std::cout << "Device found: " << target_device->Get_name() << std::endl;
        std::cout << "1. Activate Device" << std::endl;
        std::cout << "2. Deactivate Device" << std::endl;
        std::cout << "3. Check Connection" << std::endl;
        std::cout << "4. Interaction event of the device" << std::endl;
        std::cout << "5. View Info of the device" << std::endl;
        std::cout << "Enter an option: ";
        std::cin >> search_choice;
        if (search_choice < 1 || search_choice > 5)
        {
            std::cout << "Invalid option! Please try again!" << std::endl;
            return;
        }

        switch (search_choice)
        {
        case 1:
            target_device->Activate(); // activate device
            break;

        case 2:
            target_device->Deactivate(); // Deactivate device
            break;

        case 3:
            target_device->CheckConnection(); // Check connection
            break;

        case 4:
            target_device->interaction_event(); // call the interaction event of the device
            break;

        case 5:
            target_device->ViewInfo(); // call the interaction event of the device
            break;
        }
    }
    else
    {
        std::cout << "Error! Device ID" << deviceSearch_id << " cannot be found" << std::endl;
    }
}

// device_found = true; // device was found

void DeviceManager::CheckConnection()
{
    int device_id;
    std::cout << "[ID:1 - SecurityCamera]" << std::endl;
    std::cout << "[ID:2 - AirConditioning]" << std::endl;
    std::cout << "[ID:3 - Projector]" << std::endl;
    std::cout << "[ID:4 - RoomLighting]" << std::endl;
    std::cout << "[ID:5 - DoorLock]" << std::endl;
    std::cout << "Enter a Device ID to change the connection status: ";
    std::cin >> device_id;
    if (device_id < 1 || device_id > 5)
    {
        std::cout << "Invalid option! Please try again!" << std::endl;
        return;
    }

    // loops through the vector, and displays the devices
    // dev->Get_id(), dev->Get_name(), displays the getter methods so the user understand with what devices it interacts
    for (auto &dev : devices)
    {
        // checks if device id are the same
        if (dev->Get_id() == device_id)
        {
            // saves the current status of the device (true/false) inside the variable current_state
            // if the device is online (true) it makes it offline (false).
            // instead of using a if-else statement this approach is much faster
            bool current_state = dev->CheckConnection();
            // status
            dev->SetConnection(!current_state);
            std::cout << dev->Get_name() << " connection is now: " << (!current_state ? "Online" : "Offline");
        }
    }
}

// loops through the vector, and displays the devices
// dev->Get_id(), dev->Get_name(), displays the getter methods so the user understand with what devices it interacts
void DeviceManager::CheckConnectionList()
{
    std::cout << "----- Connected Devices -----" << std::endl;
    for (auto &dev : devices)
    {
        if (dev->CheckConnection())
        {
            std::cout << "[ONLINE] ID: " << dev->Get_id() << " - " << dev->Get_name() << std::endl;
        }
    }
    std::cout << "----- Disconnected Devices -----" << std::endl;
    for (auto &dev : devices)
    {
        if (!dev->CheckConnection())
        {
            std::cout << "[OFFLINE] ID: " << dev->Get_id() << " - " << dev->Get_name() << std::endl;
        }
        // if (dev->CheckConnection() == false)
        // {
        //     std::cout << "The device ID: " << dev->Get_id() << " - " << dev->Get_name() << " " << " is Disconnected" << std::endl;
        // }
    }
}

void DeviceManager::AddDevice()
{
    int device_type;

    std::cout << "[ID:1 - SecurityCamera]" << std::endl;
    std::cout << "[ID:2 - AirConditioning]" << std::endl;
    std::cout << "[ID:3 - Projector]" << std::endl;
    std::cout << "[ID:4 - RoomLighting]" << std::endl;
    std::cout << "[ID:5 - DoorLock]" << std::endl;
    std::cout << "Insert the ID of the device you want to add: ";
    std::cin >> device_type;
    if (device_type < 1 || device_type > 5)
    {
        std::cout << "Invalid option! Please try again!" << std::endl;
        return;
    }

    std::string device_name, device_brand;
    int id;

    std::cout << "Enter Device ID: ";
    std::cin >> id;

    for (auto &dev : devices)
    {
        if (dev->Get_id() == id)
        {
            std::cout << "Device with the ID: " << id << " already exists, add another id" << std::endl;
            return;
        }
    }

    std::cout << "Enter Device Name: ";
    std::cin >> device_name;
    std::cout << "Enter Device Brand: ";
    std::cin >> device_brand;

    switch (device_type)
    {
    case 1:
        devices.push_back(std::make_unique<SecurityCamera>("720p", "100 wat", id, device_name, device_brand));
        break;

    case 2:
        devices.push_back(std::make_unique<AirConditioning>(22, id, device_name, device_brand));
        break;
    case 3:
        devices.push_back(std::make_unique<Projector>("wireless", 30, id, device_name, device_brand));
        break;
    case 4:
        devices.push_back(std::make_unique<RoomLighting>(40, id, device_name, device_brand));
        break;
    case 5:
        devices.push_back(std::make_unique<DoorLock>(true, "user", id, device_name, device_brand));
        break;
    default:
        std::cout << "Incorrect selection of a device" << std::endl;
        break;
    }
    std::cout << "Device added succesfully!" << std::endl;
}

void DeviceManager::DeleteDevice()

{
    int target_id;

    std::cout << "[ID:1 - SecurityCamera]" << std::endl;
    std::cout << "[ID:2 - AirConditioning]" << std::endl;
    std::cout << "[ID:3 - Projector]" << std::endl;
    std::cout << "[ID:4 - RoomLighting]" << std::endl;
    std::cout << "[ID:5 - DoorLock]" << std::endl;
    std::cout << "Select the device you want to delete :";
    std::cin >> target_id;

    // looping through the vector
    // auto lets the compilet to decide the device (iterator) type
    // the loop basically points to the first device inside the vector and stops after passing the last device
    for (auto device = devices.begin(); device != devices.end();)
    {
        // dereferencing the device iterator to get the unique pointer and after accessing the device object
        if ((*device)->Get_id() == target_id)
        {
            device = devices.erase(device); // deletes the specific device which has the id that the user inputted, frees memory

            std::cout << "Device with ID: " << target_id << " was deleted succesfully!" << std::endl;
        }
        else
        {
            device++; // iterator advances to the next device, not possibility of crash
        }
    }
}

void DeviceManager::EditDevice()
{
    int target_id;
    std::cout << "[ID:1 - SecurityCamera]" << std::endl;
    std::cout << "[ID:2 - AirConditioning]" << std::endl;
    std::cout << "[ID:3 - Projector]" << std::endl;
    std::cout << "[ID:4 - RoomLighting]" << std::endl;
    std::cout << "[ID:5 - DoorLock]" << std::endl;
    std::cout << "Enter the Device ID you want to edit: ";
    std::cin >> target_id;

    for (auto &dev : devices)
    {
        if (dev->Get_id() == target_id)
        {
            dev->EditDevice();
            std::cout << "Devices edited succesfully!" << std::endl;
        }
    }
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
        std::cout << "\n";
    }

    for (auto &r : room)
    {
        for (auto &d : r->room_devices)
        {
            d->Activate();

            std::cout << "\n";
        }
    }
    std::cout << "\n\nAll devices across the campus are activated!" << std::endl;
}

void DeviceManager::DeactivateAllDevices()
{

    // using auto for cleaner syntax and for the compiler to work out the element type in runtime
    for (auto &dev : devices)
    {
        dev->Deactivate();
        std::cout << "\n";
    }
    for (auto &r : room)
    {
        for (auto &d : r->room_devices)
        {
            d->Deactivate();
            std::cout << "\n";
        }
    }
    std::cout << "\n\nAll devices across the campus are deactivated!" << std::endl;
}

void DeviceManager::ShowMenu()
{

    std::cout << "\n\n====== Smart Campus Menu ======" << std::endl;
    std::cout << "1. View all devices" << std::endl;
    std::cout << "2. Interact with a device" << std::endl;
    std::cout << "3. Activate all devices" << std::endl;
    std::cout << "4. Deactivate all devices" << std::endl;
    std::cout << "5. Add device" << std::endl;
    std::cout << "6. Delete device" << std::endl;
    std::cout << "7. Edit device" << std::endl;
    std::cout << "8. Check Connection Status of devices (Online/Offline)" << std::endl;
    std::cout << "9. Trigger device connection" << std::endl;
    std::cout << "10. Search device" << std::endl;
    std::cout << "11. Create room" << std::endl;
    std::cout << "12. View all rooms" << std::endl;
    std::cout << "13. Add device inside a room" << std::endl;
    std::cout << "14. Remove device inside a room" << std::endl;
    std::cout << "15. Exit" << std::endl;
    std::cout << "Choose an option:";
}

// Here are where all the choices are being made via a switch statement
void DeviceManager::ChoiceHandling(int choice)
{
    switch (choice)
    {
    case 1:
        std::cout << " \n====== Default Device Information ====== \n"
                  << std::endl;
        // looping to show all the devices
        for (auto &d : devices)
        {
            d->ViewInfo();
            std::cout << "----------------------------" << std::endl;
        }

        std::cout << " \n====== Devices Found In Rooms ====== \n"
                  << std::endl;
        if (room.empty())
        {
            std::cout << "No rooms were loaded from the file" << std::endl;
        }
        else
        {
            ViewAllRooms();
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
        AddDevice();
        break;

    case 6:
        DeleteDevice();
        break;

    case 7:
        EditDevice();
        break;
    case 8:
        CheckConnectionList();
        break;
    case 9:
        CheckConnection();
        break;
    case 10:
        DeviceSearch();
        break;
    case 11:
        CreateRoom();
        break;

    case 12:
        ViewAllRooms();
        break;

    case 13:
        AddRoomDevice();
        break;
    case 14:
        RemoveRoomDevice();
        break;

    case 15:
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