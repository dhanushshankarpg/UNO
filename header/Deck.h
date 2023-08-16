#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include "player.h"

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

struct Card
{
    Rank rank;
    Color color;
    int maxRank = 9;
    int maxColor = 4;
};

class Deck
{
public:
    const int max_deck_size = 36; // w/o special cards
    static int count;
    Player *player = nullptr;
    Card m_topCard;
    std::vector<Card> overallDeck; // The Card Deck available after shuffling,
                                   // Ready to distribute
    std::stack<Card> dropDeck; //  It is a LAST in FIRST out entity, hench using std::stack
    std::vector<std::vector<Card>> dealtStack; // The Cards that are in players hand  #todo: this is floating i.e. Changes when games begins
public:
    Deck();
    Deck(Player &);
    void initializeDeck();
    void displayDeck(std::vector<Card> &);
    void displayCard(const Card &);
    void shuffleDeck(std::vector<Card> &);
    void dealCards(std::vector<Card> &);
    void setInitialTopCard();
    template <typename T>
    bool isEmpty(std::vector<T>);
    void displayDeltStacks(std::vector<std::vector<Card>> &);
    void testme();
};
