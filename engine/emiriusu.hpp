#ifndef EMIRIUSU_HPP
#define EMIRIUSU_HPP

#include "app.hpp"
#include "WindowsWindow.hpp"

extern Emiriusu::Application* Emiriusu::applicationNew ();

int main (int argc, char** argv) {
    
    auto app = Emiriusu::applicationNew ();
    app->run();
    delete app;

    return 0;
}

#endif