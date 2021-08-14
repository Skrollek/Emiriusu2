#include "app.hpp"

static void error_callback (int error, const char* description) {
    std::cerr << "Error: " << description << '\n';
}

extern bool isGLFWinitialized;

namespace Emiriusu {

    Application::Application () {

        glfwSetErrorCallback (error_callback);

        window = Window::Create ();
        //window-> SetEventCallback();
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
            glClearColor(0.2578, 0.52734, 0.9570, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            window->OnUpdate ();
        }
    }
}