#include "app.hpp"

static void error_callback (int error, const char* description) {
    std::cerr << "Error: " << description << '\n';
}

extern bool isGLFWinitialized;

namespace Emiriusu {

#define BIND_EVENT_FUNCTION(x) std::bind(&x, this, std::placeholders::_1)

    Application::Application () {

        glfwSetErrorCallback (error_callback);

        window = Window::create ();
        window-> setEventCallback(BIND_EVENT_FUNCTION(Application::onEvent));
    }

    Application::~Application () {

        delete window;
        if (isGLFWinitialized)
        {
            glfwTerminate ();
            isGLFWinitialized = false;
        } 
    }

    void Application::pollEvents () {

    }

    void Application::dispatchEvents () {
        
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

    void Application::run () {

        while (running) {
            glClearColor(0.2578, 0.52734, 0.9570, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            window->onUpdate ();
        }
    }

    void Application::onEvent(Event& newEvent)
    {
        EventDispatcher dispatcher(newEvent);
        dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(Application::onWindowClose));
        std::cout << "Application::onEvent called\n";
    }

    bool Application::onWindowClose(WindowCloseEvent& newEvent)
    {
        running = false;
        return true;
    }
}