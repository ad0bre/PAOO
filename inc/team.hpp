#ifndef TEAM_HPP
#define TEAM_HPP

#include <string>
#include "car.hpp"
#include "person.hpp"

using namespace std;

class Team {
private:
    string name;
    Person* principal;
    Car* car1;
    Car* car2;
    Person* mechanic;
public:
    Team();
    Team(const string &name, Person* principal, Car* car1, Car* car2, Person* mechanic);
    string getName();
    void replacePrincipal(Person* principal);
    void replaceCar1(Car* car);
    void replaceCar2(Car* car);
    void replaceMechanic(Person* mechanic);
    Car* getCar1();
    Car* getCar2();
    string toString();
    Team& operator=(const Team& team);
    ~Team();
};

#endif