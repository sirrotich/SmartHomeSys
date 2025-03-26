# Smart Home Automation System Documentation

## 1. Introduction

The Smart Home Automation System is a C++ application designed to manage and control various smart devices in a home environment. This system demonstrates object-oriented programming principles while providing a practical solution for home automation.

### 1.1 Purpose

This system allows users to:
- Add and remove smart devices
- Control devices individually
- Monitor device status
- Group devices by location
- Automate device operations

### 1.2 Scope

The current implementation includes support for:
- Smart lights with brightness control
- Thermostats with temperature monitoring and control
- Security cameras with recording capabilities

## 2. System Architecture

### 2.1 Class Hierarchy

The system follows an object-oriented design with a clear inheritance hierarchy:

```
Device (Base Class)
├── Light
├── Thermostat
└── SecurityCamera
```

The `SmartHome` class acts as a container and manager for all devices.

### 2.2 File Structure

- `Device.h/cpp`: Base class for all smart devices
- `Light.h/cpp`: Class for light devices
- `Thermostat.h/cpp`: Class for thermostat devices
- `SecurityCamera.h/cpp`: Class for security camera devices
- `SmartHome.h/cpp`: Class for managing all devices
- `Exceptions.h`: Custom exception classes
- `main.cpp`: Main application with user interface
- `Testing.cpp`: Comprehensive test suite

## 3. Class Descriptions

### 3.1 Device Class

The base class for all smart devices.

#### Attributes:
- `name`: String identifier for the device
- `isOn`: Boolean indicating power state
- `location`: String indicating where the device is located

#### Methods:
- `turnOn()`: Powers on the device
- `turnOff()`: Powers off the device
- `status()`: Displays current device status
- Getters for all attributes

### 3.2 Light Class

Represents a smart light with brightness control.

#### Attributes:
- Inherits all attributes from Device
- `brightness`: Integer (0-100) representing light intensity

#### Methods:
- Inherits all methods from Device
- `setBrightness(int)`: Sets the brightness level
- `getBrightness()`: Returns current brightness
- Overridden `status()` to include brightness information

### 3.3 Thermostat Class

Represents a smart thermostat for temperature control.

#### Attributes:
- Inherits all attributes from Device
- `temperature`: Current temperature reading
- `targetTemperature`: Desired temperature setting

#### Methods:
- Inherits all methods from Device
- `setTemperature(float)`: Sets current temperature
- `getTemperature()`: Returns current temperature
- `setTargetTemperature(float)`: Sets target temperature
- `getTargetTemperature()`: Returns target temperature
- Overridden `status()` to include temperature information

### 3.4 SecurityCamera Class

Represents a security camera with recording capabilities.

#### Attributes:
- Inherits all attributes from Device
- `isRecording`: Boolean indicating recording state
- `resolution`: Two-element array for width and height

#### Methods:
- Inherits all methods from Device
- `startRecording()`: Begins recording if camera is on
- `stopRecording()`: Stops recording
- `getIsRecording()`: Returns recording state
- `setResolution(int, int)`: Sets camera resolution
- Overridden `status()` to include recording and resolution information

### 3.5 SmartHome Class

Manages a collection of smart devices.

#### Attributes:
- `homeName`: String identifier for the home
- `devices`: Vector of Device pointers

#### Methods:
- `addDevice(Device*)`: Adds a device to the home
- `removeDevice(string)`: Removes a device by name
- `findDevice(string)`: Locates a device by name
- `listAllDevices()`: Displays all devices
- `turnAllOn()`: Powers on all devices
- `turnAllOff()`: Powers off all devices
- `operator+(Device*)`: Overloaded + operator to add devices
- `status()`: Displays status of all devices
- `status(string)`: Displays status of devices in a specific location

## 4. Exception Handling

The system implements custom exceptions for error handling:

- `DeviceNotFoundException`: Thrown when attempting to access a non-existent device
- `DeviceAlreadyExistsException`: Thrown when adding a device with a duplicate name
- `NullDeviceException`: Thrown when attempting to add a null device pointer

<!--     TO START THE APPLICATION  -->
# Starting the applicatio
- `g++ -std=c++11 -o SmartHomeSystem src/main.cpp src/Device.cpp src/Light.cpp src/Thermostat.cpp src/SecurityCamera.cpp src/SmartHome.cpp`

## 5. OOP Principles Demonstrated

### 5.1 Encapsulation
- Private data members with public accessor methods
- Implementation details hidden from users

### 5.2 Inheritance
- Device as base class
- Light, Thermostat, and SecurityCamera as derived classes
- Method overriding for specialized behavior

### 5.3 Polymorphism
- Virtual methods (status) with different implementations
- Dynamic casting to handle device-specific operations
- Operator overloading (+ operator in SmartHome)
- Function overloading (status method with different parameters)

### 5.4 Abstraction
- Device class provides a common interface
- Users interact with devices through this interface without knowing implementation details

## 6. Testing

The system includes a comprehensive test suite in `Testing.cpp` that verifies:
- Base class functionality
- Derived class specific features
- Exception handling
- Container class operations

## 7. User Guide

### 7.1 Adding a Device
1. Select "Add a device" from the main menu
2. Enter device name and location
3. Select device type (Light, Thermostat, or SecurityCamera)

### 7.2 Controlling Devices
1. Select "Control a device" from the main menu
2. Enter the device name
3. Use the device-specific control menu to operate the device

### 7.3 Viewing Device Status
- Select "Show status of all devices" to see all device statuses
- Select "Show status by location" to see devices in a specific area

## 8. Future Enhancements

Potential improvements for future versions:
- Additional device types (smart plugs, door locks, etc.)
- Device grouping and scenes
- Scheduling and automation rules
- User authentication and multiple user profiles
- Remote access capabilities
- Integration with real smart home protocols

## 9. Conclusion

The Smart Home Automation System demonstrates effective use of object-oriented programming principles to create a flexible and extensible solution for home automation. The modular design allows for easy addition of new device types and features in the future.
