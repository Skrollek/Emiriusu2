#ifndef EMIRIUSU_WINDOW_HPP
#define EMIRIUSU_WINDOW_HPP

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include "config.hpp"
#include "applicationEvent.hpp"

#include <string>
#include <functional>

namespace Emiriusu {

    struct WindowProps {

        std::string title;
        int width, height;

        WindowProps (const std::string& initialTitle = "Emiriusu2", int initialWidth = 640, int initialHeight = 480) :
            title (initialTitle), width (initialWidth), height (initialHeight) {}
    };

    class Window {

    public:
        using EventCallbackFunction = std::function<void(Event&)>;

        virtual ~Window () {}
        virtual void onUpdate () = 0;

        virtual int getWidth () const = 0;
        virtual int getHeight () const = 0;

        virtual void setEventCallback (const EventCallbackFunction& newCallback) = 0;
        virtual void setVSync (bool enabled) = 0;
        virtual bool isVSync () const = 0;

        static Window* create (const WindowProps& props = WindowProps ());
    };
}

#endif