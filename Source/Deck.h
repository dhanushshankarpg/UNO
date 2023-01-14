
#ifndef DECK_H
#define DECK_H

#endif

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Deck
{
private:
    int playerCount;
    int cardCount;
    std::string color[4]{
        "red",
        "green",
        "yellow",
        "blue"};

    std::string rank[9]{
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"};
    std::vector<std::map<std::string, std::string>> overallDeck;

public:
    void initializeDeck();
    void getPlayerCount();
    void getCardCount();
    void createCardSetForPlayers();
};