#include "../inc/fastestLap.hpp"
#include <iostream>
#include <string>

using namespace std;

FastestLap::FastestLap(int lapNumber, int time, Driver* driver) : 
    lapNumber(lapNumber), 
    time(time),
    driver(new Driver(*driver))
{
    cout << "FastestLap object created" << endl;
}

int FastestLap::getLapNumber()
{
    return lapNumber;
}

int FastestLap::getTime()
{
    return time;
}

string FastestLap::toString()
{
    return "Lap " + to_string(lapNumber) + " - " + to_string(time) + "s";
}

FastestLap::~FastestLap()
{
    cout << "FastestLap object destroyed" << endl;
    driver = nullptr;
}

FastestLap& FastestLap::operator=(FastestLap&& other)
{
    cout << "Called FastestLap move assignment operator: FastestLap (" << this->lapNumber << ") = FastestLap (" << other.lapNumber << ")." << endl;
    if (this == &other) {
        return *this;
    }
    lapNumber = other.lapNumber;
    time = other.time;
    driver = other.driver;
    other.driver = nullptr;
    other.lapNumber = 0;
    other.time = 0;
    return *this;
}

