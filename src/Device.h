#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class Device {
protected:
    std::string name;
    bool isOn;
    std::string location;

public:
    Device(const std::string& name, const std::string& location);
    virtual ~Device();
    
    virtual void turnOn();
    virtual void turnOff();
    virtual void status() const;
    
    std::string getName() const;
    bool getIsOn() const;
    std::string getLocation() const;
};

#endif
