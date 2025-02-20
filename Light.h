#pragma once
#include "Devices.h"
#include <string>

class Light : public Devices
{
    public:

        Light(const string& deviceName, const string& deviceType, bool deviceState, int brightness, double timer);
        Light();
        void adjustBrightness(int brightness);
        void setBrightness(int brightness);
        int getBrightness() { return brightness; };
        string deviceInfo() override;
        bool getState() const override { return deviceState; };
        void quickView() override;
        void turnOn() override;
        void turnOff() override;
        void setState(bool deviceState);
        void oneClickAction() override;
        double getSleepTimer();
        void setSleepTimer(double timer);
        void fullFeatureDevice() override;
       
        //void saveData() const;


    private: 
        int brightness;
        bool deviceState;
        double timer;
};

