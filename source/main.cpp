#include "../header/deck.h"
#include "../header/game.h"
#include "../header/player.h"
#include <iostream>

int main(int, char **)
{
    Player *players = new Player();
    Deck *deck = new Deck(*players);
    Game *game = new Game(*deck);
    game->initGame();
    delete game;
    delete deck;
    delete players;
}
