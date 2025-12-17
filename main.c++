#include <iostream>
#include <string>
using namespace std;

class Device
{

protected:
    unsigned int unique_number_id;
    string device_name;
    string manufacturer;

public:
    // constructor to initialize parameters for Device
    Device(unsigned int id, string name, string manufacturer) : unique_number_id(id), device_name(name), manufacturer(manufacturer) {}

    // destructor is initialised for safe polymorphic deletion and ensures correct clean up=
    virtual ~Device() {}

    // this method will be called and override each class with the appropriate output
    virtual void interaction_event() = 0;
};

int main()
{
}