#ifndef RACE_HPP
#define RACE_HPP

#include <string>
#include <list>
#include <vector>
#include "team.hpp"

using namespace std;

class Race {
    private:
        string name;
        list<Team*> teams;
        Car** cars;
        int totalLaps;
    public:
        Race() = delete;
        Race(const string &name, int totalLaps);
        string getName();
        void addTeam(Team* team);
        void removeTeam(Team* team);
        void createDriversFromTeams();
        void simulateRace();
        string toString();
        Race& operator=(const Race &race);
        ~Race();
};

#endif