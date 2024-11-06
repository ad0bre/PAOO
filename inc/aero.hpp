#ifndef AERO_H
#define AERO_H

#include <string>

class Aero {
private:
    std::string series;
    float drag; // 0 to 1

public:
    Aero();
    Aero(const std::string &series, float drag);
    std::string getSeries();
    float getDrag();
    std::string toString();
    Aero& operator=(const Aero& aero);
    ~Aero();
};

#endif