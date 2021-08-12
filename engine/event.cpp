#include "event.hpp"

namespace Emiriusu {

    EventDispatcher& EventDispatcher::EventSystem () {
        static EventDispatcher instance;
        return instance;
    }

    void EventDispatcher::Report (Event* event) {
        
        queueEvents.push_back (event);
    }

    Event* EventDispatcher::Dispatch (EventCategory category) {

        auto itend = queueEvents.end ();
        for (auto it = queueEvents.begin (); it != itend; ++it) {

            if (category & (*it)->GetEventCategory ()) {

                Event* temp = *it;
                queueEvents.erase (it);

                temp->wasHandled = true;
                return temp;
            }
        }

        return new EventNone ();
    }

}