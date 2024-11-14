#pragma once

#include <deque>
#include "point.hpp"
#include "direction.hpp"
#include "apple.hpp"

class Snake {
private:
    std::deque<Point> body;
    Direction currentDirection;

public:
    Snake();
    void Move();
    void Grow();
    void SetDirection(Direction dir);
    const std::deque<Point>& GetBody() const;
    bool IsColliding() const;
    bool HasEaten(const Apple& apple);
};
