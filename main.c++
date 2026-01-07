#include <iostream>
#include <string>
#include "Device.H"
#include "SecurityCamera.H"
#include "Projector.H"
#include "AirConditioning.H"
#include "RoomLighting.H"
#include "DeviceManager.h"
using namespace std;

int main()
{

    // int choice;

    // cout << "\n===== Start Smart Campus System =====" << endl;
    // cout << "1. Security Camera" << endl;
    // cout << "2. Air Condition" << endl;
    // cout << "3. Projector" << endl;
    // cout << "4. Room Lightning" << endl;
    // cout << "5. Door Lock" << endl;
    // cout << "0. Exit System" << endl;
    // cout << "Select Device :";
    // cin >> choice;

    DeviceManager manager;

    manager.RunProgram();

    manager.ShowMenu();
}