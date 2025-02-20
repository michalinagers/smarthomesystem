#pragma once
#include "Devices.h"
#include "Speaker.h"
#include "Radiator.h"
#include "HeatThermo.h"
#include "SocketPlugs.h"
#include "TempSensor.h"
#include "Light.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>

Devices::Devices(const string& deviceType, const string& deviceName) : deviceName(deviceName), deviceType(deviceType) {}

Devices::Devices() : deviceName(""), deviceType("") {}


void Devices::displayDevices(int index) const {
    cout << index + 1 << ". " << deviceName << endl;
}

void Devices::displayCategories(int index)const {
    cout << index + 1 << ". " << deviceType << endl;
}


bool Devices::sortDevices(Devices*& device1, Devices*& device2) {
    return (device1->deviceName) < (device2->deviceName);  // Returns true if string a is alphabetically less than string b

}

void Devices::displayDeviceName() const {

    cout << deviceName << endl;
}


void Devices::fullFeatureDevice() {
    cout << "\nInteract with the full feature set of the device:\n";
    cout << "1) Turn On\n";
    cout << "2) Turn Off\n";
    cout << "3) Adjust Brightness\n";
    cout << "4) Sleep Timer\n";
    cout << "4) Quick View\n";
    cout << "0) Go Back\n";
    cout << "Enter 'Delete device' to delete the device";
}

void Devices::setDeviceName(const string& name) {
    deviceName = name;
}

void Devices::setDeviceType(const string& type) {
    deviceType = type;
}

void Devices::print() {
    cout << deviceName << "" << deviceType << endl;
}
