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
    
    // Add a destructor with the same exception specification as the base class
    virtual ~DeviceNotFoundException() throw() {}
    
    virtual const char* what() const throw() {
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
    
    // Add a destructor with the same exception specification as the base class
    virtual ~DeviceAlreadyExistsException() throw() {}
    
    virtual const char* what() const throw() {
        return message.c_str();
    }
};

class NullDeviceException : public std::exception {
public:
    // Add a destructor with the same exception specification as the base class
    virtual ~NullDeviceException() throw() {}
    
    virtual const char* what() const throw() {
        return "Cannot add null device";
    }
};

#endif
