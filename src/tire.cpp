#include "../inc/tire.hpp"
#include <iostream>

using namespace std;

Tire::Tire() 
{
    model = "NULL Model";
    numberOfLaps = 0;
}

Tire::Tire(const string &model, int numberOfLaps) : 
    model(model), 
    numberOfLaps(numberOfLaps) {}

string Tire::getModel()
{
    return model;
}

int Tire::getNumberOfLaps()
{
    return numberOfLaps;
}

void Tire::reduceLaps(int ammount)
{
    numberOfLaps -= ammount;
}

string Tire::toString()
{
    return "Model: " + model + ", Laps: " + to_string(numberOfLaps);
}

Tire& Tire::operator=(const Tire& tire)
{
    if (this == &tire) {
        return *this;
    }
    model = tire.model;
    numberOfLaps = tire.numberOfLaps;
    return *this;
}

Tire::~Tire() 
{
    cout << "Tire object destroyed" << endl;
}
