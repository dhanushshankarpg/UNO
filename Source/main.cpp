#include<iostream>
#include "Deck.h"

int main(){
    std::cout << "Welcome to UNO" << std::endl;

    enum Color
    {
        red,
        green,
        yellow,
        blue
    };

    enum Rank
    {
        one = 1,
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine
    };
    Deck d;
    d.initializeDeck();
    return 0;
}