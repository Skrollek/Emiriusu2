#ifndef EMIRIUSU_ENGINE_HPP
#define EMIRIUSU_ENGINE_HPP

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include <iostream>

namespace Emiriusu {

    class Application {

    private:

        int width;
        int height;

        GLFWwindow* window;

    public:

        Application ();
        virtual ~Application ();

        void Run ();
    };

    Application* ApplicationNew ();
}

#endif
