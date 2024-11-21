#ifndef CAR_HPP
#define CAR_HPP

#include <string>
#include "person.hpp"

using namespace std;

class Car {
private:
    string model;
    string tires;
    int numberOfLaps;
    Person* driver;
    bool hasDRS;

public:
    Car() = delete;
    Car(const string &model,string tires, int numberOfLaps, Person* driver);
    string getModel();
    void enableDRS();
    void disableDRS();
    bool hasDRSActive();
    string toString();
    Car& operator=(const Car& car);
    ~Car();
    Person* getDriver();
    Car(const Car& car) = delete;
    Car(Car&& car) = delete;
    Car& operator=(const Car&& car) = delete;
};

#endif