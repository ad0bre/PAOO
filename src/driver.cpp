#include "../inc/driver.hpp"
#include <iostream>

Driver::Driver(string name, int age, string country) : Person(name, age, country)
{
    cout << "Driver object created" << endl;
    trophies = 0;
}

string Driver::getName() 
{
    return Person::getName();
}

string Driver::getCountry() 
{
    return Person::getCountry();
}

int Driver::getAge() 
{
    return Person::getAge();
}

string Driver::toString() 
{
    return "Driver: " + name + ", " + to_string(age) + ", " + country + ", Trophies: " + to_string(trophies);
}

Driver::~Driver() 
{
    cout << "Driver (" << name << ") object destroyed" << endl;
}

void Driver::addTrophy()
{
    trophies++;
}

Driver& Driver::operator=(const Driver& driver) 
{
    cout << "Called Driver copy assignment operator: Driver (" << this->name << ") = Driver (" << driver.name << ")." << endl;
    if (this == &driver) {
        return *this;
    }
    name.assign(driver.name);
    age = driver.age;
    country.assign(driver.country);
    trophies = driver.trophies;
    return *this;
}
