#include "../inc/person.hpp"
#include <iostream>

using namespace std;

Person::Person() 
{
    name = "";
    age = 0;
    country = "";
}

Person::Person(string name, int age, string country) : 
    name(name), 
    age(age), 
    country(country) {}

string Person::getName() 
{
    return name;
}

string Person::getCountry() 
{
    return country;
}

int Person::getAge() 
{
    return age;
}

string Person::toString() 
{
    return "Name: " + name + ", Age: " + to_string(age) + ", Country: " + country;
}

Person::~Person() 
{
    cout << "Person object destroyed" << endl;
}