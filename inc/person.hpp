#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

using namespace std;

class Person {
    private:
        string name;
        int age;
        string country;
    public:
        Person();
        Person(string name, int age, string country);
        string getName();
        string getCountry();
        int getAge();
        string toString();
        ~Person();
};

#endif