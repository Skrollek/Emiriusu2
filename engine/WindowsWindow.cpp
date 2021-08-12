#include "WindowsWindow.hpp"

#include <iostream>

extern bool isGLFWinitialized;

namespace Emiriusu {

    Window* Window::Create (const WindowProps& props) {
        return new WindowsWindow (props);
    }

    WindowsWindow::WindowsWindow (const WindowProps& props) {
        data.title = props.title;
        data.width = props.width;
        data.height = props.height;

        if (!isGLFWinitialized) {
            
            if (!glfwInit ()) {
                std::cout << "Initialization failed!\n";
                exit (EXIT_FAILURE);
            }

            isGLFWinitialized = true;
        }

        
        glWindow = glfwCreateWindow (data.width, data.height, data.title.c_str(), NULL, NULL);

        glfwMakeContextCurrent (glWindow);
        glfwSetWindowUserPointer (glWindow, &data);
        //glfwSetKeyCallback (glWindow, key_callback);
        SetVSync (true);
    }

    WindowsWindow::~WindowsWindow () {

        glfwDestroyWindow (glWindow);
    }

    void WindowsWindow::OnUpdate () {

        glfwPollEvents ();
        glfwSwapBuffers (glWindow);
    }

    void WindowsWindow::SetVSync (bool enabled) {
        
        if (enabled) glfwSwapInterval (1);
        else glfwSwapInterval (0);

        data.VSync = enabled;
    }
}