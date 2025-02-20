#include <iostream>
#include <string>
#include "Devices.h" 
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include "Factory.h"
#include "Radiator.h"
#include "TempSensor.h"
#include "SocketPlugs.h"

using namespace std;

// Function declarations
void displayMainMenu();
void ListDevices(vector<Devices*>& inventory);  // Pass inventory functions
void NameSort(vector<Devices*>& inventory);
void Categories(vector<Devices*>& inventory);
void FullFeatureDevice(vector<Devices*>& inventory);
void AddDevice(vector<Devices*>& inventory);
void goBack();
void saveToFile(vector<Devices*>& inventory);
void printDevices(vector<Devices*> inventory);
bool caseInsensitive(string& input, string& deviceName);
void DeleteDevice(vector<Devices*>& inventory);
void createObjects(ifstream& file, vector<Devices*>& inventory);


int main() {

#ifdef _DEBUG
    onexit(_CrtDumpMemoryLeaks);
#endif

    vector<Devices*> inventory;

    ifstream file("APdevices.txt");

    if (file.is_open()) {
        createObjects(file, inventory);
        file.close();
    }
  
    // Print the inventory for debugging to check if objects have been created correctly
    /*
    for (const auto& device : inventory) {
        if (dynamic_cast<Devices*>(device)) {
            cout << device->getDeviceType() << " " << device->getDeviceName() << endl;
        }
        else {
            return 0;
        }

    }
    */


    while (true) {  // Infinite loop until input = 7
        displayMainMenu(); // Display the main menu each time
        string input;
        getline(cin, input);  // Read input as a string

        bool isDigit = !input.empty() && all_of(input.begin(), input.end(), ::isdigit); // Check if input is an integer https://en.cppreference.com/w/cpp/string/byte/isdigit Here I have learned how to use a function which checks whether its a digit or a string.
        void (*operation[7])(vector<Devices*>&) = { nullptr, &ListDevices, &NameSort, &Categories, &FullFeatureDevice, &AddDevice, &DeleteDevice };

        if (isDigit) {                  
            int digit = stoi(input); // Convert to integer        https://www.geeksforgeeks.org/stdstoi-function-in-cpp/ On this website I have learned on how to use stoi to convert from string to integer
            if (digit >= 1 && digit <= 6) {
                operation[digit](inventory);
            }
            else if (digit == 7) {
                saveToFile(inventory); // Save before exiting
                break;  // Quit
            }
            else if (digit < 1 || digit > 7) {
                cout << "Invalid input. Please select a valid menu choice (1 to 7).\n";
            }
        }
        else {
            bool found = false;
            for (Devices* device : inventory) {
                if (device->getDeviceName() == input) {
                    dynamic_cast<Devices*>(device)->oneClickAction();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Device not found.\n";
            }
            goBack();
        }
    }

    // Clean up allocated memory
    for (Devices* device : inventory) {
        delete device;
    }

    return 0;
}

// Function to display the main menu
void displayMainMenu() {
    cout << "Enter device name: Perform that device's one-click action\n";
    cout << "1) List devices\n";
    cout << "2) Sort by name\n";
    cout << "3) Sort by device type\n";
    cout << "4) Device: Select device to interact with its full feature set\n";
    cout << "5) Add device\n";
    cout << "6) Delete device\n";
    cout << "7) Quit\n";
}

// Function to list all devices
void ListDevices(vector<Devices*>& inventory) {

      if (inventory.empty()) {
        cout << "No devices found in the inventory.\nAdd a device first to interact with it. \n"; 
        return;
    }
    int index = 0;
    // Loop through the vector with the iterator
    for (vector<Devices*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
        (*it)->displayDevices(index);
        index++;
    }
    goBack();  // Ask if the user wants to go back to the main menu or quit
}

// Function to sort devices by name
void NameSort(vector<Devices*>& inventory) {

    cout << "List of devices.\n";

    //Lambda expression in the sorting function 
    sort(inventory.begin(), inventory.end(), [](Devices* device1, Devices* device2) {          
        return device1->getDeviceName() < device2->getDeviceName();          //Comparing 2 devices and sorting alphabetically using the sort algorithm and lambda expression.
        });

    // Display sorted devices by their names
    for (int i = 0; i < inventory.size(); ++i) {
        inventory[i]->displayDevices(i);
    }
   goBack();  
}

// Function to sort devices into categories
void Categories(vector<Devices*>& inventory) {

    cout << "Please enter the number of the category you would like to see:" << endl;
    cout << "1) Lighting & Electricity\n";
    cout << "2) Speaker\n";
    cout << "3) Temperature & Humidity Sensor\n";
    cout << "4) Heating Thermostat\n";
    cout << "5) Socket / Plugs\n";
    cout << "6) Radiator Heating\n";

    int input;
    cin >> input;
    cin.ignore();      //Due to dealing with many user inputs of different data types (integer and string), some inputs may be not read correctly, which is why I have used cin.ignore in many parts of my code

    bool isDevice = false;
    int index = 0; //Index restart
    

    for (int i = 0; i < inventory.size(); ++i) {
        string deviceType = inventory[i]->getDeviceType();

        //Device type comparison
        if ((input == 1 && inventory[i]->getDeviceType() == "Light") ||
            (input == 2 && inventory[i]->getDeviceType() == "Speaker") ||
            (input == 3 && inventory[i]->getDeviceType() == "TempSensor") ||
            (input == 4 && inventory[i]->getDeviceType() == "HeatThermo") ||
            (input == 5 && inventory[i]->getDeviceType() == "SocketPlugs") ||
            (input == 6 && inventory[i]->getDeviceType() == "Radiator")) {
            inventory[i]->displayDevices(index);
            index++;
            isDevice = true;

        }
    }
    if (!isDevice) {
        cout << "No devices found in this category.\n";
    }

    goBack();
}

// Function to interact with the full feature set of a chosen device
void FullFeatureDevice(vector<Devices*>& inventory) {

    cout << "Enter a device name to interact with the full feature set of a device.\n";
    string input;
    getline(cin, input);
    bool found = false;

    for (Devices* device : inventory) {

        if (device->getDeviceName() == input) {
            found = true;                           //If input entered is a device, fullFeatureDevice function will turn on 
            cout << "Device found: ";
            (*device).displayDeviceName();
            dynamic_cast<Devices*>(device)->fullFeatureDevice();       //Converting base-class pointer into derived-class pointers
            
        }
        else if (!found) {
            cout << "Device not found.";
        }
    }
    goBack();
   
}

// Function to add a new device
void AddDevice(vector<Devices*>& inventory) {
    cout << "Add new device\n";

    string deviceType;
    cout << "Enter device type: ";
    cin >> deviceType;

    string deviceName;
    cout << "Enter device name: ";
    cin >> deviceName;

    //Add a device using factory
    Devices* device = Factory::createDeviceInput(deviceType, deviceName, false, 0, { {3, "pm"} }, 20.0, 1, 50, 0, 0, 10, 20, 20);    //Default parameters for depending for what device type it is
    //If user does not input the values, these will be set by default

    if (device != nullptr) {
        inventory.push_back(device);  //Adding device to the vector
        cout << "Device added: " << deviceName << " of type " << deviceType << endl;
        cout << "Number of devices: " << inventory.size() << " \n";      //For debugging purpose to check if the device has been successfully added to the vector
    }
    else {
        cout << "Failed to add a device.\n";
    }
    goBack();
}

//Function to ask the user if they want to go back to the main menu
void goBack() {

    cin.clear();
    int input;
    cout << "Press '0' to go back to the main menu.\n";
    cin >> input;
  
    // If the user presses '0', display the main menu again
    if (input == 0) {
        cin.ignore(); //Display the main menu, cin.ignore is needed here as with only 'return;' the menu gets display twice 
        return; 
    }
    else {
        cout << "Invalid input. Press '0' to go back.\n";
    }
}

void printDevices(vector<Devices*> inventory) {      //May be used for debugging purposes to check if devices have been added to the vector
    for (Devices* device : inventory)
        device[0].print();
}

void saveToFile(vector<Devices*>& inventory) {
    ofstream MyFile("APdevices.txt", ios::trunc);

    if (!MyFile.is_open()) {
        cout << "Unable to open the file for writing." << endl;     //Making sure that the selected file is correctly opened
        return;
    }

    //Iterate through the inventory and save device parameters
    for (const auto& device : inventory) {
        cout << "Saving: " << device->getDeviceName() << endl;
        MyFile << device->getDeviceName() << " " << device->getDeviceType() << " ";
        MyFile << device->deviceInfo() << endl;  //deviceInfo updates values
    }

    MyFile.close();
    cout << "Data has been written to APdevices.txt." << endl;
}


void DeleteDevice(vector<Devices*>& inventory) {

    cout << "Enter a device name to delete.\n";
    string input;
    getline(cin, input);

    for (Devices* device : inventory) {

        // Here I have learned how to use the lambda expression and the find if algorithm which will look for the user input in the vector  
        //Using the websites: https://en.cppreference.com/w/cpp/algorithm/find, https://cplusplus.com/reference/algorithm/find/
        auto it = find_if(inventory.begin(), inventory.end(),                   
            [&input](Devices* device) {                                              
                return device->getDeviceName() == input;                                    
            });

        //Check if the device was found
        if (it != inventory.end()) {
            cout << "Device found: ";
            (*it)->displayDeviceName();        

            //Delete the device to free memory
            delete* it;

            // Delete the device from user input from the vector
            inventory.erase(it);

            cout << "Device has been deleted\n";                        
                                                         
        }
    }
    goBack();
}

void createObjects(ifstream& file, vector<Devices*>& inventory) {

    string deviceName, deviceType, userSchedule;
    bool deviceState;
    float temp = 0.0;
    int brightness, volume, liveData, historyData, heatBoost, energyUse, historyUse;
    double timer = 0.0;
    map<int, string> schedule;

    //Light object
    while (file >> deviceName >> deviceType) {
        if (deviceType == "Light") {
            file >> deviceState >> brightness >> timer;
            Light* light = new Light();
            light->setDeviceName(deviceName);                       // https://www.youtube.com/watch?v=drdqjDwV_F4&ab_channel=CalebCurry 
            light->setDeviceType(deviceType);                       //Video which I have watched to learn how to create objects, read from file and write into file
            light->setState(deviceState);                           //Inserting values from the text file and creating objects with the chosen parameters
            light->setBrightness(brightness);
            light->setSleepTimer(timer);
            inventory.push_back(light);
        } //Speaker object
        else if (deviceType == "Speaker") {
            file >> deviceState >> volume;
            Speaker* speaker = new Speaker();
            speaker->setDeviceName(deviceName);
            speaker->setDeviceType(deviceType);
            speaker->setState(deviceState);
            speaker->setDeviceVolume(volume);
            inventory.push_back(speaker);
        } //Tempsensor object
        else if (deviceType == "TempSensor") {
            TempSensor* tempSensor = new TempSensor();
            tempSensor->setDeviceName(deviceName);
            tempSensor->setDeviceType(deviceType);
            tempSensor->setLiveData(liveData);
            tempSensor->setHistoricData(historyData);
            tempSensor->setTemp(temp);
            inventory.push_back(tempSensor);
        } //HeatThermo object
        else if (deviceType == "HeatThermo") {
            file >> deviceState >> userSchedule >> heatBoost;
            HeatThermo* heatthermo = new HeatThermo();
            heatthermo->setDeviceName(deviceName);
            heatthermo->setDeviceType(deviceType);
            heatthermo->setState(deviceState);
            heatthermo->addSchedule(schedule);
            heatthermo->setHeatBoost(heatBoost);
            inventory.push_back(heatthermo);
        } //Radiator object
        else if (deviceType == "Radiator") {
            file >> deviceState >> schedule[1] >> temp;
            Radiator* radiator = new Radiator();
            radiator->setDeviceName(deviceName);
            radiator->setDeviceType(deviceType);
            radiator->setState(deviceState);
            radiator->setSchedule(schedule);
            radiator->setTemp(temp);
            inventory.push_back(radiator);
        } //Socket and plugs object
        else if (deviceType == "SocketPlugs") {
            file >> deviceState >> schedule[1] >> timer >> energyUse >> historyUse;
            SocketPlugs* socketplugs = new SocketPlugs();
            socketplugs->setDeviceName(deviceName);
            socketplugs->setDeviceType(deviceType);
            socketplugs->setState(deviceState);
            socketplugs->setSchedule(schedule);
            socketplugs->setSleepTimer(timer);
            socketplugs->setLiveEnergy(energyUse);
            socketplugs->setHistoricEnergy(historyUse);
            inventory.push_back(socketplugs);
        }

    }

    file.close();

}

bool caseInsensitive(string& input, string& deviceName)          //Case insensitive function which has not been implemented
{                                                                //https://cplusplus.com/forum/beginner/243351/ This website has heavily influenced this method, I have taken the function and have changed the parameters which I think would be suitable in my project. 
    return equal(input.begin(), input.end(),                     //This would compare the user input with the name of the device stored in the inventory 
        deviceName.begin(), deviceName.end(),
        [](char input, char deviceName) {
            return tolower(input) == tolower(deviceName);
        });
}