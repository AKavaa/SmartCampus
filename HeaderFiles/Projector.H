#ifndef PROJECTOR_H
#define PROJECTOR_H

#include <iostream>
#include <string>
#include "Device.H"
using namespace std;

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

#endif