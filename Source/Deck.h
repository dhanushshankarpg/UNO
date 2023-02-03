
// #ifndef DECK_H
// #define DECK_H

// #endif

#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>
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

public:
    Deck();
    static int count ;
    std::vector<Card> overallDeck;
    void getPlayerCount();
    void getCardCount();
    void initializeDeck();
    void displayDeck(std::vector<Card> &);
    void displayCard(Card &);
    void shuffleDeck(std::vector<Card> &);
    void dealCards(std::vector<Card> &);
    void checkEmptyDeck(std::vector<Card> &);
};