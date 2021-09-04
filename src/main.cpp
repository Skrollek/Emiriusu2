#include "engine/Emiriusu.hpp"

class TheAStrategicGame : public Emiriusu::Application {

public:

    TheAStrategicGame () {}

    ~TheAStrategicGame () {}
};

Emiriusu::Application* Emiriusu::applicationNew () {

    return new TheAStrategicGame ();
}