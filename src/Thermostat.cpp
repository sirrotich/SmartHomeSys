#include "Thermostat.h"
#include <iostream>

Thermostat::Thermostat(const std::string& name, const std::string& location)
    : Device(name, location), temperature(22.0), targetTemperature(22.0) {
}

Thermostat::~Thermostat() {
    std::cout << "Thermostat " << getName() << " destroyed" << std::endl;
}

void Thermostat::setTemperature(float temp) {
    temperature = temp;
    std::cout << getName() << " current temperature set to " << temperature << "°C" << std::endl;
}

float Thermostat::getTemperature() const {
    return temperature;
}

void Thermostat::setTargetTemperature(float temp) {
    targetTemperature = temp;
    std::cout << getName() << " target temperature set to " << targetTemperature << "°C" << std::endl;
}

float Thermostat::getTargetTemperature() const {
    return targetTemperature;
}

void Thermostat::status() const {
    Device::status();
    std::cout << "Current temperature: " << temperature << "°C" << std::endl;
    std::cout << "Target temperature: " << targetTemperature << "°C" << std::endl;
}
