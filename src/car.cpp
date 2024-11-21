#include "../inc/car.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

Car::Car(const string &model, string tires, int numberOfLaps, Person* driver) : 
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
    delete driver;
    cout << "Car (" << model << ") object destroyed" << endl;
}

Person* Car::getDriver()
{
    return driver;
}

Car::Car(const Car& car) : 
    model(car.model),
    tires(car.tires),
    driver(new Person(car.driver->getName(), car.driver->getAge(), car.driver->getCountry())),
    numberOfLaps(car.numberOfLaps),
    hasDRS(false) {
        cout << "Called Car copy constructor: Car (" << car.model << ")." << endl;
    }

Car::Car(Car&& car) :
    model(car.model),
    tires(car.tires),
    driver(car.driver),
    numberOfLaps(car.numberOfLaps),
    hasDRS(car.hasDRS) {
        cout << "Called Car move constructor: Car (" << car.model << ")." << endl;
        car.driver = nullptr;
    }

bool Car::operator==(const Car& car)
{
    return model == car.model && driver == car.driver;
}