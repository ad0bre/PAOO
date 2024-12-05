#ifndef TEAM_HPP
#define TEAM_HPP

#include <string>
#include <memory>
#include "car.hpp"
#include "person.hpp"

using namespace std;

class Team {
private:
    string name;
    Person* principal;
    shared_ptr<Car> car1;
    shared_ptr<Car> car2;
    Person* mechanic;
public:
    Team() = delete;
    Team(const string &name, Person* principal, shared_ptr<Car> car1, shared_ptr<Car> car2, Person* mechanic);
    string getName();
    void replacePrincipal(Person* principal);
    void replaceCar1(shared_ptr<Car> car);
    void replaceCar2(shared_ptr<Car> car);
    void replaceMechanic(Person* mechanic);
    shared_ptr<Car> getCar1();
    shared_ptr<Car> getCar2();
    string toString();
    Team& operator=(const Team& team);
    ~Team();
};

#endif