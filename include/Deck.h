#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
#include <unordered_map>

#include "../src/utils/UNOStructs.h"
#include "helpers.h"

class Deck
{
public:
    std::vector<Card> m_overallDeck;
    std::stack<Card> m_dropDeck;
    std::vector<std::vector<Card>> m_dealtStack;
public:
    Deck();
    void initializeDeck();
    void shuffleDeck(std::vector<Card> &);
    void dealCards(std::vector<Card> &);
};
