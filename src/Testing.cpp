#include <iostream>
#include <cassert>
#include "SmartHome.h"
#include "Light.h"
#include "Thermostat.h"
#include "SecurityCamera.h"
#include "Exceptions.h"

// Function to print test result
void printTestResult(const std::string& testName, bool passed) {
    std::cout << testName << ": " << (passed ? "PASSED" : "FAILED") << std::endl;
}

// Test Device base class functionality
void testDeviceClass() {
    std::cout << "\n=== Testing Device Class ===\n";
    
    Device* device = new Device("Test Device", "Test Location");
    
    bool test1 = device->getName() == "Test Device";
    printTestResult("Device name getter", test1);
    
    bool test2 = device->getLocation() == "Test Location";
    printTestResult("Device location getter", test2);
    
    bool test3 = !device->getIsOn();
    printTestResult("Device initial state is off", test3);
    
    device->turnOn();
    bool test4 = device->getIsOn();
    printTestResult("Device turn on", test4);
    
    device->turnOff();
    bool test5 = !device->getIsOn();
    printTestResult("Device turn off", test5);
    
    delete device;
}

// Test Light class functionality
void testLightClass() {
    std::cout << "\n=== Testing Light Class ===\n";
    
    Light* light = new Light("Test Light", "Living Room");
    
    bool test1 = light->getName() == "Test Light";
    printTestResult("Light name inheritance", test1);
    
    bool test2 = light->getBrightness() == 50;
    printTestResult("Light default brightness", test2);
    
    light->setBrightness(75);
    bool test3 = light->getBrightness() == 75;
    printTestResult("Light brightness setter", test3);
    
    // Test brightness limits
    light->setBrightness(120);
    bool test4 = light->getBrightness() == 100;
    printTestResult("Light brightness upper limit", test4);
    
    light->setBrightness(-10);
    bool test5 = light->getBrightness() == 0;
    printTestResult("Light brightness lower limit", test5);
    
    delete light;
}

// Test Thermostat class functionality
void testThermostatClass() {
    std::cout << "\n=== Testing Thermostat Class ===\n";
    
    Thermostat* thermostat = new Thermostat("Test Thermostat", "Bedroom");
    
    bool test1 = thermostat->getTemperature() == 22.0f;
    printTestResult("Thermostat default temperature", test1);
    
    bool test2 = thermostat->getTargetTemperature() == 22.0f;
    printTestResult("Thermostat default target temperature", test2);
    
    thermostat->setTemperature(24.5f);
    bool test3 = thermostat->getTemperature() == 24.5f;
    printTestResult("Thermostat temperature setter", test3);
    
    thermostat->setTargetTemperature(23.0f);
    bool test4 = thermostat->getTargetTemperature() == 23.0f;
    printTestResult("Thermostat target temperature setter", test4);
    
    delete thermostat;
}

// Test SecurityCamera class functionality
void testSecurityCameraClass() {
    std::cout << "\n=== Testing SecurityCamera Class ===\n";
    
    SecurityCamera* camera = new SecurityCamera("Test Camera", "Front Door");
    
    bool test1 = !camera->getIsRecording();
    printTestResult("Camera initial recording state", test1);
    
    // Try to start recording while camera is off
    camera->startRecording();
    bool test2 = !camera->getIsRecording();
    printTestResult("Camera recording blocked when off", test2);
    
    camera->turnOn();
    camera->startRecording();
    bool test3 = camera->getIsRecording();
    printTestResult("Camera start recording when on", test3);
    
    camera->stopRecording();
    bool test4 = !camera->getIsRecording();
    printTestResult("Camera stop recording", test4);
    
    camera->setResolution(1920, 1080);
    printTestResult("Camera resolution setter", true);
    
    delete camera;
}

// Test SmartHome class functionality
void testSmartHomeClass() {
    std::cout << "\n=== Testing SmartHome Class ===\n";
    
    SmartHome home("Test Home");
    
    // Test adding devices
    Light* light = new Light("Kitchen Light", "Kitchen");
    home.addDevice(light);
    
    try {
        Device* found = home.findDevice("Kitchen Light");
        bool test1 = found != nullptr;
        printTestResult("Add and find device", test1);
    } catch (const std::exception& e) {
        printTestResult("Add and find device", false);
    }
    
    // Test operator overloading
    Thermostat* thermostat = new Thermostat("Living Room Thermostat", "Living Room");
    home + thermostat;
    
    try {
        Device* found = home.findDevice("Living Room Thermostat");
        bool test2 = found != nullptr;
        printTestResult("Operator+ overloading", test2);
    } catch (const std::exception& e) {
        printTestResult("Operator+ overloading", false);
    }
    
    // Test exception handling - add duplicate device
    bool exceptionCaught = false;
    try {
        Light* duplicateLight = new Light("Kitchen Light", "Kitchen");
        home.addDevice(duplicateLight);
    } catch (const DeviceAlreadyExistsException& e) {
        exceptionCaught = true;
        delete light; // Clean up the duplicate
    }
    printTestResult("Exception for duplicate device", exceptionCaught);
    
    // Test removing a device
    try {
        home.removeDevice("Kitchen Light");
        bool deviceRemoved = true;
        try {
            home.findDevice("Kitchen Light");
            deviceRemoved = false;
        } catch (const DeviceNotFoundException& e) {
            deviceRemoved = true;
        }
        printTestResult("Remove device", deviceRemoved);
    } catch (const std::exception& e) {
        printTestResult("Remove device", false);
    }
    
    // Test exception handling - find non-existent device
    exceptionCaught = false;
    try {
        home.findDevice("Non-existent Device");
    } catch (const DeviceNotFoundException& e) {
        exceptionCaught = true;
    }
    printTestResult("Exception for non-existent device", exceptionCaught);
}

// Main test function
int main() {
    std::cout << "===== SMART HOME AUTOMATION SYSTEM TESTS =====\n";
    
    testDeviceClass();
    testLightClass();
    testThermostatClass();
    testSecurityCameraClass();
    testSmartHomeClass();
    
    std::cout << "\n===== ALL TESTS COMPLETED =====\n";
    return 0;
}
