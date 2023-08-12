#include "../header/deck.h"
#include "../header/game.h"
#include "../header/player.h"
#include "../header/helpers.h"
#include <iostream>
using namespace std;

int main(int, char **)
{
    
    //Init
    Player *players = new Player();
    Helpers *helper = new Helpers();
    Deck *deck = new Deck(*players);
    Game *game = new Game(*deck, *helper);

    //bootstraps
    //game->initGame();
    game->gameStart();

    //Clean Up 
    delete game;
    delete deck;
    delete players;
}
