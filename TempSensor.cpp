#include "TempSensor.h"
#include "Devices.h"
#include <iostream>

TempSensor::TempSensor(const string& deviceName, const string& deviceType, int liveData, int historyData, float temp)
    : Devices(deviceName, deviceType), liveData(liveData), historyData(historyData), temp(temp) {}
TempSensor::TempSensor() : liveData(0), historyData(0), temp(0){}

void TempSensor::quickView() {
    cout << "Live Data: " << liveData << " \n";
    cout << "History Data: " << historyData << " \n";
}

void TempSensor::turnOn() { //Function for device turn on
    if (!deviceState) {
        cout << "Temperature Sensor is turned ON.\n";
    }
}

void TempSensor::turnOff() { //Function for device turn off
    if (deviceState) {
        cout << "Temperature Sensor is turned ON.";
    }
}


void TempSensor::setTemp(float temp) {    //Setting temperature
    if (temp >= 0) {
        this->temp = temp;
    }
}

/*
void TempSensor::setHumid(double humid) {     //Setting humidity
    srand((unsigned)time(NULL));

    humid = rand() % 100 + 1;    //Humidity between 1 and 100
    this->humid = humid;             
    }
    */

void TempSensor::setHistoricData(int &historyData) {      //Randomized historic data

    srand((unsigned)time(NULL));

    historyData = rand() % 30 + 17;    //Temperature between 17-30
    this->historyData = historyData;

    //cout << "Historic Energy Usage is: " << historyData << " kWh\n";

}

void TempSensor::setLiveData(int &liveData) {   //Randomized live data

    srand((unsigned)time(NULL));

    liveData = rand() % 30 + 17;
    this->liveData = liveData;
    //cout << "Live Energy Usage is: " << liveData << " kWh\n";

}

void TempSensor::fullFeatureDevice() {

    cout << "\nInteract with the full feature set of the device:\n";
    cout << "1) Live Data\n";
    cout << "2) Historic Data\n";
    cout << "3) Quick View\n";
    cout << "0) Go Back\n";

    int input;
    cin >> input;

    if (input == 1) {

        cout << "Live Data: " << getLiveData() << "\n";
    }
    else if (input == 2) {
        cout << "Historic Data: " << getHistoricData() << "\n";
    }
    else if (input == 3) {
        quickView();
    }

}

string TempSensor::deviceInfo() {    //Device information which will be inserted into text file once user quits the console

    return string(deviceState ? "0" : "1") + " " + to_string(liveData) + " " + to_string(historyData);
}


//void TempSensor::oneClickAction() {
//
 //   cout << getDeviceName() << ": " << temp << " / " << humid << endl;
//}

void TempSensor::oneClickAction() {

    cout << getDeviceName() << ": " << temp << endl;
}


