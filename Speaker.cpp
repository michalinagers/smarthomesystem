#include "Speaker.h"
#include "Devices.h"
#include <iostream>
#include <fstream>

Speaker::Speaker(const string& deviceName, const string& deviceType, bool deviceState, int volume) : Devices(deviceName, deviceType), volume(volume) {}
Speaker::Speaker() : deviceState(), volume() {}



void Speaker::adjustDeviceVolume(int volume) {
    this->volume = volume;
    cout << "Volume set to " << this->volume << endl;
}


void Speaker::setDeviceVolume(int volume) {
    if (volume > 0) {
        this->volume = volume; 
    }
}

void Speaker::turnOn() { //Function for device turn on
    if (deviceState = true) {
        cout << "Speaker is already turned ON.\n";
    }
    else {

        cout << "Speaker is now turned ON.";

    }
}


void Speaker::turnOff() { //Function for device turn off
    if (deviceState = false) {
        cout << "Speaker is already turned OFF.\n";
    }
    else {
        cout << "Speaker is turned OFF.";

    }
}



void Speaker::oneClickAction() {
    if (getState() == false) {
        cout << "Device is OFF\n";
    }
    else {
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

void Speaker::fullFeatureDevice() {

    cout << "\nInteract with the full feature set of the device:\n";
    cout << "1) Turn On\n";
    cout << "2) Turn Off\n";
    cout << "3) Adjust Volume\n";
    cout << "4) Quick View\n";
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
        cout << "Volume currently set to: " << volume << endl;
        cout << "Choose volume (0-100)\n" << endl;
        cin >> volume;
        adjustDeviceVolume(volume);
    }
    else if (input == 4) {
        quickView();
    }
}


void Speaker::quickView() {

    cout << "Speaker: " << volume << " Volume \n";
    cout << "Speaker: " << (deviceState ? "ON" : "OFF") << " \n";

}

string Speaker::deviceInfo() {
    return string(deviceState ? "1" : "2") + " " + to_string(volume);
}

void Speaker::setState(bool deviceState) {
    if (deviceState == 1) {
        this->deviceState = true;
    }
    else if (deviceState == 0) {
        this->deviceState = false;
    }
}


