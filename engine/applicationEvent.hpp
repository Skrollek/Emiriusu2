#ifndef EMIRIUSU_APPLICATION_EVENT_HPP
#define EMIRIUSU_APPLICATION_EVENT_HPP

#include "event.hpp"
#include "types.hpp"

namespace Emiriusu {

    class WindowResizeEvent : public Event {

        int w_width, w_height;

    public:

        WindowResizeEvent (int width, int height) : w_width (width), w_height (height) {}

        inline int GetWindowWidth () const { return w_width; }
        inline int GetWindowHeight () const { return w_height; }

        EVENT_TYPE (WindowResized);
        EVENT_CATTEGORY (EventCategoryApplication);
    };

    class WindowMoveEvent : public Event {

        Vec2i position;

    public:

        WindowMoveEvent (int x, int y) : position (x, y) {};
        WindowMoveEvent (Vec2i& pos) : position (pos) {};

        inline int GetPositionX () const { return position.x; }
        inline int GetPositionY () const { return position.y; }
        inline Vec2i& GetPosition () { return position; }


        EVENT_TYPE (WindowMoved);
        EVENT_CATTEGORY (EventCategoryApplication);
    };

    class WindowCloseEvent : public Event {

    public:

        WindowCloseEvent () {}

        EVENT_TYPE (WindowClosed);
        EVENT_CATTEGORY (EventCategoryApplication);
    };
}

#endif