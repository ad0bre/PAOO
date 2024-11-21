#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <string>
#include "person.hpp"

class Driver : public Person {
    private:
        int trophies;
    public:
        Driver() = delete;
        Driver(string name, int age, string country);
        string getName();
        string getCountry();
        int getAge();
        string toString();
        void addTrophy();
        ~Driver();
        Driver(const Driver& driver);
        Driver& operator=(const Driver& driver);
        Driver(const Driver&& driver) = delete;
        Driver& operator=(Driver&& other) noexcept = delete;
};

#endif