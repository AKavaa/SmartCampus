#include <iostream>
#include <string>
#include "HeaderFiles/Device.H"
#include "HeaderFiles/SecurityCamera.H"
#include "HeaderFiles/Projector.H"
#include "HeaderFiles/AirConditioning.H"
#include "HeaderFiles/RoomLighting.H"
#include "HeaderFiles/DeviceManager.h"
using namespace std;

int main()
{

    DeviceManager manager;

    manager.RunProgram();
}