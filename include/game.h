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

    public:
        bool m_isCycleReversed;
        bool m_isGameOver;
        Deck m_deck;
        std::vector<Player> m_players;
};
