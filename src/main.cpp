#include "engine/Emiriusu.hpp"

class TheAStrategicGame : public Emiriusu::Application {

public:

    TheAStrategicGame () {}

    ~TheAStrategicGame () {}
};

Emiriusu::Application* Emiriusu::ApplicationNew () {

    return new TheAStrategicGame ();
}