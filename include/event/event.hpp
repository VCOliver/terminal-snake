#pragma once

#include "collision.hpp"

class Event {
    public:
        virtual ~Event() = default;
};

class WallCollisionEvent : public Event {

    public:
        WallCollisionEvent() = default;
};

class SelfCollisionEvent : public Event {
    public:
        SelfCollisionEvent() = default;
};

class FoodCollisionEvent : public Event {
    public:
        FoodCollisionEvent() = default;
};

class EventHandler {
    public:
        virtual void handleEvent(Event* event) = 0;
        virtual ~EventHandler() = default;
};