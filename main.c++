#include <iostream>
#include <string>
#include "Device.H"
#include "SecurityCamera.H"
#include "Projector.H"
#include "AirConditioning.H"
#include "RoomLighting.H"
using namespace std;

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

    int choice;

    cout << "\n===== Start Smart Campus System =====" << endl;
    cout << "1. Security Camera" << endl;
    cout << "2. Air Condition" << endl;
    cout << "3. Projector" << endl;
    cout << "4. Room Lightning" << endl;
    cout << "5. Door Lock" << endl;
    cout << "0. Exit System" << endl;
    cout << "Select Device :" << endl;
    cin >> choice;
}