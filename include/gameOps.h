#pragma once

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

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
    void pickCardHumanOrCPU(Player&, Deck&);
    void dropCardHuman(Player&, Deck&);
    void dropCardCPU(Card&, Deck&);
    void AIplay(Player&, Deck &);
    void setGameCycle(Deck &);
    void clampPlayerIndex();
    Card * checkEquivalentCard(Player&, Deck&);
};