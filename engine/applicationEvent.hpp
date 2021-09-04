#ifndef EMIRIUSU_APPLICATION_EVENT_HPP
#define EMIRIUSU_APPLICATION_EVENT_HPP

#include "event.hpp"
#include "types.hpp"

namespace Emiriusu {


    class WindowResizeEvent : public Event {

        int width, height;

    public:

        WindowResizeEvent (int newWidth, int newHeight) : width (newWidth), height (newHeight) {}

        inline int getWindowWidth () const { return width; }
        inline int getWindowHeight () const { return height; }

        EVENT_TYPE (WindowResized);
        EVENT_CATTEGORY (EventCategoryApplication);
    };

    class WindowMoveEvent : public Event {

        Vec2i position;

    public:

        WindowMoveEvent (int x, int y) : position (x, y) {};
        WindowMoveEvent (Vec2i& newPosition) : position (newPosition) {};

        inline int getPositionX () const { return position.x; }
        inline int getPositionY () const { return position.y; }
        inline Vec2i& getPosition () { return position; }


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