#include "SmartHome.h"
#include "Exceptions.h"
#include <iostream>
#include <algorithm>

SmartHome::SmartHome(const std::string& name) : homeName(name) {
    std::cout << "Smart Home '" << homeName << "' created" << std::endl;
}

SmartHome::~SmartHome() {
    std::cout << "Smart Home '" << homeName << "' destroyed" << std::endl;
    for (Device* device : devices) {
        delete device;
    }
    devices.clear();
}

void SmartHome::addDevice(Device* device) {
    if (device == nullptr) {
        throw NullDeviceException();
    }
    
    for (Device* d : devices) {
        if (d->getName() == device->getName()) {
            throw DeviceAlreadyExistsException(device->getName());
        }
    }
    
    devices.push_back(device);
    std::cout << device->getName() << " added to " << homeName << std::endl;
}

void SmartHome::removeDevice(const std::string& deviceName) {
    auto it = std::find_if(devices.begin(), devices.end(), 
                          [&deviceName](Device* d) { return d->getName() == deviceName; });
    
    if (it != devices.end()) {
        delete *it;
        devices.erase(it);
        std::cout << deviceName << " removed from " << homeName << std::endl;
    } else {
        throw DeviceNotFoundException(deviceName);
    }
}

Device* SmartHome::findDevice(const std::string& deviceName) {
    for (Device* device : devices) {
        if (device->getName() == deviceName) {
            return device;
        }
    }
    throw DeviceNotFoundException(deviceName);
}

void SmartHome::listAllDevices() const {
    std::cout << "Devices in " << homeName << ":" << std::endl;
    if (devices.empty()) {
        std::cout << "  No devices found" << std::endl;
        return;
    }
    
    for (Device* device : devices) {
        std::cout << "  - " << device->getName() << " (" << device->getLocation() << ")" << std::endl;
    }
}

void SmartHome::turnAllOn() {
    for (Device* device : devices) {
        device->turnOn();
    }
}

void SmartHome::turnAllOff() {
    for (Device* device : devices) {
        device->turnOff();
    }
}

SmartHome& SmartHome::operator+(Device* device) {
    addDevice(device);
    return *this;
}

void SmartHome::status() const {
    std::cout << "Status of all devices in " << homeName << ":" << std::endl;
    for (Device* device : devices) {
        device->status();
        std::cout << "------------------------" << std::endl;
    }
}

void SmartHome::status(const std::string& location) const {
    std::cout << "Status of devices in " << location << ":" << std::endl;
    bool found = false;
    
    for (Device* device : devices) {
        if (device->getLocation() == location) {
            device->status();
            std::cout << "------------------------" << std::endl;
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No devices found in " << location << std::endl;
    }
}
