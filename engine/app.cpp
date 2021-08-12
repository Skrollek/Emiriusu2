#include "app.hpp"

static void error_callback (int error, const char* description) {
    std::cerr << "Error: " << description << '\n';
}

extern bool isGLFWinitialized;

namespace Emiriusu {

    Application::Application () {

        glfwSetErrorCallback (error_callback);

        window = Window::Create ();
    }

    Application::~Application () {

        delete window;
        if (isGLFWinitialized) glfwTerminate ();
    }

    void Application::PollEvents () {

    }

    void Application::DispatchEvents () {
        
        /*Event* ev;

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
        }*/
    }

    void Application::Run () {

        while (running) {
            
            window->OnUpdate ();
        }
    }
}