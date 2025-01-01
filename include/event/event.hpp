#pragma once

#include <vector>
#include <functional>
#include "snake/snake.hpp"

class Handler;
enum class CollisionType;

class Event {
public:
    virtual ~Event() = default;
};

class CollisionEvent : public Event {
    std::vector<Handler*> listeners;

public:

    CollisionEvent() = default;

    void addListener(Handler* listener);

    void trigger(CollisionType collisionType);
};