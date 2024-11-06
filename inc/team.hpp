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
    Car* car;
    Person* driver1;
    Person* driver2;
    Person* mechanic;
public:
    Team();
    Team(const string &name, Person* principal, Car* car, Person* driver1, Person* driver2, Person* mechanic);
    string getName();
    void replacePrincipal(Person* principal);
    void replaceCar(Car* car);
    void replaceDriver1(Person* driver1);
    void replaceDriver2(Person* driver2);
    void replaceMechanic(Person* mechanic);
    string toString();
    Team& operator=(const Team& team);
    ~Team();
};

#endif