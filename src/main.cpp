#include <iostream>
#include <cstdlib>

#include "../inc/race.hpp"
#include "../inc/team.hpp"
#include "../inc/car.hpp"
#include "../inc/person.hpp"
#include "../inc/driver.hpp"

int main()
{
    srand(time(NULL)); //get different results each run

    Driver* driver11 = new Driver("Max", 26, "NL");
    Driver* driver12 = new Driver("Checo", 36, "MX");

    Driver* driver21 = new Driver("Lewis", 39, "UK");
    Driver* driver22 = new Driver("George", 25, "UK");

    Driver* driver31 = new Driver("Charles", 24, "MC");
    Driver* driver32 = new Driver("Carlos", 27, "SP");

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

    Person* p1 = new Driver("Max", 26, "NL");

    Race* race = new Race("Monaco GP", 10);
    race->addTeam(team1);
    race->addTeam(team2);
    race->addTeam(team3);

    race->simulateRace();

    delete race;

    return 0;
}