#ifndef CAR_HPP
#define CAR_HPP

#include <string>
#include "engine.hpp"
#include "aero.hpp"
#include "tire.hpp"
#include "person.hpp"

using namespace std;

class Car {
private:
    string model;
    Engine* engine;
    Aero* wing;
    Tire* tires;
    Person* driver;
    bool hasDRS;

public:
    Car();
    Car(const string &model, Engine* engine, Aero* wing, Tire* tires, Person* driver);
    string getModel();
    void replaceEngine(Engine* engine);
    void replaceWing(Aero* wing);
    void replaceTires(Tire* tires);
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