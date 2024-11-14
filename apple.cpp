#include "apple.hpp"

Apple::Apple() : position(0, 0) {}

Apple::Apple(const Point& pos) : position(pos) {}

Apple::Apple(const Apple& other) : position(other.GetPosition()) {}

Point Apple::GetPosition() const {
    return position;
}

Apple& Apple::operator=(const Apple& other) {
    if (this != &other) {
        position = other.GetPosition();
    }
    return *this;
}

bool Apple::operator==(const Apple& other) const {
    return position == other.GetPosition();
}

std::istream& operator>>(std::istream& in, Apple& apple) {
    in >> apple.position;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Apple& apple) {
    out << apple.position;
    return out;
}
