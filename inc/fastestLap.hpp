#ifndef FASTESTLAP_HPP
#define FASTESTLAP_HPP

#include <string>
#include "driver.hpp"

using namespace std;

class FastestLap {
    private:
        int lapNumber;
        int time;
        Driver* driver;
    public:
        FastestLap() = delete;
        FastestLap(int lapNumber, int time, Driver* driver);
        int getLapNumber();
        int getTime();
        string toString();
        FastestLap(FastestLap&& other) = delete;
        FastestLap& operator=(const FastestLap& other) = delete;
        FastestLap& operator=(FastestLap&& other);
        ~FastestLap();
};

#endif