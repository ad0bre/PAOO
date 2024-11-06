#ifndef TIRE_H
#define TIRE_H

#include <string>

class Tire {
private:
    std::string model;
    int numberOfLaps;

public:
    Tire();
    Tire(const std::string &model, int numberOfLaps);
    std::string getModel();
    int getNumberOfLaps();
    void reduceLaps(int ammount);
    std::string toString();
    Tire& operator=(const Tire& tire);
    ~Tire();
};

#endif