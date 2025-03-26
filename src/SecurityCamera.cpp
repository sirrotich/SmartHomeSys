#include "SecurityCamera.h"
#include <iostream>

SecurityCamera::SecurityCamera(const std::string& name, const std::string& location)
    : Device(name, location), isRecording(false) {
    resolution[0] = 1280; // width
    resolution[1] = 720;  // height
}

SecurityCamera::~SecurityCamera() {
    std::cout << "Security Camera " << getName() << " destroyed" << std::endl;
}

void SecurityCamera::startRecording() {
    if (!getIsOn()) {
        std::cout << "Cannot start recording, camera is off" << std::endl;
        return;
    }
    
    isRecording = true;
    std::cout << getName() << " started recording" << std::endl;
}

void SecurityCamera::stopRecording() {
    isRecording = false;
    std::cout << getName() << " stopped recording" << std::endl;
}

bool SecurityCamera::getIsRecording() const {
    return isRecording;
}

void SecurityCamera::setResolution(int width, int height) {
    resolution[0] = width;
    resolution[1] = height;
    std::cout << getName() << " resolution set to " << width << "x" << height << std::endl;
}

void SecurityCamera::status() const {
    Device::status();
    if (getIsOn()) {
        std::cout << "Recording: " << (isRecording ? "YES" : "NO") << std::endl;
        std::cout << "Resolution: " << resolution[0] << "x" << resolution[1] << std::endl;
    }
}
