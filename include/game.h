#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>

#include "Deck.h"
#include "helpers.h"
#include "player.h"
#include "cardOps.h"
#include "gameOps.h"

class Game {

    public:
        Game();
        void initGame();
        void startGame();
        void staticDisplayForHumanPlayer();
        void staticDisplayForCPUPlayer();
        void setTopCardValidity();

    public:
        bool m_isGameOver;
        Deck m_deck;
        Card m_topCard;
        GameOperations m_gameOps;
        CardOperation m_cardOps;
        std::vector<Player> m_players;

};

