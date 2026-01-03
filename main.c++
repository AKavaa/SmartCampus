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

    // if device is activated the appropriate message is shown
    void Activate()
    {
        status = true;
        cout << device_name << "is activated..";
    }

    // if device is deactivated the appropriate message is shown
    void Deactivate()
    {
        status = false;
        cout << device_name << "is deactivated.. ";
    }

    // this method will be called and override each class with the appropriate output
    virtual void interaction_event() = 0;
};

class SecurityCamera : public Device
{
private:
    string camera_quality;
    string power;

public:
    SecurityCamera(string cam_quality, string pwr, unsigned int id, string name, string manufacturer) : Device(id, name, manufacturer), camera_quality(cam_quality), power(pwr) {}

    void interaction_event() override
    {
        if (!status)
        {
            cout << "Current device is inactive!" << endl;
            return;
        }
        else
        {
            cout << "Now viewing camera:" << device_name;
        }
    }
};

class AirConditioning : public Device
{
private:
    unsigned int target_temperature;

public:
    AirConditioning(int target_temp, unsigned int id, string name, string manufacturer) : Device(id, name, manufacturer), target_temperature(target_temp) {}

    void interaction_event() override
    {
        if (!status)
        {
            cout << "Current device is inactive!" << endl;
            return;
        }
        else
        {
            cout << "Current Air Condition temperature: " << target_temperature << "°C" << endl;
            cout << "Set a new temperature: ";
            cin >> target_temperature;
            cout << "Target Temperature set to: " << target_temperature << endl;
        }
    }
};

class Projector : public Device
{
private:
    string input_source;
    unsigned short brightness_level;

public:
    Projector(string input_src, unsigned short brightness_lvl, unsigned int id, string name, string manufacturer) : Device(id, name, manufacturer), input_source(input_src), brightness_level(brightness_lvl) {}

    void interaction_event() override
    {
        if (!status)
        {
            cout << "Current device is inactive!" << endl;
            return;
        }
        else
        {
            cout << "Projector Control :" << device_name << endl;
            cout << "Source input :" << input_source << endl;
            cout << "Brightness input :" << brightness_level << "%" << endl;
        }

        int input_choice;
        cout << "Choose Option:" << endl;
        cout << "1. Change Input Source | 2. Adjust Brightness level" << endl;
        cin >> input_choice;

        if (input_choice == 1)
        {
            cout << "Enter Input Source (HDMI, VGA, wireless):";
            cin >> input_source;
            cout << "Input Source changes to :" << input_source << endl;
        }
        else if (input_choice == 2)
        {
            cout << "Enter Preferred Brightness Level (0 - 100%):" << endl;
            cin >> brightness_level;
            cout << " Brightness Level Set To : " << brightness_level << "%" << endl;
        }
        else
        {
            cout << "Invalid option selected!" << endl;
        }
    }
};

class RoomLighting : public Device
{
private:
    unsigned int brightness_level;

public:
    RoomLighting(unsigned int brightness_lvl, unsigned int id, string name, string manufacturer) : Device(id, name, manufacturer), brightness_level(brightness_lvl) {}

    void interaction_event()
    {
        if (!status)
        {
            cout << "Current device is inactive!" << endl;
            return;
        }
        else
        {
            // add the appropriate statement
        }
    }
};

class DoorLock : public Device
{
private:
    bool locked;
    string last_opened;

public:
    DoorLock(bool locked, string last_opened, unsigned int id, string name, string manufacturer) : Device(id, name, manufacturer), locked(locked), last_opened(last_opened) {}

    void interaction_event()
    {
        if (!status)
        {
            cout << "Current device is inactive!" << endl;
            return;
        }
        else
        {
            // add the appropriate statement
        }
    }
};

int main()
{
}