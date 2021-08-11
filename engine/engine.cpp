#include "engine.hpp"

static void error_callback (int error, const char* description) {
    std::cerr << "Error: " << description << '\n';
}

static void key_callback (GLFWwindow* window, int key, int scancode, int action, int mods) {

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose (window, GLFW_TRUE);
}

namespace Emiriusu {

    Application::Application () {

        glfwSetErrorCallback (error_callback);

        if (!glfwInit ()) {
            std::cout << "Initialization failed!\n";
            exit (EXIT_FAILURE);
        }

        int width = 640, height = 480;
        window = glfwCreateWindow (width, height, "Emiriusu2", NULL, NULL);

        if (!window) {
            std::cout << "Can not create a window!\n";
            exit (EXIT_FAILURE);
        }

        glfwMakeContextCurrent (window);
        glfwSetKeyCallback (window, key_callback);
    }

    Application::~Application () {

        glfwDestroyWindow (window);
        glfwTerminate ();
    }

    void Application::Run () {

        while (!glfwWindowShouldClose (this->window)) {
        
            glfwGetFramebufferSize (window, &width, &height);
            glViewport (0, 0, width, height);

            glfwPollEvents ();
        }
    }
}