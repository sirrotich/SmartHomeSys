#ifndef LIGHT_H
#define LIGHT_H

#include "Device.h"

class Light : public Device {
private:
    int brightness;  // 0-100%

public:
    Light(const std::string& name, const std::string& location);
    ~Light() override;
    
    void setBrightness(int level);
    int getBrightness() const;
    void status() const override;
};

#endif
