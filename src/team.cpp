#include "../inc/team.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

Team::Team(const string &name, Person* principal, shared_ptr<Car> car1, shared_ptr<Car> car2, Person* mechanic) : 
    name(name), 
    principal(principal), 
    car1(car1), 
    car2(car2), 
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

void Team::replaceCar1(shared_ptr<Car> car)
{
    this->car1.swap(car);
    car.reset();
    cout << "Car of team " << this->getName() << " replaced" << endl;
}

void Team::replaceCar2(shared_ptr<Car> car)
{
    this->car2.swap(car);
    car.reset();
    cout << "Car of team " << this->getName() << " replaced" << endl;
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

shared_ptr<Car> Team::getCar1()
{
    return car1;
}

shared_ptr<Car> Team::getCar2()
{
    return car2;
}

string Team::toString()
{
    return "Team " + this->name + ":\n" 
        + "Principal: " + principal->getName() + "\n"
        + "Car1: " + car1.get()->toString() + "\n"
        + "Car2: " + car2.get()->toString() + "\n"
        + "Mechanic: " + mechanic->getName();
}

Team& Team::operator=(const Team& team)
{
    if (this == &team) {
        return *this;
    }

    name = team.name;
    replacePrincipal(team.principal);
    replaceCar1(team.car1);
    replaceCar2(team.car2);
    replaceMechanic(team.mechanic);
    return *this;
}

Team::~Team()
{
    cout << "Team " << name << " deleted" << endl;
    delete principal;
    delete mechanic;
    car1.reset();
    car2.reset();
    name.clear();
}


