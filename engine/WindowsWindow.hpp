#ifndef EMIRIUSU_WINDOW_WINDOWS_HPP
#define EMIRIUSU_WINDOW_WINDOWS_HPP

#include <GLFW/glfw3.h>
#include "window.hpp"

#ifdef EMIRIUSU_PLATFORM_WINDOWS

namespace Emiriusu {

    class WindowsWindow : public Window {

    private:

        GLFWwindow* glWindow;

        void Init (const WindowProps& props);

        struct WindowData {

            std::string title;
            int width, height;
            bool VSync;
        };

        WindowData data;

    public:
        WindowsWindow (const WindowProps& props);
        virtual ~WindowsWindow ();

        void OnUpdate () override;

        inline int GetWidth () const override { return data.width; }
        inline int GetHeight () const override { return data.height; }

        void SetVSync (bool enabled) override;
        bool IsVSync () const override { return data.VSync; }
    };

}

#endif

#endif