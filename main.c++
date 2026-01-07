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

    DeviceManager manager;

    manager.RunProgram();
}