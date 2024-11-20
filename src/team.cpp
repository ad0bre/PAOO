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
    car1 = (Car*) malloc(sizeof(Car));
    if (car1 == NULL) {
        cout << "Failed to allocate memory for car" << endl;
        exit(1);
    }
    car2 = (Car*) malloc(sizeof(Car));
    if (car2 == NULL) {
        cout << "Failed to allocate memory for car" << endl;
        exit(1);
    }
    mechanic = (Person*) malloc(sizeof(Person));
    if (mechanic == NULL) {
        cout << "Failed to allocate memory for mechanic" << endl;
        exit(1);
    }
}

Team::Team(const string &name, Person* principal, Car* car1, Car* car2, Person* mechanic) : 
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

void Team::replaceCar1(Car* car)
{
    Car* oldCar = this->car1;
    this->car1 = (Car*)malloc(sizeof(Car));
    if (this->car1 == NULL) {
        cout << "Failed to allocate memory for car" << endl;
        exit(1);
    }
    this->car1 = car;
    free(oldCar);
    cout << "Car of team " << this->getName() << " replaced" << endl;
}

void Team::replaceCar2(Car* car)
{
    Car* oldCar = this->car2;
    this->car2 = (Car*)malloc(sizeof(Car));
    if (this->car2 == NULL) {
        cout << "Failed to allocate memory for car" << endl;
        exit(1);
    }
    this->car2 = car;
    free(oldCar);
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

Car* Team::getCar1()
{
    return car1;
}

Car* Team::getCar2()
{
    return car2;
}

string Team::toString()
{
    return "Team " + this->name + ":\n" 
        + "Principal: " + principal->getName() + "\n"
        + "Car1: " + car1->toString() + "\n"
        + "Car2: " + car2->toString() + "\n"
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
    delete principal;
    delete car1;
    delete car2;
    delete mechanic;
    cout << "Team " << name << " deleted" << endl;
}


