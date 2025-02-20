#include "Light.h"
#include "Devices.h"
#include <iostream>
#include <deque>
#include <fstream>
#include <string>

Light::Light(const string& deviceName,const string& deviceType, bool deviceState, int brightness, double timer) : Devices(deviceName, deviceType), deviceState(deviceState), brightness(brightness), timer(timer) {}
Light::Light() : deviceState(""), brightness(), timer() {}


void Light::adjustBrightness(int brightness) {
    if (brightness >= 0 && brightness <= 100) {
        this->brightness = brightness;
        cout << "Brightness set to " << this->brightness << endl;
    }
               
}

void Light::setBrightness(int brightness) {
    if (brightness >= 0 && brightness <= 100) { 
        this->brightness = brightness;
       
    }
    }

void Light::setState(bool deviceState) {
    if (deviceState == 1) {  
        this->deviceState = true;
    }
    else if (deviceState == 0) {
        this->deviceState = false;
    }
}

void Light::turnOn() { //Function for device turn on
    if (deviceState = true) {
        cout << "Light is already turned ON.\n";
    }
    else {

        cout << "Light is now turned ON.";

    }
}


void Light::turnOff() { //Function for device turn off
    if (deviceState = false) {
        cout << "Light is already turned OFF.\n";
    }
    else {
        cout << "Light is turned OFF.";

    }
}


string Light::deviceInfo() {
    return string(deviceState ? "0" : "1") + " " + to_string(brightness) + " " + to_string(timer);
}


void Light::quickView() {

        cout << "Light: " << brightness << "% Brightness\n" ;
        if (deviceState == 0) {
            cout << "Light: OFF\n";
        }
        else if (deviceState == 1) {
            cout << "Light: ON\n";
        }
     
}


void Light::oneClickAction() {
    if (!deviceState) {
        cout << "Device is OFF\n";
    }
    else if (deviceState){
        cout << "Device is ON.\n";
    }
    cout << "Press 1 to turn ON or 2 to turn OFF\n";
    int input2;
    cin >> input2;
    if (input2 == 1) {
        turnOn();
    }
    else if (input2 == 2) {
        turnOff();
    }
}

void Light::setSleepTimer(double timer) { //Function for setting timers
    this->timer = timer;
  
}

double Light::getSleepTimer() {
    cout << "Timer set for: " << timer << " minutes\n";
    return timer;
    
}

void Light::fullFeatureDevice() {

    cout << "\nInteract with the full feature set of the device:\n";
    cout << "1) Turn On\n";
    cout << "2) Turn Off\n";
    cout << "3) Adjust Brightness\n";
    cout << "4) Sleep Timer\n";
    cout << "5) Quick View\n";
    cout << "0) Go Back\n";

    int input;
    cin >> input;

    if (input == 1) {
        turnOn();
    }
    else if (input == 2) {
        turnOff();
    }
    else if (input == 3) {
        cout << "Brightness currently set to: " << brightness << endl;
        cout << "Choose brightness (0-100)\n" << endl;
        cin >> brightness;
        adjustBrightness(brightness);
    }
    else if (input == 4) {
        getSleepTimer();
    
    }
    else if (input == 5) {
        quickView();
    }

}

