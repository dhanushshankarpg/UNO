#include "../include/deck.h"
#include "../include/game.h"


int main(int, char **)
{
    Helpers::intro();
    Helpers::getPlayerCount();
    Helpers::introGame();

    Game game;
    game.initGame();

    return 0;
}