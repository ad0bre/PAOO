#ifndef AERO_HPP
#define AERO_HPP

#include <string>

using namespace std;

class Aero {
private:
    string series;
    float drag; // 0 to 1

public:
    Aero();
    Aero(const string &series, float drag);
    string getSeries();
    float getDrag();
    string toString();
    Aero& operator=(const Aero& aero);
    ~Aero();
};

#endif