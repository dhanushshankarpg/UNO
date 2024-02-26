#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "Deck.h"
#include "../../utils/UNOStructs.h"

class Player
{
    public:
        Player();
        explicit Player(const Deck &);

    public:
        static int s_playerIndex;
        std::vector<Card> m_playerHandCards;
        std::string m_playerName;

    public:
        void m_generatePlayerProfile(const Deck &);
};