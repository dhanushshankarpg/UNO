#include "../include/player.h"

int Player::s_playerIndex = 0;

Player::Player()= default;


Player::Player(const Deck &deck)
{
    m_generatePlayerProfile(deck);
    ++s_playerIndex;

}

void Player::m_generatePlayerProfile(const Deck &deck)
{
    m_playerHandCards = deck.m_dealtStack[s_playerIndex];
    m_playerName = s_playerIndex ?  "CPU_Player_" + std::to_string(s_playerIndex) : "You" ;
}