#include "app.hpp"

static void error_callback (int error, const char* description) {
    std::cerr << "Error: " << description << '\n';
}

namespace Emiriusu {

    Application::Application () {

        glfwSetErrorCallback (error_callback);

        if (!glfwInit ()) {
            std::cout << "Initialization failed!\n";
            exit (EXIT_FAILURE);
        }

        int width = 640, height = 480;
        window = new Window ("Emiriusu2", width, height);

        if (!window) {
            std::cout << "Can not create a window!\n";
            exit (EXIT_FAILURE);
        }
    }

    Application::~Application () {

        delete window;
    }

    void Application::PollEvents () {

        window->PollEvents();
    }

    void Application::DispatchEvents () {
        
        Event* ev;

        while ((ev = EventDispatcher::EventSystem().Dispatch (EventCategoryApplication)) != nullptr) {
            switch (ev->GetEventType ()) {
                case EventType::WindowResized: break;
                case EventType::WindowMoved: break;
                case EventType::WindowClosed: {
                    window->close();
                    break;
                }
                default: break;
            }

            delete ev;
        }
    }

    void Application::Run () {

        while (!window->isClosed()) {
            
            PollEvents ();
            DispatchEvents ();
        }
    }
}