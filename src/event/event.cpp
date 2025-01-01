#include "event/event.hpp"

CollisionHandler* WallCollisionEvent::getCollisionHandler() {
    return this->collisionHandler;
}