#include "Factory.h"
#include "Speaker.h"
#include "Light.h"
#include "Devices.h"
#include "HeatThermo.h"
#include "SocketPlugs.h"
#include "TempSensor.h"
#include "Light.h"
#include "Speaker.h"
#include "Radiator.h"
#include <iostream>

Devices* Factory::createDeviceInput(const string& deviceType, const string& deviceName, bool deviceState, int brightness,
	map<int, string> schedule, float temp, int heatBoost, int volume, double timer, int liveData, int historyData, int energyUse, int historyUse) {

	cout << "Creating device: " << deviceName << ", Type: " << deviceType << endl;

	if (deviceType == "Speaker") {
		cout << "Do you want device to be turned off or on? Enter 0 for OFF and 1 for ON\n";
		cin >> deviceState;
		cout << "Enter device volume: \n";	
		cin >> volume;
		cout << "Device Name: " <<  deviceName << " Device Type: " << deviceType << " Device: " << deviceState << " Volume: " << volume << " has been added\n" << endl;
		return new Speaker("Speaker", deviceName, deviceState, volume);
	}
	else if (deviceType == "Light") {
		cout << "Do you want device to be turned off or on? Enter 0 for OFF and 1 for ON\n";
		cin >> deviceState;
		cout << "Enter device brightness: \n";
		cin >> brightness;
		cout << "Enter sleep timer or 0 for no sleep timer.";
		cin >> timer;
		cout << "Device Name: " << deviceName << " Device Type: " << deviceType << " Device: " << deviceState << " Brightness: " << brightness << "Sleep Timer: " << timer << "has been added\n" << endl;
		return new Light("Light", deviceName, deviceState, brightness, timer);
	}
	else if (deviceType == "HeatThermo") {
		cout << "Do you want device to be turned off or on? Enter 0 for OFF and 1 for ON\n";
		cin >> deviceState;
		cout << "Enter device schedule: \n";
		cout << "\nEnter the time: " << endl;
		cin >> schedule[1];
		cout << "Would you like heatboost on? Type 0 for no, 1 for yes\n";
		cin >> heatBoost;
		return new HeatThermo("HeatThermo",deviceName, deviceState, schedule, heatBoost);
	}
	else if (deviceType == "Radiator") {
		cout << "Do you want device to be turned off or on? Enter 0 for OFF and 1 for ON\n";
		cin >> deviceState;
		cout << "Enter temperature: \n";
		cin >> temp;
		return new Radiator("Radiator",deviceName, deviceState, temp, schedule);
	}
	else if (deviceType == "SocketPlugs") {
		cout << "Do you want device to be turned off or on? Enter 0 for OFF and 1 for ON\n";
		cin >> deviceState;
		cout << "Enter timer: \n";
		cin >> timer;
		return new SocketPlugs("SocketPlugs",deviceName, deviceState, schedule, timer, energyUse, historyUse);
	}
	else if (deviceType == "TempSensor") {
		cout << "Data will be calculated. Check full features for more.\n";
		cout << "Choose temperature: \n";
		cin >> temp;
		return new TempSensor("TempSensor", deviceName, liveData, historyData, temp);
	}
	else {
		return nullptr;
	}
}

