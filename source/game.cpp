#include"../header/game.h"
#include<iostream>

void Game::initGame()
{
    Deck *deck = new Deck();
    deck->initializeDeck();
    deck->shuffleDeck(deck->overallDeck);
    deck->dealCards(deck->overallDeck);
    deck->displayDeltStacks(deck->dealtStack);
    delete deck;
}


