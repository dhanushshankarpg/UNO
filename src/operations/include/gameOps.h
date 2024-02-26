#pragma once

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

#include "../../game/include/Deck.h"
#include "../../game/include/player.h"
#include "cardOps.h"
#include "../../utils/UNOStructs.h"

class GameOperations : public CardOperation
{
public:
    static bool s_isCycleReversed;
    static int s_currentPlayerIndex;

public:
    GameOperations();
    int getCurrentPlayer();
    void pickCardHumanOrCPU(Player&, Deck&);
    void dropCardHuman(Player&, Deck&);
    void dropCardCPU(Player&, Card&, Deck&);
    void AIplay(Player&, Deck &);
    void setPlayerIndex(int);
    void clampPlayerIndex();
    void setGameCycle(Deck&);

};
