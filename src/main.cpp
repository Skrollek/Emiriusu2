#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include <iostream>

void error_callback (int error, const char* description) {
    std::cerr << "Error: " << description << '\n';
}

void key_callback (GLFWwindow* window, int key, int scancode, int action, int mods) {

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose (window, GLFW_TRUE);
}

int main () {

    glfwSetErrorCallback (error_callback);

    if (!glfwInit ()) {
        std::cout << "Initialization failed!\n"; 
    } else std::cout << "Initialization passed!\n";

    int width = 640, height = 480;

    GLFWwindow* window = glfwCreateWindow (width, height, "Emiriusu2", NULL, NULL);

    if (!window) {
        std::cout << "Can not create a window!\n";
        exit (EXIT_FAILURE);
    }

    glfwMakeContextCurrent (window);
    glfwSetKeyCallback (window, key_callback);

    while (!glfwWindowShouldClose (window)) {
        
        glfwGetFramebufferSize (window, &width, &height);
        glViewport (0, 0, width, height);

        glfwPollEvents();
    }

    glfwDestroyWindow (window);
    glfwTerminate ();
    return 0;
}