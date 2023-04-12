//#include "../header/deck.h"
#include "../header/game.h"
#include <iostream>

int main(int, char **)
{
    // Deck *deck = new Deck();
    // deck->initializeDeck();
    // deck->shuffleDeck(deck->overallDeck);
    // deck->dealCards(deck->overallDeck);
    // deck->displayDeltStacks(deck->dealtStack);
    // delete deck;
    Game *game = new Game();
    game->initGame();
    // Deck *game = new Game();
    // deck->testme();
    // game->testme();
    delete game;
}
