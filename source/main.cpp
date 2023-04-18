#include "../header/deck.h"
#include "../header/game.h"
#include "../header/player.h"
#include <iostream>

int main(int, char **)
{
    Player *players = new Player();
    Deck *deck = new Deck(*players);
    delete deck;
    delete players;
}
