
#include "../include/gameOps.h"

int GameOperations::m_currentPlayerIndex = 0;

void GameOperations::pickCardHuman( std::vector<Player>& players, Deck& deck)
{
    players.at(0).m_playerHandCards.push_back(deck.m_overallDeck.back());
    deck.m_overallDeck.erase( deck.m_overallDeck.cend());
    // #Todo: check for drop due to color/rank clash with top card
    // #Todo: check for container boundries

}

void GameOperations::dropCardHuman(std::vector<Player>& players, Deck& deck)
{
    int index;
    std::cout<<"Enter the Card to Drop"<<std::endl;
    std::cin >> index;

    deck.m_dropDeck.push(players.at(0).m_playerHandCards.at(index));
    players.at(0).m_playerHandCards.erase(players.at(0).m_playerHandCards.begin() + index);
    // #Todo: check for container boundries
}

void GameOperations::AIplay(Deck& deck)
{
    std::cout<<"AI Plays"<<std::endl;
}


void GameOperations::setGameCycle()
{

}

int GameOperations::getCurrentPlayer() {
    return m_currentPlayerIndex;
}
