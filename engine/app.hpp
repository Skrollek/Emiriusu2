#ifndef EMIRIUSU_APP_HPP
#define EMIRIUSU_APP_HPP

#include "window.hpp"

#include <iostream>

namespace Emiriusu {

    class Application {

    private:

        int width;
        int height;

        Window* window;

        void PollEvents ();

    public:

        Application ();
        virtual ~Application ();

        virtual void DispatchEvents ();
        void Run ();
    };

    Application* ApplicationNew ();
}

#endif
