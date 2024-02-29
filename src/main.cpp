#include "game.h"

int main(int, char **)
{

    Helpers::intro();
    Helpers::getPlayerCount();
    Helpers::introGame();

    Game game;
    game.initGame();

    return EXIT_SUCCESS;
}