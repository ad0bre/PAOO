#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

using namespace std;

class Person {
    protected:
        string name;
        int age;
        string country;
    public:
        Person() = delete;
        Person(string name, int age, string country);
        string getName();
        string getCountry();
        int getAge();
        virtual string toString();
        virtual ~Person();
        Person& operator=(const Person& person);
        Person(const Person&& person) = delete;
        Person& operator=(const Person&& person) = delete;
};

#endif