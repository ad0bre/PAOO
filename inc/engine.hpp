#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <string>

using namespace std;

class Engine {
    private:
        string series;
        int horsepower;
    public:
        Engine();
        Engine(string series, int horsepower);
        string getSeries();
        int getHorsepower();
        string toString();
        Engine& operator=(const Engine& engine);
        ~Engine();
};

#endif