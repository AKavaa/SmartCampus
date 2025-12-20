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
    Device(unsigned int id, string name, string manufacturer, bool status) : unique_number_id(id), device_name(name), manufacturer(manufacturer) {}

    // destructor is initialised for safe polymorphic deletion and ensures correct clean up=
    virtual ~Device() {}

    // this method will be called and override each class with the appropriate output
    virtual void interaction_event() = 0;

    virtual void Active() = 0;
    virtual void Deactive() = 0;
};

class SecurityCamera : public Device
{
private:
    string camera_quality;
    string power;

public:
    SecurityCamera(string cam_quality, string pwr, unsigned int id, string name, string manufacturer) : Device(id, name, manufacturer, status), camera_quality(cam_quality), power(pwr) {}

    void interaction_event() override
    {
        cout << "Now viewing camera:" << device_name;
    }
};

class AirConditioning : public Device
{
private:
    unsigned int target_temperature;

public:
    AirConditioning(int target_temp, unsigned int id, string name, string manufacturer) : Device(id, name, manufacturer, status), target_temperature(target_temp) {}

    void interaction_event() override
    {
        cout << "Current Air Condition temperature: " << target_temperature << "°C" << endl;
        cout << "Set a new temperature: ";
        cin >> target_temperature;
        cout << "Target Temperature set to: " << target_temperature << endl;
    }
};

class Projector : public Device
{
private:
    string input_source;
    unsigned short brightness_level;

public:
    Projector(string input_src, unsigned short brightness_lvl, unsigned int id, string name, string manufacturer) : Device(id, name, manufacturer, status), input_source(input_src), brightness_level(brightness_lvl) {}

    void interaction_event()
    {
        // add the appropriate output
    }
};

class RoomLighting : public Device
{
private:
    unsigned int brightness_level;

public:
    RoomLighting(unsigned int brightness_lvl, unsigned int id, string name, string manufacturer) : Device(id, name, manufacturer, status), brightness_level(brightness_lvl) {}

    void interaction_event()
    {
        // add the appropriate output
    }
};

class DoorLock : public Device
{
private:
    bool locked;
    string last_opened;

public:
    DoorLock(bool locked, string last_opened, unsigned int id, string name, string manufacturer) : Device(id, name, manufacturer, status), locked(locked), last_opened(last_opened) {}

    void interaction_event()
    {
        // add the appropriate output
    }
};

int main()
{
}