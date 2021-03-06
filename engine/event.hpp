#ifndef EMIRIUSU_EVENT_HPP
#define EMIRIUSU_EVENT_HPP

#define BIT(x) (1 << x) 

#include <vector>
#include <list>
#include <functional>

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

#define EVENT_TYPE(x) static EventType getStaticEventType() {return EventType::x; }\
                        virtual EventType getEventType() const override {return getStaticEventType(); }\
                        virtual const char* getName() const override {return #x; }

#define EVENT_CATTEGORY(x) virtual int getEventCategory() const override {return x;}

    class Event {

        friend class EventDispatcher;

    public:

        virtual EventType getEventType () const = 0;
        virtual const char* getName () const = 0;
        virtual int getEventCategory () const = 0;

        virtual ~Event () {}

        inline bool isInCateogry (EventCategory category) const { return getEventCategory () & category; }

    protected:

        bool wasHandled = false;
    };

    class EventDispatcher
    {
        template<typename T>
        using EventFunction = std::function<bool(T&)>;
        Event& event;
    public:
        EventDispatcher(Event& initialEvent) : event(initialEvent){}
        template <typename T>
        bool dispatch(EventFunction<T> function)
        {
            if(event.getEventType() == T::getStaticEventType())
            {
                event.wasHandled = function(*(T*)&event);
                return true;
            }
            return false;
        }
    };

    /*class EventDispatcher {

        std::vector <Event*> queueEvents;

        EventDispatcher () {}
        EventDispatcher (const EventDispatcher& ) {}
        ~EventDispatcher () {}

    public:

        static EventDispatcher& EventSystem ();

        void Report (Event* event);
        Event* Dispatch (EventCategory category);
        //bool Dispatch()
    };*/
}

#endif