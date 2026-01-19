#include "../HeaderFiles/Projector.H"
#include <iostream>

Projector::Projector(std::string input_src, unsigned short brightness_lvl, unsigned int id, std::string name, std::string manufacturer) : Device(id, name, manufacturer), input_source(input_src), brightness_level(brightness_lvl) {}

void Projector::ViewInfo()
{

    Device::ViewInfo(); // shows other details of a the device

    //   if (!status)
    //     {
    //         std::cout << "Current device is inactive!" << std::endl;
    //         return;
    //     }

    // std::cout << "Projector Control :" << device_name << std::endl;
    // std::cout << "Source input :" << input_source << std::endl;
    // std::cout << "Brightness input :" << brightness_level << "%" << std::endl;

    // int input_choice;
    // std::cout << "Choose Option:" << std::endl;
    // std::cout << "1. Change Input Source | 2. Adjust Brightness level" << std::endl;
    // std::cin >> input_choice;

    // if (input_choice == 1)
    // {
    //     std::cout << "Enter Input Source (HDMI, VGA, wireless):";
    //     std::cin >> input_source;
    //     std::cout << "Input Source changes to :" << input_source << std::endl;
    // }
    // else if (input_choice == 2)
    // {
    //     std::cout << "Enter Preferred Brightness Level (0 - 100%):" << std::endl;
    //     std::cin >> brightness_level;
    //     std::cout << " Brightness Level Set To : " << brightness_level << "%" << std::endl;
    // }
    // else
    // {
    //     std::cout << "Invalid option selected!" << std::endl;
    // }

    std::cout << "Source input :" << input_source << std::endl;
    std::cout << "Brightness input :" << brightness_level << "%" << "\n"
              << std::endl;
}
