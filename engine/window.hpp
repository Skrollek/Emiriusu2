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
        virtual void OnUpdate () = 0;

        virtual int GetWidth () const = 0;
        virtual int GetHeight () const = 0;

        virtual void SetEventCallback (const EventCallbackFunction& newCallback) = 0;
        virtual void SetVSync (bool enabled) = 0;
        virtual bool IsVSync () const = 0;

        static Window* Create (const WindowProps& props = WindowProps ());
    };
}

#endif