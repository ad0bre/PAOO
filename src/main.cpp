#include <iostream>
#include <cstdlib>

#include "../inc/race.hpp"
#include "../inc/team.hpp"
#include "../inc/car.hpp"
#include "../inc/person.hpp"

int main()
{
    Person* driver11 = new Person("Max", 26, "NL");
    Person* driver12 = new Person("Checo", 36, "MX");

    Person* driver21 = new Person("Lewis", 39, "UK");
    Person* driver22 = new Person("George", 25, "UK");

    Person* driver31 = new Person("Charles", 24, "MC");
    Person* driver32 = new Person("Carlos", 27, "SP");

    Person* principal1 = new Person("Christian", 44, "AU");
    Person* mechanic1 = new Person("Bob", 35, "UK");

    Person* principal2 = new Person("Toto", 42, "DE");
    Person* mechanic2 = new Person("Rob", 37, "UK");

    Person* principal3 = new Person("Fred", 47, "FR");
    Person* mechanic3 = new Person("Mike", 32, "UK");

    Car* car11 = new Car("1", "soft", 5, driver11);
    Car* car12 = new Car("11", "medium", 7, driver12);

    Car* car21 = new Car("44", "hard", 9, driver21);
    Car* car22 = new Car("63", "soft", 5, driver22);

    Car* car31 = new Car("16", "medium", 7, driver31);
    Car* car32 = new Car("55", "hard", 9, driver32);

    Team* team1 = new Team("RBR", principal1, car11, car12, mechanic1);
    Team* team2 = new Team("MER", principal2, car21, car22, mechanic2);
    Team* team3 = new Team("FER", principal3, car31, car32, mechanic3);

    Race* race = new Race("Monaco GP", 10);
    race->addTeam(team1);
    race->addTeam(team2);
    race->addTeam(team3);

    race->simulateRace();

    delete race;

    return 0;
}