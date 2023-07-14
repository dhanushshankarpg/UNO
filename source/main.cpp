#include "../header/deck.h"
#include "../header/game.h"
#include "../header/player.h"
#include "../header/helpers.h"
#include <iostream>
using namespace std;

int main(int, char **)
{
    
    Player *players = new Player();
    Helpers *helper = new Helpers();
    Deck *deck = new Deck(*players);
    Game *game = new Game(*deck, *helper);
    game->initGame();
    game->gameStart(); 
    delete game;
    delete deck;
    delete players;
 }
