#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include "collision.hpp"

class EventType {
    public:
        virtual CollisionType handleEvent() = 0;
        virtual ~EventType() = default;
};

// Alias for the event handler type
using EventHandler = std::function<void(EventType*)>;

class Event {
protected:
    std::vector<EventHandler> listeners;

public:

    // Add a listener to the event
    void addListener(const EventHandler& handler);

    // Trigger the event, notifying all listeners
    void trigger(EventType* event);
};

class CollisionEvent : public EventType {
    private:
        CollisionType type;
        Snake snake;

    public:

        CollisionEvent(Snake snake) : snake(snake) {};

        CollisionType handleEvent() override;

        void setCollisionType(CollisionType type);

        CollisionType getCollisionType();

};