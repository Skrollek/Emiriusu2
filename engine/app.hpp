#ifndef EMIRIUSU_APP_HPP
#define EMIRIUSU_APP_HPP

#include "window.hpp"

#include <iostream>

namespace Emiriusu {

    class Application {

    private:
        bool running = true;

        Window* window;

        void pollEvents ();
        bool onWindowClose(WindowCloseEvent& newEvent);

    public:

        Application ();
        virtual ~Application ();

        virtual void dispatchEvents ();
        void run ();
        void onEvent(Event& newEvent);
    };

    Application* applicationNew ();
}

#endif
