#include <iostream>
#include <cstdlib>

#include "../inc/race.hpp"
#include "../inc/team.hpp"
#include "../inc/car.hpp"
#include "../inc/person.hpp"
#include "../inc/engine.hpp"
#include "../inc/aero.hpp"
#include "../inc/tire.hpp"

int main()
{
    Person* driver11 = new Person("Max", 26, "NL");
    Person* driver12 = new Person("Checo", 36, "MX");

    Person* driver21 = new Person("Lewis", 39, "UK");
    Person* driver22 = new Person("George", 25, "UK");

    Person* driver31 = new Person("Charles", 24, "MC");
    Person* driver32 = new Person("Carlos", 27, "SP");

    Engine* engine11 = new Engine("Honda", 1100);
    Engine* engine12 = new Engine("Honda", 1100);

    Engine* engine21 = new Engine("AMG", 1000);
    Engine* engine22 = new Engine("AMG", 1000);
    
    Engine* engine31 = new Engine("Ferrari", 1000);
    Engine* engine32 = new Engine("Ferrari", 1000);

    Aero* wing11 = new Aero("Low down force", 0.1);
    Aero* wing12 = new Aero("High down force", 0.9);

    Aero* wing21 = new Aero("Low down force", 0.1);
    Aero* wing22 = new Aero("High down force", 0.9);

    Aero* wing31 = new Aero("Low down force", 0.1);
    Aero* wing32 = new Aero("High down force", 0.9);

    Tire* tires11 = new Tire("Soft", 3);
    Tire* tires12 = new Tire("Medium", 5);

    Tire* tires21 = new Tire("Hard", 7);
    Tire* tires22 = new Tire("Soft", 3);

    Tire* tires31 = new Tire("Medium", 5);
    Tire* tires32 = new Tire("Hard", 7);

    Person* principal1 = new Person("Christian", 44, "AU");
    Person* mechanic1 = new Person("Bob", 35, "UK");

    Person* principal2 = new Person("Toto", 42, "DE");
    Person* mechanic2 = new Person("Rob", 37, "UK");

    Person* principal3 = new Person("Fred", 47, "FR");
    Person* mechanic3 = new Person("Mike", 32, "UK");

    Car* car11 = new Car("1", engine11, wing11, tires11, driver11);
    Car* car12 = new Car("11", engine12, wing12, tires12, driver12);

    Car* car21 = new Car("44", engine21, wing21, tires21, driver21);
    Car* car22 = new Car("63", engine22, wing22, tires22, driver22);

    Car* car31 = new Car("16", engine31, wing31, tires31, driver31);
    Car* car32 = new Car("55", engine32, wing32, tires32, driver32);

    Team* team1 = new Team("RBR", principal1, car11, car12, mechanic1);
    Team* team2 = new Team("MER", principal2, car21, car22, mechanic2);
    Team* team1 = new Team("FER", principal3 car31, car32, mechanic3);

    Race* race = new Race("Monaco GP", 10);
    race->addTeam(team1);
    race->addTeam(team2);
    race->addTeam(team2);

    race->simulateRace();

    delete race;

    return 0;
}