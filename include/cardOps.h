#pragma once

#include <iostream>
#include <vector>

#include "../src/utils/UNOStructs.h"
#include "helpers.h"
#include "player.h"

class CardOperation
{
public:
    CardOperation();
    void setInitialTopCard();
    void displayCard(const Card &);
    void displayTopCard(const Card &card);
    void displayDeck(const std::vector<Card> &);
    void displayDealtStacks(const std::vector<std::vector<Card>> &);
    bool checkEquivalentCard(Card&, std::stack<Card>&);
    Card *checkEquivalentCardInADeck(Player &currentPlayer, Deck &deck);

    template <typename T>
    static bool isEmpty(std::vector<T>);

};

