#include <iostream>
#include <string>
#include "SmartHome.h"
#include "Light.h"
#include "Thermostat.h"
#include "SecurityCamera.h"
#include "Exceptions.h"

// Function to display menu
void displayMenu() {
    std::cout << "\n===== Smart Home Automation System =====\n";
    std::cout << "1. Add a device\n";
    std::cout << "2. Remove a device\n";
    std::cout << "3. List all devices\n";
    std::cout << "4. Control a device\n";
    std::cout << "5. Turn all devices on\n";
    std::cout << "6. Turn all devices off\n";
    std::cout << "7. Show status of all devices\n";
    std::cout << "8. Show status by location\n";
    std::cout << "0. Exit\n";
    std::cout << "Choice: ";
}

// Function to display device types menu
void displayDeviceTypesMenu() {
    std::cout << "\nSelect device type:\n";
    std::cout << "1. Light\n";
    std::cout << "2. Thermostat\n";
    std::cout << "3. Security Camera\n";
    std::cout << "Choice: ";
}

// Function to display control menu for a light
void displayLightControlMenu() {
    std::cout << "\nLight Control:\n";
    std::cout << "1. Turn On\n";
    std::cout << "2. Turn Off\n";
    std::cout << "3. Set Brightness\n";
    std::cout << "4. Show Status\n";
    std::cout << "0. Back\n";
    std::cout << "Choice: ";
}

// Function to display control menu for a thermostat
void displayThermostatControlMenu() {
    std::cout << "\nThermostat Control:\n";
    std::cout << "1. Turn On\n";
    std::cout << "2. Turn Off\n";
    std::cout << "3. Set Current Temperature\n";
    std::cout << "4. Set Target Temperature\n";
    std::cout << "5. Show Status\n";
    std::cout << "0. Back\n";
    std::cout << "Choice: ";
}

// Function to display control menu for a security camera
void displayCameraControlMenu() {
    std::cout << "\nSecurity Camera Control:\n";
    std::cout << "1. Turn On\n";
    std::cout << "2. Turn Off\n";
    std::cout << "3. Start Recording\n";
    std::cout << "4. Stop Recording\n";
    std::cout << "5. Set Resolution\n";
    std::cout << "6. Show Status\n";
    std::cout << "0. Back\n";
    std::cout << "Choice: ";
}

int main() {
    // Create a smart home
    SmartHome myHome("My Smart Home");
    
    // Example devices for demonstration
    myHome.addDevice(new Light("Living Room Light", "Living Room"));
    myHome.addDevice(new Thermostat("Main Thermostat", "Hallway"));
    myHome.addDevice(new SecurityCamera("Front Door Camera", "Entrance"));
    
    int choice = -1;
    
    while (choice != 0) {
        displayMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1: { // Add a device
                std::string name, location;
                int deviceType;
                
                std::cout << "Enter device name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                
                std::cout << "Enter device location: ";
                std::getline(std::cin, location);
                
                displayDeviceTypesMenu();
                std::cin >> deviceType;
                
                Device* newDevice = nullptr;
                
                switch (deviceType) {
                    case 1:
                        newDevice = new Light(name, location);
                        break;
                    case 2:
                        newDevice = new Thermostat(name, location);
                        break;
                    case 3:
                        newDevice = new SecurityCamera(name, location);
                        break;
                    default:
                        std::cout << "Invalid device type!" << std::endl;
                        continue;
                }
                
                try {
                    myHome + newDevice; // Using operator overloading
                } catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                    delete newDevice; // Clean up if we couldn't add it
                }
                break;
            }
            
            case 2: { // Remove a device
                std::string name;
                std::cout << "Enter device name to remove: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                
                try {
                    myHome.removeDevice(name);
                } catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            
            case 3: // List all devices
                myHome.listAllDevices();
                break;
                
            case 4: { // Control a device
                std::string name;
                std::cout << "Enter device name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                
                try {
                    Device* device = myHome.findDevice(name);
                    
                    // Check device type and show appropriate control menu
                    Light* light = dynamic_cast<Light*>(device);
                    Thermostat* thermostat = dynamic_cast<Thermostat*>(device);
                    SecurityCamera* camera = dynamic_cast<SecurityCamera*>(device);
                    
                    int controlChoice = -1;
                    
                    if (light) {
                        while (controlChoice != 0) {
                            displayLightControlMenu();
                            std::cin >> controlChoice;
                            
                            switch (controlChoice) {
                                case 1: light->turnOn(); break;
                                case 2: light->turnOff(); break;
                                case 3: {
                                    int brightness;
                                    std::cout << "Enter brightness (0-100): ";
                                    std::cin >> brightness;
                                    light->setBrightness(brightness);
                                    break;
                                }
                                case 4: light->status(); break;
                                case 0: break;
                                default: std::cout << "Invalid choice!" << std::endl;
                            }
                        }
                    } else if (thermostat) {
                        while (controlChoice != 0) {
                            displayThermostatControlMenu();
                            std::cin >> controlChoice;
                            
                            switch (controlChoice) {
                                case 1: thermostat->turnOn(); break;
                                case 2: thermostat->turnOff(); break;
                                case 3: {
                                    float temp;
                                    std::cout << "Enter current temperature: ";
                                    std::cin >> temp;
                                    thermostat->setTemperature(temp);
                                    break;
                                }
                                case 4: {
                                    float temp;
                                    std::cout << "Enter target temperature: ";
                                    std::cin >> temp;
                                    thermostat->setTargetTemperature(temp);
                                    break;
                                }
                                case 5: thermostat->status(); break;
                                case 0: break;
                                default: std::cout << "Invalid choice!" << std::endl;
                            }
                        }
                    } else if (camera) {
                        while (controlChoice != 0) {
                            displayCameraControlMenu();
                            std::cin >> controlChoice;
                            
                            switch (controlChoice) {
                                case 1: camera->turnOn(); break;
                                case 2: camera->turnOff(); break;
                                case 3: camera->startRecording(); break;
                                case 4: camera->stopRecording(); break;
                                case 5: {
                                    int width, height;
                                    std::cout << "Enter width: ";
                                    std::cin >> width;
                                    std::cout << "Enter height: ";
                                    std::cin >> height;
                                    camera->setResolution(width, height);
                                    break;
                                }
                                case 6: camera->status(); break;
                                case 0: break;
                                default: std::cout << "Invalid choice!" << std::endl;
                            }
                        }
                    }
                } catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            
            case 5: // Turn all devices on
                myHome.turnAllOn();
                break;
                
            case 6: // Turn all devices off
                myHome.turnAllOff();
                break;
                
            case 7: // Show status of all devices
                myHome.status();
                break;
                
            case 8: { // Show status by location
                std::string location;
                std::cout << "Enter location: ";
                std::cin.ignore();
                std::getline(std::cin, location);
                myHome.status(location);
                break;
            }
            
            case 0: // Exit
                std::cout << "Exiting Smart Home Automation System. Goodbye!" << std::endl;
                break;
                
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    }
    
    return 0;
}

