#pragma once

#include "board.hpp"
#include "snake.hpp"
#include "apple.hpp"
#include "direction.hpp"
#include <memory>

class GameEngine {
private:
    Board board;
    Snake snake;
    Apple apple;
    bool isRunning;

public:
    GameEngine();
    void Init();
    void Run();
    void ProcessInput(Direction dir);
    void Update();
    void Render() const;
};
