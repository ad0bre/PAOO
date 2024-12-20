#include "../inc/race.hpp"
#include "../inc/fastestLap.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <memory>
#include <mutex>
#include <thread>

using namespace std;

Race::Race(const string &name, int totalLaps) : 
    name(name), 
    totalLaps(totalLaps) 
    {
        teams = list<Team*>();
        cars = (shared_ptr<Car>*) malloc(sizeof(shared_ptr<Car>) * 2);
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
    cars = (shared_ptr<Car>*) realloc(cars, sizeof(shared_ptr<Car>) * size * 2);
    if (cars == NULL) {
        cout << "Failed to reallocate memory for drivers" << endl;
        exit(1);
    }

    int iterator = 0;

    for (Team* team : teams) {
        cars[iterator++] = team->getCar1();
        cars[iterator++] = team->getCar2();
        cout << "From team " << team->getName() << ": " << endl;
        cout << team->getCar1().get()->getDriver()->getName() << " starting P" << iterator - 1 << endl;
        cout << " and " << endl;
        cout << team->getCar2().get()->getDriver()->getName() << " starting P" << iterator << endl;
    }
}

mutex mtx;

void Race::simulateRace()
{
    cout << "!!!Race start!!!" << endl;
    cout << "Total laps: " << totalLaps << endl;

    this->createDriversFromTeams();

    int totalCars = teams.size() * 2;

    unique_ptr<FastestLap>* fastLaps = (unique_ptr<FastestLap>*) malloc(sizeof(unique_ptr<FastestLap>) * totalLaps);
    if (fastLaps == NULL) {
        cout << "Failed to allocate memory for fastest laps" << endl;
        exit(1);
    }

    for (int i = 0; i < totalLaps; i++) {
        cout << "|            Lap " << i + 1 << "          |" << endl;
        int fastest = rand() % totalCars;
        thread t1(&Race::overtake, this, totalCars);
        thread t2(&Race::overtake, this, totalCars);
        t1.join();
        t2.join();
        unique_ptr<FastestLap> current(new FastestLap(i + 1, rand() % 100, cars[fastest]->getDriver()));
        fastLaps[i] = move(current);
    }

    cout << endl << "!!!RACE IS OVER!!!" << endl;

    cout << "Final standings: " << endl
         << "1. " << cars[0]->getDriver()->getName() << endl
         << "2. " << cars[1]->getDriver()->getName() << endl
         << "3. " << cars[2]->getDriver()->getName() << endl
         << endl;

    cout << "// Fastest laps //" << endl;
    for (int i = 0; i < totalLaps; i++) {
        cout << fastLaps[i]->toString() << endl;
        delete fastLaps[i].get();
    }
    free(fastLaps);
}

void Race::overtake(int totalCars)
{
    mtx.lock();
    int lucky = rand() % totalCars;
    if (lucky == 0) {
        lucky = 2;
    }
    if (lucky > 0) {
        cars[lucky]->enableDRS();
    }
    if (cars[lucky - 1]->hasDRSActive()) {
        cars[lucky - 1]->disableDRS();
    } else {
        int j = lucky;
        cars[j-1].swap(cars[j]);
        cout << "/---- " << cars[j-1]->getDriver()->getName() << " overtakes " << cars[j]->getDriver()->getName() << " ----/" << endl;
        cars[j-1]->disableDRS();
    }
    mtx.unlock();
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
    cars = (shared_ptr<Car>*) realloc(cars, sizeof(shared_ptr<Car>) * 2);
    if (cars == NULL) {
        cout << "Failed to reallocate memory for drivers" << endl;
        exit(1);
    }
    return *this;
}

Race::~Race() 
{
    cout << "Destorying race object:" << name << endl;
    for (Team* team : teams) {
        delete team;
    }
    teams.clear();
    name.clear();
}
