#include "snake_game.hpp"

int main() {
    srand(time(0));  // Inițializare seed pentru generarea de numere aleatoare

    // Creăm o instanță a jocului cu dimensiuni de 20x10
    SnakeGame game(20, 10);
    game.startGame();  // Începem jocul

    return 0;
}
