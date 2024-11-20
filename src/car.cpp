#include "../inc/car.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

Car::Car() 
{
    model = "NULL Model";
    hasDRS = false;
    tires = "Pirelli";
    numberOfLaps = 1;
    driver = (Person*) malloc(sizeof(Person));
    if (driver == NULL) {
        cout << "Failed to allocate memory for driver" << endl;
        exit(1);
    }
    hasDRS = false;
}

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

void Car::replaceDriver(Person* driver)
{
    Person* oldDriver = this->driver;
    this->driver = (Person*)malloc(sizeof(Person));
    if (this->driver == NULL) {
        cout << "Failed to allocate memory for engine" << endl;
        exit(1);
    }
    this->driver = driver;
    free(oldDriver);
    cout << "Driver of car " << this->getModel() << " replaced" << endl;
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
    if (this == &car) {
        return *this;
    }
    model = car.model;
    hasDRS = car.hasDRS;
    tires.assign(car.tires);
    numberOfLaps = car.numberOfLaps;
    replaceDriver(car.driver);
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