#ifndef SMART_HOME_H
#define SMART_HOME_H

#include <vector>
#include <string>
#include "Device.h"
#include "Light.h"
#include "Thermostat.h"
#include "SecurityCamera.h"

class SmartHome {
private:
    std::string homeName;
    std::vector<Device*> devices;

public:
    SmartHome(const std::string& name);
    ~SmartHome();
    
    void addDevice(Device* device);
    void removeDevice(const std::string& deviceName);
    Device* findDevice(const std::string& deviceName);
    void listAllDevices() const;
    void turnAllOn();
    void turnAllOff();
    
    // Operator overloading
    SmartHome& operator+(Device* device);
    
    // Function overloading
    void status() const;
    void status(const std::string& location) const;
};

#endif
