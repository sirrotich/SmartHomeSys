#ifndef SECURITY_CAMERA_H
#define SECURITY_CAMERA_H

#include "Device.h"

class SecurityCamera : public Device {
private:
    bool isRecording;
    int resolution[2]; // width, height

public:
    SecurityCamera(const std::string& name, const std::string& location);
    ~SecurityCamera() override;
    
    void startRecording();
    void stopRecording();
    bool getIsRecording() const;
    void setResolution(int width, int height);
    void status() const override;
};

#endif
