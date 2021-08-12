#include "window.hpp"

namespace Emiriusu {

    static void key_callback (GLFWwindow* window, int key, int scancode, int action, int mods) {

        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            EventDispatcher::EventSystem().Report (new WindowCloseEvent ());
    }

    Window::Window (std::string initialName, int initialWidth, int initialHeight) {

        width = initialWidth;
        height = initialHeight;
        
        glWindow = glfwCreateWindow (width, height, "Emiriusu2", NULL, NULL);

        glfwMakeContextCurrent (glWindow);
        glfwSetKeyCallback (glWindow, key_callback);
    }

    Window::~Window () {

        glfwDestroyWindow (glWindow);
        glfwTerminate ();
    };

    bool Window::isClosed () { return glfwWindowShouldClose (glWindow); }

    void Window::PollEvents () {

        glfwGetFramebufferSize (glWindow, &width, &height);
        glViewport (0, 0, width, height);

        glfwPollEvents ();
    }

    void Window::close () {

        glfwSetWindowShouldClose (glWindow, GLFW_TRUE);
    }
}