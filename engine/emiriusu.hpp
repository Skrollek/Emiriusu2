#ifndef EMIRIUSU_HPP
#define EMIRIUSU_HPP

#include "app.hpp"

extern Emiriusu::Application* Emiriusu::ApplicationNew ();

int main (int argc, char** argv) {
    
    auto app = Emiriusu::ApplicationNew ();
    app->Run ();
    delete app;

    return 0;
}

#endif