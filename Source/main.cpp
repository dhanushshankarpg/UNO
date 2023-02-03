#include<iostream>
#include "Deck.h"

int main(){
    std::cout << "Welcome to UNO" << std::endl;
    Deck *deck = new Deck();
    deck->initializeDeck();
    //deck->displayDeck(deck->overallDeck);
    deck->shuffleDeck(deck->overallDeck);
    deck->dealCards(deck->overallDeck);

    //deck->displayDeck();
    delete deck;
    return 0;
}