#include "event/event.hpp"

void Event::addListener(const EventHandler& handler) {
    listeners.push_back(handler);
}

void Event::trigger(EventType event) {
    for (const auto& handler : listeners) {
        handler(event);
    }
}

void CollisionEvent::setCollisionType(CollisionType type) {
    this->type = type;
}

CollisionType CollisionEvent::getCollisionType() {
    return this->type;
}