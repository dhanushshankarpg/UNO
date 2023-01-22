
// #ifndef DECK_H
// #define DECK_H

// #endif

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

#include <map>

enum Color
{
    RED = 0,
    GREEN,
    BLUE,
    YELLOW
};

enum Rank
{
    ONE = 0,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE
};

struct Card{
    Rank rank;
    Color color;
    int maxRank = 9;
    int maxColor = 4;
};

class Deck
{
private:
    int playerCount;
    int cardCount;
    const int max_deck_size = 36; // w/o special cards
    std::vector<Card> overallDeck;

public:
    Deck();
    void getPlayerCount();
    void getCardCount();
    void initializeDeck();
    void displayDeck();
    void displayCard(Card &);
    void shuffleDeck();
    void dealCards();
    void checkEmptyDeck(std::vector<Card> &);
};