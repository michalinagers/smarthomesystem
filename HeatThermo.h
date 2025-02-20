#pragma once
#include "Devices.h"
#include <map>


class HeatThermo : public Devices

{
    public:
    HeatThermo(const string& deviceName, const string& deviceType, bool deviceState, map<int, string> schedule, int heatBoost);
    HeatThermo();
    void turnOn() override;
    void turnOff() override;
    void startBoost();
    void setSchedule(map<int, string> schedule);
    map<int, string> getSchedule() const;
    string deviceInfo() override;
    void quickView() override;
    void addSchedule(map<int, string> schedule);
    void oneClickAction() override;
    bool getState() const override { return deviceState; };
    void setState(bool deviceState);
    void fullFeatureDevice() override;
    void setHeatBoost(int heatBoost);


    private:
        bool deviceState;
        int heatBoost = 1;
        map<int, string> schedule;
        string userSchedule;

};

