#ifndef CAR_HPP
#define CAR_HPP

#include <string>
#include "person.hpp"
#include "driver.hpp"

using namespace std;

class Car {
private:
    string model;
    string tires;
    int numberOfLaps;
    Driver* driver;
    bool hasDRS;

public:
    Car() = delete;
    Car(const string &model,string tires, int numberOfLaps, Driver* driver);
    string getModel();
    void enableDRS();
    void disableDRS();
    bool hasDRSActive();
    string toString();
    Car& operator=(const Car& car);
    ~Car();
    Driver* getDriver();
    Car(const Car& car) = delete;
    Car(Car&& car) = delete;
    Car& operator=(const Car&& car) = delete;
};

#endif