#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class DeviceNotFoundException : public std::exception {
private:
    std::string message;
    
public:
    DeviceNotFoundException(const std::string& deviceName) {
        message = "Device '" + deviceName + "' not found";
    }
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class DeviceAlreadyExistsException : public std::exception {
private:
    std::string message;
    
public:
    DeviceAlreadyExistsException(const std::string& deviceName) {
        message = "Device '" + deviceName + "' already exists";
    }
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class NullDeviceException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Cannot add null device";
    }
};

#endif
