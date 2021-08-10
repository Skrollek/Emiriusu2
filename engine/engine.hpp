#ifndef EMIRIUSU_ENGINE_HPP
#define EMIRIUSU_ENGINE_HPP

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include <iostream>

namespace Emiriusu {

    class Engine {

    private:

        int width;
        int height;

        GLFWwindow* window;

        Engine ();
        Engine (const Engine& engine);
        ~Engine ();

    public:

        static Engine& Get ();
        void Init ();
    };
}

#endif
