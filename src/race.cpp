#include "../inc/race.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

Race::Race() 
{
    name = "NULL Race";
    totalLaps = 0;
    teams = list<Team*>();
    cars = (Car**) malloc(sizeof(Car) * 2);
    if (cars == NULL) {
        cout << "Failed to allocate memory for drivers" << endl;
        exit(1);
    }
}

Race::Race(const string &name, int totalLaps) : 
    name(name), 
    totalLaps(totalLaps) 
    {
        teams = list<Team*>();
        cars = (Car**) malloc(sizeof(Car) * 2);
        if (cars == NULL) {
            cout << "Failed to allocate memory for drivers" << endl;
            exit(1);
        }
    }

string Race::getName()
{
    return name;
}

void Race::addTeam(Team* team)
{
    teams.push_back(team);
    cout << "New team added to race " << name << ":\n" << team->getName() << endl;
}

void Race::createDriversFromTeams()
{
    cout << "Drivers entering this race: " << endl;
    int size = teams.size();
    cars = (Car**) realloc(cars, sizeof(Car) * size * 2);
    if (cars == NULL) {
        cout << "Failed to reallocate memory for drivers" << endl;
        exit(1);
    }

    int iterator = 0;

    for (Team* team : teams) {
        cars[iterator++] = team->getCar1();
        cars[iterator++] = team->getCar2();
        cout << "From team " << team->getName() << ": " << endl;
        cout << team->getCar1()->getDriver()->getName() << " starting P" << iterator - 1 << endl;
        cout << " and " << endl;
        cout << team->getCar2()->getDriver()->getName() << " starting P" << iterator << endl;
    }
}

void Race::simulateRace()
{
    cout << "!!!Race start!!!" << endl;
    cout << "Total laps: " << totalLaps << endl;

    this->createDriversFromTeams();

    int totalCars = teams.size() * 2;

    for (int i = 0; i < totalLaps; i++) {
        cout << "|     Lap " << i + 1 << "    |" << endl;
        cars[0]->disableDRS();
        int lucky = rand() % totalCars;
        if (lucky == 0) {
            lucky = 2;
        }
        if (lucky > 0) {
            cars[lucky]->enableDRS();
        }
        
        if (cars[lucky - 1]->hasDRSActive()) {
            cars[lucky - 1]->disableDRS();
        }
        else{
            int j = lucky;
            Car* carInFront = cars[j - 1];
            cars[j - 1] = cars[j];
            cars[j] = carInFront;
            cout << cars[j - 1]->getDriver()->getName() << " overtakes " << cars[j]->getDriver()->getName() << endl;
            cars[j - 1]->disableDRS();
        }
    }

    cout << "!!!RACE IS OVER!!!" << endl;

    cout << "Final standings: " << endl <<
        "1. " << cars[0]->getDriver()->getName() << endl <<
        "2. " << cars[1]->getDriver()->getName() << endl <<
        "3. " << cars[2]->getDriver()->getName() << endl;
}

Race& Race::operator=(const Race &race)
{
    if (this == &race) 
    {
        return *this;
    }

    name = race.name;
    totalLaps = race.totalLaps;
    teams = race.teams;
    cars = (Car**) realloc(cars, sizeof(Car) * 2);
    if (cars == NULL) {
        cout << "Failed to reallocate memory for drivers" << endl;
        exit(1);
    }
    return *this;
}

Race::~Race() 
{
    int size = teams.size() * 2;
    for (int i = 0; i < size; i++) {
        delete cars[i];
    }
    delete cars;
    for (Team* team : teams) {
        delete team;
    }
    teams.clear();
}
