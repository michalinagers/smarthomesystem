#pragma once
#include "Devices.h"
#include <map>

class SocketPlugs : public Devices
{
    public:
    SocketPlugs(const string& deviceName, const string& deviceType, bool deviceState, map<int, string> schedule, double timer, int energyUse, int historyUse);
    SocketPlugs();
    void setSchedule(map<int, string> schedule);
    map<int, string> getSchedule() const;
    void setSleepTimer(double timer);
    void oneClickAction() override;
    void quickView() override;
    void turnOn() override;
    void turnOff() override;
    string deviceInfo() override;
    bool getState() const override { return deviceState; };
    void fullFeatureDevice() override;
    int getHistoricEnergy() { return historyUse; };
    int getLiveEnergy() { return energyUse; };
    void getSleepTimer();
    void setHistoricEnergy(int& historyUse);
    void setLiveEnergy(int& energyUse);
    void setState(bool deviceState);

    private:
    bool deviceState;
    map<int, string> schedule;
    double timer;
    int energyUse;
    int historyUse;

};

