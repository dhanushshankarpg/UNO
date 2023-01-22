#include<iostream>
#include "Deck.h"

int main(){
    std::cout << "Welcome to UNO" << std::endl;
    Deck *deck = new Deck();
    deck->initializeDeck();
    //deck->displayDeck();
    return 0;
}