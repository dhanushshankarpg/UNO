#pragma once
#include <iostream>
#include<vector>
#include <thread>
#include <chrono>
using namespace std;

#include "deck.h"
#include "helpers.h"

class Game  {
    public:
        Deck *m_deck = nullptr;
        Helpers *m_helper = nullptr;
        Card m_topCard;

    public:
        Game();
        Game(Deck &, Helpers &);
        void initGame();
        void gameStart();
        Card setTopCard();
};