#include "../inc/team.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

Team::Team() 
{
    name = "NULL Team";
    principal = (Person*) malloc(sizeof(Person));
    if (principal == NULL) {
        cout << "Failed to allocate memory for principal" << endl;
        exit(1);
    }
    car = (Car*) malloc(sizeof(Car));
    if (car == NULL) {
        cout << "Failed to allocate memory for car" << endl;
        exit(1);
    }
    driver1 = (Person*) malloc(sizeof(Person));
    if (driver1 == NULL) {
        cout << "Failed to allocate memory for driver1" << endl;
        exit(1);
    }
    driver2 = (Person*) malloc(sizeof(Person));
    if (driver2 == NULL) {
        cout << "Failed to allocate memory for driver2" << endl;
        exit(1);
    }
    mechanic = (Person*) malloc(sizeof(Person));
    if (mechanic == NULL) {
        cout << "Failed to allocate memory for mechanic" << endl;
        exit(1);
    }
}

Team::Team(const string &name, Person* principal, Car* car, Person* driver1, Person* driver2, Person* mechanic) : 
    name(name), 
    principal(principal), 
    car(car), 
    driver1(driver1), 
    driver2(driver2), 
    mechanic(mechanic) {}

string Team::getName()
{
    return name;
}

void Team::replacePrincipal(Person* principal)
{
    Person* oldPrincipal = this->principal;
    this->principal = (Person*)malloc(sizeof(Person));
    if (this->principal == NULL) {
        cout << "Failed to allocate memory for principal" << endl;
        exit(1);
    }
    this->principal = principal;
    free(oldPrincipal);
    cout << "Principal of team " << this->getName() << " replaced" << endl;
}

void Team::replaceCar(Car* car)
{
    Car* oldCar = this->car;
    this->car = (Car*)malloc(sizeof(Car));
    if (this->car == NULL) {
        cout << "Failed to allocate memory for car" << endl;
        exit(1);
    }
    this->car = car;
    free(oldCar);
    cout << "Car of team " << this->getName() << " replaced" << endl;
}

void Team::replaceDriver1(Person* driver1)
{
    Person* oldDriver1 = this->driver1;
    this->driver1 = (Person*)malloc(sizeof(Person));
    if (this->driver1 == NULL) {
        cout << "Failed to allocate memory for driver1" << endl;
        exit(1);
    }
    this->driver1 = driver1;
    free(oldDriver1);
    cout << "Driver 1 of team " << this->getName() << " replaced" << endl;
}

void Team::replaceDriver2(Person* driver2)
{
    Person* oldDriver2 = this->driver2;
    this->driver2 = (Person*)malloc(sizeof(Person));
    if (this->driver2 == NULL) {
        cout << "Failed to allocate memory for driver2" << endl;
        exit(1);
    }
    this->driver2 = driver2;
    free(oldDriver2);
    cout << "Driver 2 of team " << this->getName() << " replaced" << endl;
}

void Team::replaceMechanic(Person* mechanic)
{
    Person* oldMechanic = this->mechanic;
    this->mechanic = (Person*)malloc(sizeof(Person));
    if (this->mechanic == NULL) {
        cout << "Failed to allocate memory for mechanic" << endl;
        exit(1);
    }
    this->mechanic = mechanic;
    free(oldMechanic);
    cout << "Mechanic of team " << this->getName() << " replaced" << endl;
}

string Team::toString()
{
    return "Team " + name + ":\n" 
        + "Principal: " + principal->toString() + "\n"
        + "Car: " + car->toString() + "\n"
        + "Driver 1: " + driver1->toString() + "\n"
        + "Driver 2: " + driver2->toString() + "\n"
        + "Mechanic: " + mechanic->toString();
}

Team& Team::operator=(const Team& team)
{
    if (this == &team) {
        return *this;
    }

    name = team.name;
    replacePrincipal(team.principal);
    replaceCar(team.car);
    replaceDriver1(team.driver1);
    replaceDriver2(team.driver2);
    replaceMechanic(team.mechanic);
    return *this;
}

Team::~Team()
{
    delete principal;
    delete car;
    delete driver1;
    delete driver2;
    delete mechanic;
    cout << "Team " << name << " deleted" << endl;
}


