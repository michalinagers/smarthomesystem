#include "SocketPlugs.h"
#include "Devices.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>

// do live and historic constructor

SocketPlugs::SocketPlugs(const string& deviceName, const string& deviceType, bool deviceState, map<int, string> schedule, double timer, int energyUse, int historyUse) : Devices(deviceName, deviceType), deviceState(deviceState), schedule(schedule), timer(timer) {}
SocketPlugs::SocketPlugs() : deviceState(), schedule(), timer(), historyUse(), energyUse() {}

void SocketPlugs::turnOn() { //Function for device turn on
    if (deviceState = true) {
        cout << "Light is already turned ON.\n";
    }
    else {

        cout << "Light is now turned ON.";

    }
}


void SocketPlugs::turnOff() { //Function for device turn off
    if (deviceState = false) {
        cout << "Light is already turned OFF.\n";
    }
    else {
        cout << "Light is turned OFF.";

    }
}

void SocketPlugs::setSchedule(map<int, string> schedule) {

    cout << "Choose one of the times to schedule" << endl;
    cout << "Once the time is scheduled, device will turn on for 3 hours at the given time" << endl;

    schedule[1] = 6, "am";
    schedule[2] = 9, "am";
    schedule[3] = 12, "pm";
    schedule[4] = 3, "pm";
    schedule[5] = 6, "pm";
    schedule[6] = 9, "pm";

    cout << "Schedules: \n" << "1. " << schedule[1] << "\n 2. " << schedule[2] << "\n 3. " << schedule[3] << "\n 4. " << schedule[4] << "\n 5. " << schedule[5] << "\n6. " << schedule[6] << endl;

    for (auto it : schedule)
        cout << it.first << ": " << it.second << endl;   //https://www.geeksforgeeks.org/how-to-create-a-dictionary-in-cpp/ Here I have learned how to read the dictionary in the console
}

map<int, string> SocketPlugs::getSchedule() const {
    return schedule; 
}

void SocketPlugs::oneClickAction() {
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

string SocketPlugs::deviceInfo() {
    return string(deviceState ? "0" : "1") + " " + (schedule.empty() ? "None" : to_string(schedule.begin()->first) + " " + schedule.begin()->second) + " " + to_string(timer) + " " + to_string(energyUse) + " " + to_string(historyUse);
}

void SocketPlugs::fullFeatureDevice() {

    cout << "\nInteract with the full feature set of the device:\n";
    cout << "1) Turn On\n";
    cout << "2) Turn Off\n";
    cout << "3) View Schedule\n";
    cout << "4) Sleep Timer\n";
    cout << "5) Live and Historic Energy Usage\n";
    cout << "6) Quick View\n";
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

            cout << "Set schedule: \n";
            cin >> input;
            getState();
            setSchedule(schedule);
        }
    
    else if (input == 4) {
        getSleepTimer();
        cout << "To set a sleep timer, choose how long you would like to set it for: ";
        cin >> timer;
        cout << "Timer set for " << timer << " minutes\n";
    }
    else if (input == 5) {
        cout << "Historic Energy Usage: " << getHistoricEnergy() << "\n";
        cout << "Live Energy Usage: " << getLiveEnergy();
    }
    else if (input == 6) {
        quickView();
    }
}

void SocketPlugs::setSleepTimer(double timer) { //Function for setting timers
    if (timer > 0) {
        this->timer = timer;  
    }
}


void SocketPlugs::setHistoricEnergy(int& historyUse) {      //Randomized historic data

    srand((unsigned)time(NULL));

    historyUse = rand() % 30 + 17;    //Temperature between 17-30
    this->historyUse = historyUse;


}

void SocketPlugs::setLiveEnergy(int& energyUse) {   //Randomized live data

    srand((unsigned)time(NULL));

    energyUse = rand() % 30 + 17;
    this->energyUse = energyUse;

}

void SocketPlugs::quickView() {

    if (deviceState == 0) {
        cout << "Socket / Plug : OFF\n";
    }
    else if (deviceState == 1) {
        cout << "Socket / Plug : ON\n";
    }
    for (const auto& it : schedule) {
        cout << "Scheduled for: " << it.first << " " << it.second << endl;
    }
    cout << "Sleep timer: " << timer << " minutes.\n";
    cout << "Live energy usage: " << energyUse;
    cout << "\nHistoric energy usage: " << historyUse;
}


void SocketPlugs::setState(bool deviceState) {
    if (deviceState == 1) {
        this->deviceState = true;
    }
    else if (deviceState == 0) {
        this->deviceState = false;
    }
}


void SocketPlugs::getSleepTimer() { //Function for setting timers
    if (timer > 0) {
        cout << "Sleep timer is set for: " << timer << "minutes. "; 
    }
    else {
        cout << "Sleep timer is turned off.";
    }
}
