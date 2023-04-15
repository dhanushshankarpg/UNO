#include "../header/deck.h"
#include "../header/game.h"
#include <iostream>

int main(int, char **)
{
    Deck *deck = new Deck();
    deck->displayDeltStacks(deck->dealtStack);
    Game *game = new Game();
    game->initGame();
    delete deck;
    delete game;
}
