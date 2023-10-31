#pragma once

#include <iostream>
#include <stack>
#include <vector>

#include "../src/utils/UNOStructs.h"
#include "Deck.h"
#include "player.h"

class GameOperations
{
public:
    void pickCardHuman(std::vector<Player>&, Deck&);
    void dropCardHuman(std::vector<Player>&, Deck&);
    void AIplay(Deck &);
    void setGameCycle();
    int getCurrentPlayer();
public:
    static int m_currentPlayerIndex;
};