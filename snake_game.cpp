#include "snake_game.hpp"
#include <conio.h>  // pentru _kbhit() si _getch()

// Constructorul clasei SnakeGame
SnakeGame::SnakeGame(int width, int height) 
    : width(width), height(height), score(0), gameOver(false), currentDirection(Direction::RIGHT) {
    // Poziționăm șarpele în mijlocul hărții
    snakeBody.push_back(Point(width / 2, height / 2));
    generateFood();
}

// Funcția care pornește jocul
void SnakeGame::startGame() {
    while (!gameOver) {
        render();
        input();
        logic();
        sleep(0.1);
    }
    gameOverScreen();
}

// Afișează starea jocului
void SnakeGame::render() {
    system("cls");  // Curăță consola

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                std::cout << "#";  // Perete
            }
            else if (x == food.x && y == food.y) {
                std::cout << "$";  // Hrana
            } 
            else {
                bool snakePart = false;
                for (auto& segment : snakeBody) {
                    if (segment.x == x && segment.y == y) {
                        std::cout << "O";  // Corpul șarpelui
                        snakePart = true;
                        break;
                    }
                }
                if (!snakePart) {
                    std::cout << " ";  // Spațiu gol
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Scor: " << score << std::endl;
}

// Gestionează inputul de la utilizator
void SnakeGame::input() {
    if (_kbhit()) {
        char ch = _getch();
        if (ch == 'w' && currentDirection != Direction::DOWN) currentDirection = Direction::UP;
        if (ch == 's' && currentDirection != Direction::UP) currentDirection = Direction::DOWN;
        if (ch == 'a' && currentDirection != Direction::RIGHT) currentDirection = Direction::LEFT;
        if (ch == 'd' && currentDirection != Direction::LEFT) currentDirection = Direction::RIGHT;
        if (ch == 'q') gameOver = true;  // Apăsarea 'q' oprește jocul
    }
}

// Logica jocului
void SnakeGame::logic() {
    moveSnake();
    checkCollisions();
}

// Mișcă șarpele
void SnakeGame::moveSnake() {
    Point newHead = snakeBody.front();

    switch (currentDirection) {
        case Direction::UP: newHead.y--; break;
        case Direction::DOWN: newHead.y++; break;
        case Direction::LEFT: newHead.x--; break;
        case Direction::RIGHT: newHead.x++; break;
    }

    snakeBody.insert(snakeBody.begin(), newHead);

    // Dacă șarpele a mâncat hrana
    if (newHead.x == food.x && newHead.y == food.y) {
        score++;
        generateFood();
    } else {
        snakeBody.pop_back();  // Șterge ultimul segment al șarpelui
    }
}

// Verifică coliziunile cu peretele sau cu corpul șarpelui
void SnakeGame::checkCollisions() {
    Point head = snakeBody.front();

    // Coliziune cu peretele
    if (head.x == 0 || head.x == width - 1 || head.y == 0 || head.y == height - 1) {
        gameOver = true;
    }

    // Coliziune cu corpul propriu
    for (size_t i = 1; i < snakeBody.size(); ++i) {
        if (snakeBody[i].x == head.x && snakeBody[i].y == head.y) {
            gameOver = true;
            break;
        }
    }
}

// Generează hrana la o locație aleatorie
void SnakeGame::generateFood() {
    food.x = rand() % (width - 2) + 1;
    food.y = rand() % (height - 2) + 1;
}

// Afișează mesajul de final al jocului
void SnakeGame::gameOverScreen() {
    std::cout << "Game Over! Scor final: " << score << std::endl;
}

// Pauză pentru simularea timpului real
void SnakeGame::sleep(double seconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(int(seconds * 1000)));
}
