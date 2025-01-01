#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include "collision.hpp"

enum EventType {
    COLLISION
};

// Alias for the event handler type
using EventHandler = std::function<void(EventType)>;

class Event {
protected:
    std::vector<EventHandler> listeners;

public:

    // Add a listener to the event
    void addListener(const EventHandler& handler);

    // Trigger the event, notifying all listeners
    void trigger(EventType event);
};

class CollisionEvent : public Event {
    private:
        CollisionType type;

    public:

        void setCollisionType(CollisionType type);

        CollisionType getCollisionType();

};