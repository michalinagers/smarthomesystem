#include "Radiator.h"
#include "Devices.h"
#include <iostream>

Radiator::Radiator(const string& deviceName, const string& deviceType, bool deviceState, float temp, map<int, string> schedule) : Devices(deviceName, deviceType), deviceState(deviceState), temp(temp), schedule(schedule) {}
Radiator::Radiator() : deviceState(), schedule(), temp() {}


void Radiator::setTemp(float temp) {
    if (temp > 0) {
       this->temp = temp;
    }
}

void Radiator::turnOn() { //Function for device turn on
    if (!deviceState) {
        deviceState = 1;
        cout << "Radiator is turned ON.\n";
    }
    else {
        cout << "Radiator is already ON.\n";
    }
}

void Radiator::turnOff() { //Function for device turn off
    if (deviceState) {
        deviceState = 0;
        cout << "Radiator is turned OFF.\n";
    }
    else {
        cout << "Radiator is already ON.\n";
    }
}

void Radiator::setState(bool deviceState) {
    if (deviceState == 1) {
        this->deviceState = true;
    }
    else if (deviceState == 0) {
        this->deviceState = false;
    }
}

void Radiator::setSchedule(map<int, string> schedule) {

    cout << "Choose one of the times to schedule" << endl;
    cout << "Once the time is scheduled, device will turn on for 3 hours at the given time" << endl;

    schedule[1] = "6am";
    schedule[2] = "9am";
    schedule[3] = "12pm";
    schedule[4] = "3pm";
    schedule[5] = "6pm";
    schedule[6] = "9pm";

    int input = 0;
    cin >> input;

    if (input >= 1 && input <= 6) {
        schedule[input];
    }

}

void Radiator::oneClickAction() {
    if (getState() == false) {
        cout << "Device is OFF.\n";
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

string Radiator::deviceInfo() {
    return string(deviceState ? "0" : "1") + " " + to_string(temp) + " " + (schedule.empty() ? "None" : to_string(schedule.begin()->first) + " " + schedule.begin()->second);

}

void Radiator::fullFeatureDevice() {

    cout << "\nInteract with the full feature set of the device:\n";
    cout << "1) Turn On\n";
    cout << "2) Turn Off\n";
    cout << "3) View Schedule\n";
    cout << "4) Temperature\n";
    cout << "5) Quick View \n";
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
        cout << "Schedule currently set to: ";
        for (auto it : schedule)
            cout << it.first << " " << it.second << endl;

        cout << "To change schedule, enter a time (for example 3 pm) or press '0' to go back.\n";
        cin >> input;
        setSchedule(schedule);

        }
   
    else if (input == 4) {
        cout << "Current temperature: " << getTemp(); 
        cout << " Enter temperature to set new temperature\n";
        cin >> temp;
        setTemp(temp);
        cout << getDeviceName() << "Radiator has been set to " << temp << "C\n";

    }
    else if (input == 5) {
        quickView();
    }
}

void Radiator::quickView() {

    if (deviceState == 0) {
        cout << "Radiator: OFF\n";
    }
    else if (deviceState == 1) {
        cout << "Radiator: ON\n";
    }

    cout << "Temperature: " << temp << "\n " << endl;

    for (const auto& it : schedule) {
        cout << "Scheduled for: " <<  it.first << " " << it.second << endl;
    }
}

map<int, string> Radiator::getSchedule() const {
    return schedule; 
}
