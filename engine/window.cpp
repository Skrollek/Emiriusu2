#include "window.hpp"

namespace Emiriusu {

    static void key_callback (GLFWwindow* window, int key, int scancode, int action, int mods) {

        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            EventDispatcher::EventSystem().Report (new WindowCloseEvent ());
    }

    Window::Window (std::string name, int width, int height) {

        this->width = width;
        this->height = height;
        
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