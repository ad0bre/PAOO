#include "../inc/car.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

Car::Car() 
{
    model = "NULL Model";
    hasDRS = false;
    engine = (Engine*) malloc(sizeof(Engine));
    if (engine == NULL) {
        cout << "Failed to allocate memory for engine" << endl;
        exit(1);
    }
    wing = (Aero*) malloc(sizeof(Aero));
    if (wing == NULL) {
        cout << "Failed to allocate memory for wing" << endl;
        exit(1);
    }
    tires = (Tire*) malloc(sizeof(Tire));
    if (tires == NULL) {
        cout << "Failed to allocate memory for tires" << endl;
        exit(1);
    }
    driver = (Person*) malloc(sizeof(Person));
    if (driver == NULL) {
        cout << "Failed to allocate memory for driver" << endl;
        exit(1);
    }
    hasDRS = false;
}

Car::Car(const string &model, Engine* engine, Aero* wing, Tire* tires, Person* driver) : 
    model(model), 
    engine(engine), 
    wing(wing), 
    tires(tires),
    driver(driver)
{
    hasDRS = false;
}

string Car::getModel()
{
    return model;
}

void Car::replaceEngine(Engine* engine)
{
    Engine* oldEngine = this->engine;
    this->engine = (Engine*)malloc(sizeof(Engine));
    if (this->engine == NULL) {
        cout << "Failed to allocate memory for engine" << endl;
        exit(1);
    }
    this->engine = engine;
    free(oldEngine);
    cout << "Engine of car " << this->getModel() << " replaced" << endl;
}

void Car::replaceWing(Aero* wing)
{
    Aero* oldWing = this->wing;
    this->wing = (Aero*)malloc(sizeof(Aero));
    if (this->wing == NULL) {
        cout << "Failed to allocate memory for engine" << endl;
        exit(1);
    }
    this->wing = wing;
    free(oldWing);
    cout << "Wing of car " << this->getModel() << " replaced" << endl;
}

void Car::replaceTires(Tire* tires)
{
    Tire* oldTires = this->tires;
    this->tires = (Tire*)malloc(sizeof(Tire));
    if (this->tires == NULL) {
        cout << "Failed to allocate memory for engine" << endl;
        exit(1);
    }
    this->tires = tires;
    free(oldTires);
    cout << "Tires of car " << this->getModel() << " replaced" << endl;
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
        + "Engine: " + engine->toString() + "\n"
        + "Wing: " + wing->toString() + "\n"
        + "Tires: " + tires->toString() + "\n"
        + "DRS: " + (hasDRS ? "Enabled" : "Disabled");
}

Car& Car::operator=(const Car& car)
{
    if (this == &car) {
        return *this;
    }
    model = car.model;
    hasDRS = car.hasDRS;
    replaceEngine(car.engine);
    replaceWing(car.wing);
    replaceTires(car.tires);
    replaceDriver(car.driver);
    return *this;
}

Car::~Car() 
{
    delete engine;
    delete wing;
    delete tires;
    delete driver;
    cout << "Car object destroyed" << endl;
}

Person* Car::getDriver()
{
    return driver;
}