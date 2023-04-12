#pragma once
#include <iostream>
#include<algorithm>
#include <string>
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

struct Card
{
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
    static int count;
    std::vector<Card> overallDeck;
    std::vector<std::vector<Card>> dealtStack;
    void getPlayerCount();
    void getCardCount();
    void initializeDeck();
    void displayDeck(std::vector<Card> &);
    void displayCard(Card &);
    void shuffleDeck(std::vector<Card> &);
    void dealCards(std::vector<Card> &);
    template <typename T>
    bool checkEmptyDeck(std::vector<T> );
    void displayDeltStacks(std::vector<std::vector<Card>> &);
    void testme();
};

