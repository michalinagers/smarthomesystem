#pragma once
#include "Devices.h"
#include <map>

class Radiator : public Devices
{
    public:
        Radiator(const string& deviceName, const string& deviceType, bool deviceState, float temp, map<int, string> schedule);
        Radiator();
        void setTemp(float temp);
        float getTemp() { return temp; };
        void quickView() override;
        void setSchedule(map<int, string> schedule);
        void turnOn() override;
        void turnOff() override;
        void oneClickAction() override;
        inline bool getState() const override { return deviceState; };
        string deviceInfo() override;
        void fullFeatureDevice() override;
        map<int, string> getSchedule() const;
        void setState(bool deviceState);



    private:
        float temp;
        map<int, string> schedule;
        bool deviceState;

};

