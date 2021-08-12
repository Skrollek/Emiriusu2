#ifndef EMIRIUSU_EVENT_HPP
#define EMIRIUSU_EVENT_HPP

#define BIT(x) (1 << x) 

#include <vector>
#include <list>

namespace Emiriusu {

    enum class EventType {
        None = 0,
        KeyPressed, KeyRepeat, KeyReleased,
        MouseMoved, MouseButtonPressed, MouseButtonReleased,
        WindowResized, WindowMoved, WindowClosed
    };

    enum EventCategory {
        EventCategoryNone = BIT(0),
        EventCategoryApplication = BIT(1),
        EventCategoryInput = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4),
        EventCategoryKey = BIT(5)
    };

#define EVENT_TYPE(x) static EventType GetStaticEventType() {return EventType::x; }\
                        virtual EventType GetEventType() const override {return GetStaticEventType(); }\
                        virtual const char* GetName() const override {return #x; }

#define EVENT_CATTEGORY(x) virtual int GetEventCategory() const override {return x;}

    class Event {

        friend class EventDispatcher;

    public:

        virtual EventType GetEventType () const = 0;
        virtual const char* GetName () const = 0;
        virtual int GetEventCategory () const = 0;

        virtual ~Event () {}

        inline bool IsInCateogry (EventCategory category) const { return GetEventCategory () & category; }

    protected:

        bool wasHandled = false;
    };

    class EventDispatcher {

        std::list <Event*> queueEvents;

        EventDispatcher () {}
        EventDispatcher (const EventDispatcher& ) {}
        ~EventDispatcher () {}

    public:

        static EventDispatcher& EventSystem ();

        void Report (Event* newEvent);
        Event* Dispatch (EventCategory category);
    };
}

#endif