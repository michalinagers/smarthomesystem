#include "HeatThermo.h"
#include "Devices.h"
#include <deque>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


HeatThermo::HeatThermo(const string& deviceName, const string& deviceType, bool deviceState, map<int, string> schedule, int heatBoost)
    : Devices(deviceName, deviceType), deviceState(deviceState), schedule(schedule), heatBoost(heatBoost) {
}

HeatThermo::HeatThermo() : deviceState(), schedule() {}  //default constructors


void HeatThermo::turnOn() { //Function for device turn on
    if (deviceState == true) {
        cout << "Thermostat is already turned ON.\n";
    }
    else {

        cout << "Thermostat is now turned ON.";

    }
}


void HeatThermo::turnOff() { //Function for device turn off
    if (deviceState == false) {
        cout << "Thermostat is already turned OFF.\n";
    }
    else {
        cout << "Thermostat is turned OFF.";

    }
}

void HeatThermo::startBoost() {
    int boost = +1;
    if (heatBoost == 1) {
        cout << "Heat boost is already on\n";
    }
    else {
        cout << "Boost has been added.";
        cout << "Heat boost will now be on for an hour.\n";
    }
}

map<int, string> HeatThermo::getSchedule() const {
    return schedule; 
}

void HeatThermo::setState(bool deviceState) {
    if (deviceState == 1) {
        this->deviceState = true;
    }
    else if (deviceState == 0) {
        this->deviceState = false;
    }
}

void HeatThermo::setHeatBoost(int heatBoost) {
    if (int heatBoost = 1) {
        heatBoost = true;
    }
    else if (int heatBoost = 0) {
        heatBoost = false;
    }
}


void HeatThermo::setSchedule(map<int, string> schedule) {

    cout << "Choose one of the times to schedule" << endl;
    cout << "Once the time is scheduled, device will turn on for 3 hours at the given time" << endl;

    schedule[1] = "6am";
    schedule[2] = "9am";
    schedule[3] = "12pm";
    schedule[4] = "3pm";
    schedule[5] = "6pm";
    schedule[6] = "9pm";

    for (auto it : schedule)
        cout << it.first << ". " << it.second << endl;

    cout << "Choose one of the time to schedule the device: \n";
    cin >> userSchedule;

}

void HeatThermo::addSchedule(map<int, string> schedule) {

    this->userSchedule = userSchedule;
}

void HeatThermo::oneClickAction() {
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

void HeatThermo::fullFeatureDevice() {

    cout << "\nInteract with the full feature set of the device:\n";
    cout << "1) Turn On\n";
    cout << "2) Turn Off\n";
    cout << "3) View Schedule\n";
    cout << "4) Heating Boost\n";
    cout << "5) Quick View\n";
    cout << "6) Delete device\n";
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
        cout << "Schedule currently set for: " << userSchedule << "\n";
        setSchedule(schedule);
    }
    else if (input == 4) {
        startBoost();
    }

}

void HeatThermo::quickView() {

    if (deviceState == 0) {
        cout << "Radiator: OFF\n";
    }
    else if (deviceState == 1) {
        cout << "Radiator: ON\n";
    }

    for (const auto& it : schedule) {
        cout << "Scheduled for: " << it.first << " " << it.second << endl;
    }

    cout << "Heat boost: " << heatBoost;
}

string HeatThermo::deviceInfo()  {
    return string(deviceState ? "0 " : "1 ") + userSchedule + " " + to_string(heatBoost);
}