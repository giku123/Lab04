#include "board.hpp"
#include <iostream>

Board::Board(int w, int h) : width(w), height(h), grid(h, std::vector<char>(w, '.')) {}

int Board::GetWidth() const {
    return width;
}

int Board::GetHeight() const {
    return height;
}

void Board::Draw() const {
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
}

Board& Board::operator=(const Board& other) {
    if (this != &other) {
        width = other.width;
        height = other.height;
        grid = other.grid;
    }
    return *this;
}

bool Board::operator==(const Board& other) const {
    return width == other.width && height == other.height && grid == other.grid;
}

std::istream& operator>>(std::istream& in, Board& board) {
    in >> board.width >> board.height;
    board.grid.resize(board.height, std::vector<char>(board.width, '.'));
    return in;
}

std::ostream& operator<<(std::ostream& out, const Board& board) {
    out << board.width << " " << board.height << std::endl;
    for (const auto& row : board.grid) {
        for (const auto& cell : row) {
            out << cell;
        }
        out << std::endl;
    }
    return out;
}
