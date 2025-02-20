#pragma once
#include "Devices.h"

class TempSensor : public Devices
{
    public: 
        TempSensor(const string& deviceName, const string& deviceType, int liveData, int historyData, float temp);
        TempSensor();
        void fullFeatureDevice() override;
        void quickView() override;
        void turnOn() override;
        void turnOff() override;
        float getTemp() { return temp; };
        void setTemp(float temp);
        // double getHumid() { return humid; };
        //void setHumid(double humid);
        string deviceInfo() override;
        void setHistoricData(int &historyData);
        void setLiveData(int &liveData);
        int getHistoricData() { return historyData; };
        int getLiveData() { return liveData; };
        void oneClickAction() override;



    private:
        bool deviceState = false;
        // double humid;
        float temp;
        int liveData;
        int historyData;



};

