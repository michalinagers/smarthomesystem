#pragma once
#include <string>
#include <vector>

using namespace std;

class Devices

{
public:
   
    Devices(const string& deviceType, const string& deviceName);
    Devices();
    virtual ~Devices() {}
    void displayDevices(int index)const;
    void displayCategories(int index)const;
    string getDeviceType() const { return deviceType; };
    static bool sortDevices(Devices*& device1, Devices*& device2);
    string getDeviceName() const { return deviceName; };
    void setDeviceName(const string& name);
    void setDeviceType(const string& type);
    void displayDeviceName() const;
    virtual void fullFeatureDevice();
    virtual string deviceInfo() = 0;    // https://stackoverflow.com/questions/60273764/whats-the-use-of-ostream-os
    virtual void oneClickAction() = 0;  //Pure virtual functions
    virtual void turnOff() = 0;
    virtual void turnOn() = 0;
    virtual void quickView() = 0;
    virtual bool getState() const { return deviceState; };
    void print();

private:
    string deviceName;
    vector<Devices*> inventory;
    string deviceType;
    bool deviceState;
};

//Devices* creatingObjects(ifstream& file);


//void displayDevices(const Devices& device, int index);

