#pragma once

#include <iostream>
#include <stack>
#include <vector>

#include "Deck.h"
#include "player.h"
#include "../src/utils/UNOStructs.h"

class GameOperations
{
public:
    static bool s_isCycleReversed;
    static int s_currentPlayerIndex;

public:
    GameOperations();
    int getCurrentPlayer();
    void pickCardHuman(std::vector<Player>&, Deck&);
    void dropCardHuman(std::vector<Player>&, Deck&);
    void AIplay(Deck &);
    void setGameCycle(Deck &);
    void clamPlayerIndex();
};