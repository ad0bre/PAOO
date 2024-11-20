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
    Car();
    Car(const string &model,string tires, int numberOfLaps, Person* driver);
    string getModel();
    void replaceDriver(Person* driver);
    void enableDRS();
    void disableDRS();
    bool hasDRSActive();
    string toString();
    Car& operator=(const Car& car);
    ~Car();
    Person* getDriver();

};

#endif