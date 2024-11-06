#include "../inc/aero.hpp"
#include <iostream>

using namespace std;

Aero::Aero() 
{
    series = "NULL Series";
    drag = 0.0;
}

Aero::Aero(const string &series, float drag) : 
    series(series), 
    drag(drag) {}

string Aero::getSeries()
{
    return series;
}

float Aero::getDrag()
{
    return drag;
}

string Aero::toString()
{
    return "Series: " + series + ", Drag: " + to_string(drag);
}

Aero& Aero::operator=(const Aero& aero)
{
    if (this == &aero) {
        return *this;
    }
    series = aero.series;
    drag = aero.drag;
    return *this;
}

Aero::~Aero() 
{
    cout << "Aero object destroyed" << endl;
}