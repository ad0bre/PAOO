#include <iostream>
#include <cstdlib>
#include "../inc/race.hpp"
#include "../inc/team.hpp"
#include "../inc/car.hpp"
#include "../inc/person.hpp"
#include "../inc/engine.hpp"
#include "../inc/aero.hpp"
#include "../inc/tire.hpp"

int main() {
    Person* driver1 = new Person("Lewis Hamilton", 35, "UK");
    Person* driver2 = new Person("Valtteri Bottas", 30, "FIN");
    Person* driver3 = new Person("Max Verstappen", 22, "NL");
    Person* driver4 = new Person("Alexander Albon", 24, "TH");
    Person* driver5 = new Person("Sebastian Vettel", 33, "DE");
    Person* driver6 = new Person("Charles Leclerc", 22, "MC");

    Person* principal1 = new Person("Toto Wolff", 48, "AT");
    Person* principal2 = new Person("Christian Horner", 46, "UK");
    Person* principal3 = new Person("Mattia Binotto", 50, "IT");

    Person* mechanic1 = new Person("Andrew Shovlin", 46, "UK");
    Person* mechanic2 = new Person("Paul Monaghan", 50, "UK");
    Person* mechanic3 = new Person("Jock Clear", 56, "UK");

    Engine* engine1 = new Engine("Mercedes", 990);
    Engine* engine2 = new Engine("Red Bull Racing", 1000);
    Engine* engine3 = new Engine("Ferrari", 1100);

    Aero* aero1 = new Aero("Mercedes", 0.78);
    Aero* aero2 = new Aero("Red Bull Racing", 0.95);
    Aero* aero3 = new Aero("Ferrari", 0.85);

    Tire* tire1 = new Tire("Soft", 3);
    Tire* tire2 = new Tire("Medium", 5);
    Tire* tire3 = new Tire("Hard", 7);

    Car* car11 = new Car("Mercedes W11", engine1, aero1, tire1, driver1);
    Car* car12 = new Car("Mercedes W11", engine1, aero1, tire3, driver2);

    Car* car21 = new Car("Red Bull Racing RB16", engine2, aero2, tire1, driver3);
    Car* car22 = new Car("Red Bull Racing RB16", engine2, aero2, tire3, driver4);

    Car* car31 = new Car("Ferrari SF1000", engine3, aero3, tire1, driver5);
    Car* car32 = new Car("Ferrari SF1000", engine3, aero3, tire3, driver6);

    Team* team1 = new Team("Mercedes AMG Petronas F1 Team", principal1, car11, car12, mechanic1);
    Team* team2 = new Team("Aston Martin Red Bull Racing", principal2, car21, car22, mechanic2);
    Team* team3 = new Team("Scuderia Ferrari", principal3, car31, car32, mechanic3);

    Race* race1 = new Race("Monaco Grand Prix", 10);

    race1->addTeam(team1);
    race1->addTeam(team2);
    race1->addTeam(team3);

    race1->simulateRace();

    Race* race2 = race1;

    race2->simulateRace();

    delete race1;

    delete race2;
    
    return 0;
}