#ifndef TIRE_HPP
#define TIRE_HPP

#include <string>

using namespace std;

class Tire {
private:
    string model;
    int numberOfLaps;

public:
    Tire();
    Tire(const string &model, int numberOfLaps);
    string getModel();
    int getNumberOfLaps();
    void reduceLaps(int ammount);
    string toString();
    Tire& operator=(const Tire& tire);
    ~Tire();
};

#endif