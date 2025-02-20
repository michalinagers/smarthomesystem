#pragma once
#include "Devices.h"

class Speaker : public Devices
{
public:
    Speaker(const string& deviceName, const string& deviceType, bool deviceState, int volume);
    Speaker();
    void adjustDeviceVolume(int volume);
    void setDeviceVolume(int volume);
    bool getState() const override { return deviceState; };
    int getVolume() { return volume; };
    void turnOn();
    void turnOff();
    void oneClickAction() override;
    void fullFeatureDevice() override;
    void setState(bool deviceState);
    void quickView() override;
    string deviceInfo() override;


private:
    int volume; //To set the volume in integer 0-100
    bool deviceState;
    string devices;
};

