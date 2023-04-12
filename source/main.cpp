#include "../header/Deck.h"
#include <iostream>

int main(int, char **)
{
    Deck *deck = new Deck();
    deck->initializeDeck();
    deck->shuffleDeck(deck->overallDeck);
    deck->dealCards(deck->overallDeck);
    deck->displayDeltStacks(deck->dealtStack);
    delete deck;
}
