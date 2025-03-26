#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "Device.h"

class Thermostat : public Device {
private:
    float temperature;
    float targetTemperature;

public:
    Thermostat(const std::string& name, const std::string& location);
    ~Thermostat() override;
    
    void setTemperature(float temp);
    float getTemperature() const;
    void setTargetTemperature(float temp);
    float getTargetTemperature() const;
    void status() const override;
};

#endif
