#ifndef EMIRIUSU_WINDOW_WINDOWS_HPP
#define EMIRIUSU_WINDOW_WINDOWS_HPP

#include <GLFW/glfw3.h>
#include "window.hpp"

#ifdef EMIRIUSU_PLATFORM_WINDOWS

namespace Emiriusu {

    class WindowsWindow : public Window {

    private:

        GLFWwindow* glWindow;

        void init (const WindowProps& props);

        struct WindowData {

            std::string title;
            int width, height;
            bool VSync;
            EventCallbackFunction eventCallback;
        };

        WindowData data;

    public:
        WindowsWindow (const WindowProps& props);
        virtual ~WindowsWindow ();

        void onUpdate () override;

        inline int getWidth () const override { return data.width; }
        inline int getHeight () const override { return data.height; }

        inline void setEventCallback(const EventCallbackFunction& newCallback) override {data.eventCallback = newCallback;}
        void setVSync (bool enabled) override;
        bool isVSync () const override { return data.VSync; }
    };

}

#endif

#endif