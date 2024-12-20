#include "../inc/car.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

Car::Car(const string &model, string tires, int numberOfLaps, Driver* driver) : 
    model(model),
    tires(tires),
    numberOfLaps(numberOfLaps),
    driver(driver)
{
    hasDRS = false;
}

string Car::getModel()
{
    return model;
}

void Car::enableDRS()
{
    hasDRS = true;
    cout << "DRS enabled for driver " << driver->getName() << endl;
}

void Car::disableDRS()
{
    hasDRS = false;
    cout << "DRS disabled for driver " << driver->getName() << endl;
}

bool Car::hasDRSActive()
{
    return hasDRS;
}

string Car::toString()
{
    return "Car " + model + ":\n"
        + "Driver: " + driver->toString() + "\n"
        + "Tires: " + tires + "\n"
        + "Number of laps: " + to_string(numberOfLaps) + "\n"
        + "DRS: " + (hasDRS ? "Enabled" : "Disabled");
}

Car& Car::operator=(const Car& car)
{
    cout << "Called Car copy assignment operator: Car (" << this->model << ") = Car (" << car.model << ")." << endl;
    if (this == &car) {
        return *this;
    }
    model = car.model;
    hasDRS = car.hasDRS;
    tires.assign(car.tires);
    numberOfLaps = car.numberOfLaps;
    driver = car.driver;
    return *this;
}

Car::~Car() 
{
    cout << "Car (" << model << ") object destroyed" << endl;
    delete driver;
    model.clear();
    tires.clear();
}

Driver* Car::getDriver()
{
    return driver;
}