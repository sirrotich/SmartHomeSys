#include "Device.h"
#include <iostream>

Device::Device(const std::string& name, const std::string& location) 
    : name(name), isOn(false), location(location) {
    std::cout << "Device " << name << " created in " << location << std::endl;
}

Device::~Device() {
    std::cout << "Device " << name << " destroyed" << std::endl;
}

void Device::turnOn() {
    isOn = true;
    std::cout << name << " turned on" << std::endl;
}

void Device::turnOff() {
    isOn = false;
    std::cout << name << " turned off" << std::endl;
}

void Device::status() const {
    std::cout << name << " in " << location << " is " 
              << (isOn ? "ON" : "OFF") << std::endl;
}

std::string Device::getName() const {
    return name;
}

bool Device::getIsOn() const {
    return isOn;
}

std::string Device::getLocation() const {
    return location;
}
