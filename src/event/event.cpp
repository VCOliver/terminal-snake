#include "event/event.hpp"
#include "event/collision.hpp"

void CollisionEvent::addListener(Handler* listener) {
    listeners.push_back(listener);
}

void CollisionEvent::trigger(CollisionType collisionType) {
    for(auto listener : listeners) {
        auto collisionHandler = dynamic_cast<CollisionHandler*>(listener);
        if (collisionHandler) {
            collisionHandler->handleCollision(collisionType);
        }
    }
}