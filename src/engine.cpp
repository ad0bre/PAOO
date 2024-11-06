#include "../inc/engine.hpp"
#include <iostream>

using namespace std;

Engine::Engine() 
{
    series = "NULL Series";
    horsepower = 0;
}

Engine::Engine(string series, int horsepower) : 
    series(series), 
    horsepower(horsepower) {}

string Engine::getSeries() 
{
    return series;
}

int Engine::getHorsepower() 
{
    return horsepower;
}

string Engine::toString() 
{
    return "Series: " + series + ", Horsepower: " + to_string(horsepower);
}

Engine& Engine::operator=(const Engine& engine) 
{
    if (this == &engine) {
        return *this;
    }
    series = engine.series;
    horsepower = engine.horsepower;
    return *this;
}

Engine::~Engine() 
{
    cout << "Engine object destroyed" << endl;
}