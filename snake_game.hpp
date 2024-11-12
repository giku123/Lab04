#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>

// Enum pentru direcțiile de mișcare ale șarpelui
enum class Direction { UP, DOWN, LEFT, RIGHT };

// Structură care reprezintă un punct pe hartă (coordonatele x, y)
struct Point {
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

// Clasa principală care reprezintă jocul Snake
class SnakeGame {
public:
    SnakeGame(int width, int height);  // Constructor pentru joc
    void startGame();                  // Funcția pentru a începe jocul

private:
    int width, height;                // Dimensiunile hărții
    int score;                         // Scorul jocului
    bool gameOver;                     // Flag pentru a indica dacă jocul s-a încheiat
    Direction currentDirection;        // Direcția curentă a șarpelui
    std::vector<Point> snakeBody;      // Corpul șarpelui
    Point food;                        // Poziția hranei

    // Funcții auxiliare
    void render();                      // Afișează jocul
    void input();                       // Gestionează inputul de la utilizator
    void logic();                       // Logica jocului (mișcarea șarpelui, coliziuni etc.)
    void generateFood();                // Generează hrana
    void moveSnake();                   // Mișcă șarpele
    void checkCollisions();             // Verifică coliziunile cu peretele sau cu corpul
    void gameOverScreen();              // Afișează mesajul de final al jocului
    void sleep(double seconds);         // Pauză pentru simularea timpului real
};

#endif // SNAKE_GAME_HPP
