#include "snake.hpp"

Snake::Snake() : currentDirection(Direction::Top) {
    body.push_front(Point(10, 10));
}

void Snake::Move() {
    Point head = body.front();
    switch (currentDirection) {
        case Direction::Top: head.y--; break;
        case Direction::Bottom: head.y++; break;
        case Direction::Left: head.x--; break;
        case Direction::Right: head.x++; break;
    }
    body.push_front(head);
    body.pop_back();
}

void Snake::Grow() {
    Point tail = body.back();
    body.push_back(tail);
}

void Snake::SetDirection(Direction dir) {
    currentDirection = dir;
}

const std::deque<Point>& Snake::GetBody() const {
    return body;
}

bool Snake::IsColliding() const {
    const Point& head = body.front();
    // Check if the head collides with the body
    for (size_t i = 1; i < body.size(); i++) {
        if (body[i] == head) {
            return true;
        }
    }
    return false;
}

bool Snake::HasEaten(const Apple& apple) {
    if (body.front() == apple.GetPosition()) {
        Grow();
        return true;
    }
    return false;
}
