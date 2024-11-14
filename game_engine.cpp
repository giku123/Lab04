#include "game_engine.hpp"
#include <iostream>

GameEngine::GameEngine() : isRunning(false) {}

void GameEngine::Init() {
    board = Board(20, 20);
    snake = Snake();
    apple = Apple(Point(5, 5));
    isRunning = true;
}

void GameEngine::Run() {
    while (isRunning) {
        Render();
        Update();
    }
}

void GameEngine::ProcessInput(Direction dir) {
    snake.SetDirection(dir);
}

void GameEngine::Update() {
    snake.Move();
    if (snake.HasEaten(apple)) {
        apple = Apple(Point(8, 8)); // Create new apple at a random position (simplified here)
    }
    if (snake.IsColliding()) {
       
