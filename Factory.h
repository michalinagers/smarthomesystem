#pragma once
#include "Devices.h"
#include "Speaker.h"
#include "Light.h"
#include "HeatThermo.h"
#include "Radiator.h"
#include "TempSensor.h"

class Factory
{

public:
	static Devices* createDeviceInput(const string& deviceType, const string& deviceName, bool deviceState,
		int brightness, map<int, string> schedule, float temp, int heatBoost, int volume, double sleepTimer, int liveData, int historyData, int energyUse, int historyUse);


	/* static Devices* createLight(const string& devices, const string& deviceType, bool deviceState, int brightness);
	static Devices* createHeatThermo(const string& devices, const string& deviceType, bool deviceState, map<int, string> schedule, int heatBoost);
	static Devices* createSocketPlugs(const string& devices, const string& deviceType, bool deviceState, map<int, string> schedule);
	static Devices* createRadiator(const string& devices, const string& deviceType, bool deviceState, float temp, map<int, string> schedule);
	*/
	// static Devices* createRadiator(const string& devices, const string& deviceType, bool deviceState, float temp, map<int, string> schedule);
	// static Devices* createRadiator(const string& devices, const string& deviceType, bool deviceState, float temp, map<int, string> schedule);

};

