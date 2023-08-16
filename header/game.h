#pragma once
#include <iostream>
#include<vector>
#include <thread>
#include <chrono>
#include <stdexcept>

#include "deck.h"
#include "helpers.h"

using namespace std;

class Game : public Helpers {
    public:
        bool m_shouldBreak = false;
        Deck *m_deck = nullptr;

    public:
        Game();
        Game(Deck &);
        // bool isGameWon = false;
        void initGame();
        void gameStart();
        void gameDisplay(); //
        void setSubsequentTopCard(Card &);
        void staticDisplay();
        void pickCardPlayer();
        void initdropCardPlayer();
        void dropCardPlayer(int index);
        void reInstantiateOverallDeck();
};