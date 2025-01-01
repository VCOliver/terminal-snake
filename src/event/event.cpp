#include "event/event.hpp"
#include "screen/screen.hpp"

void Event::addListener(const EventHandler& handler) {
    listeners.push_back(handler);
}

void Event::trigger(EventType* event) {
    for (const auto& handler : listeners) {
        handler.handleEvent(event);
    }
}

CollisionEvent::CollisionEvent(Snake snake) : snake(snake) {
    this->type = NONE;
}

CollisionType CollisionEvent::handleEvent() { // void will fix?
    auto head_pos = snake.getHeadPosition();
    auto screenSize = Screen::getScreenSize();
    if(head_pos.x < 0 || head_pos.x > screenSize.x || head_pos.y < 0 || head_pos.y > screenSize.y) {
        return WALL;
    }
    return NONE;
}

void CollisionEvent::setCollisionType(CollisionType type) {
    this->type = type;
}

CollisionType CollisionEvent::getCollisionType() {
    return this->type;
}