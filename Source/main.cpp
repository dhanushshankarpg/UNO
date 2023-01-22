#include<iostream>
#include "Deck.h"

int main(){
    std::cout << "Welcome to UNO" << std::endl;
    Deck *deck = new Deck();
    deck->initializeDeck();
    deck->displayDeck();
    deck->shuffleDeck();
    
    std::cout << "------------------------------------------"<<std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    deck->displayDeck();
    delete deck;
    return 0;
}