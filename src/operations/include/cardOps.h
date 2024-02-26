#pragma once

#include <iostream>
#include <vector>
#include <optional>

#include "../../utils/UNOStructs.h"
#include "../../game/include/helpers.h"
#include "../../game/include/player.h"

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
    Card* checkEquivalentCardInADeck(Player &currentPlayer, Deck &deck);

    template <typename T>
    static bool isEmpty(std::vector<T>);

};

