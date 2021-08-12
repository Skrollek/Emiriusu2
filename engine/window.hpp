#ifndef EMIRIUSU_WINDOW_HPP
#define EMIRIUSU_WINDOW_HPP

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include "applicationEvent.hpp"

#include <string>

namespace Emiriusu {

    class Window {

        int width, height;
        std::string name;
        GLFWwindow* glWindow;

    public:

        Window (std::string initialName, int initialWidth, int initialHeight);
        ~Window ();

        bool isClosed ();
        void close ();
        void PollEvents ();
    };
}

#endif