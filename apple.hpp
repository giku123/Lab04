#pragma once

#include "point.hpp"

class Apple {
private:
    Point position;

public:
    Apple();
    Apple(const Point& pos);
    Apple(const Apple& other);
    Point GetPosition() const;

    Apple& operator=(const Apple& other);
    bool operator==(const Apple& other) const;
};

std::istream& operator>>(std::istream& in, Apple& apple);
std::ostream& operator<<(std::ostream& out, const Apple& apple);


