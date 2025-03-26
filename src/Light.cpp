#include "Light.h"
#include <iostream>

Light::Light(const std::string& name, const std::string& location)
    : Device(name, location), brightness(50) {
}

Light::~Light() {
    std::cout << "Light " << getName() << " destroyed" << std::endl;
}

void Light::setBrightness(int level) {
    if (level < 0) level = 0;
    if (level > 100) level = 100;
    
    brightness = level;
    std::cout << getName() << " brightness set to " << brightness << "%" << std::endl;
}

int Light::getBrightness() const {
    return brightness;
}

void Light::status() const {
    Device::status();
    if (getIsOn()) {
        std::cout << "Brightness: " << brightness << "%" << std::endl;
    }
}
