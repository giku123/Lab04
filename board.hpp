#pragma once

#include "point.hpp"
#include <vector>

class Board {
private:
    int width;
    int height;
    std::vector<std::vector<char>> grid;

public:
    Board(int width = 20, int height = 20);
    int GetWidth() const;
    int GetHeight() const;
    void Draw() const;

    Board& operator=(const Board& other);
    bool operator==(const Board& other) const;
};

std::istream& operator>>(std::istream& in, Board& board);
std::ostream& operator<<(std::ostream& out, const Board& board);
