#include "WindowsWindow.hpp"

#include <iostream>
#include <GLFW/glfw3.h>

extern bool isGLFWinitialized;

namespace Emiriusu {

    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        //WindowData* callbackedData = (WindowData*)glfwGetWindowUserPointer(window);
        switch (action)
        {
            case GLFW_PRESS:
                {
                    //KeyPressedEvent
                    std::cout << "Key pressed\n";
                    break;
                }
            case GLFW_RELEASE:
                {
                    std::cout << "Key released\n";
                    break;
                }
            case GLFW_REPEAT:
                {
                    std::cout << "Key repeated\n";
                    break;
                }
            default:
                break;
        }
    }

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
            else
                std::cout << "All right\n";

            isGLFWinitialized = true;
        }

        
        glWindow = glfwCreateWindow (data.width, data.height, data.title.c_str(), NULL, NULL);

        glfwMakeContextCurrent (glWindow);
        glfwSetWindowUserPointer (glWindow, &data);
        SetVSync (true);

        glfwSetWindowSizeCallback(glWindow, [](GLFWwindow* window, int width, int height)
        {
            WindowData* callbackedData = (WindowData*)glfwGetWindowUserPointer(window);
            
            callbackedData->width = width;
            callbackedData->height = height;
            
            WindowResizeEvent event(width, height);
            callbackedData->eventCallback(event);
        });
        glfwSetWindowCloseCallback(glWindow, [](GLFWwindow* window)
        {
            WindowData* callbackedData = (WindowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            callbackedData->eventCallback(event);
        });
        glfwSetKeyCallback (glWindow, keyCallback);
        //glfwSetMouseButtonCallback();
        //glfwSetScrollCallback();
        //glfwSetCursorPosCallback();
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