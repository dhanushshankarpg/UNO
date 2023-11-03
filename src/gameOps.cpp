
#include "../include/gameOps.h"

int GameOperations::s_currentPlayerIndex = 0;
bool GameOperations::s_isCycleReversed = false;

GameOperations::GameOperations() = default;

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
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void GameOperations::clamPlayerIndex()
{
    s_currentPlayerIndex = (s_currentPlayerIndex < 0) ? (s_currentPlayerIndex + Helpers::s_totalPlayerCount) : s_currentPlayerIndex;
    s_currentPlayerIndex = (s_currentPlayerIndex > (Helpers::s_totalPlayerCount - 1)) ? (s_currentPlayerIndex - Helpers::s_totalPlayerCount) : s_currentPlayerIndex;
}

void GameOperations::setGameCycle(Deck& deck)
{
    std::cout<<"The Rank of TOP CARD"<<deck.m_dropDeck.top().rank<<std::endl;
    if (deck.m_dropDeck.top().rank == 10)
    {
        // Rank 10 = REVERSE
        s_isCycleReversed = !s_isCycleReversed;
        std::cout<<"Cycle Reversed"<<std::endl;
        s_currentPlayerIndex = s_isCycleReversed ? (s_currentPlayerIndex - 1) : (s_currentPlayerIndex + 1);
        if (s_currentPlayerIndex > (Helpers::s_totalPlayerCount-1) || s_currentPlayerIndex < 0) clamPlayerIndex();
    }
    else if (deck.m_dropDeck.top().rank == 11)
    {
        // Rank 11 = SKIP
        std::cout<<"Skip Player - "<<s_currentPlayerIndex<<std::endl;
        s_currentPlayerIndex = (s_isCycleReversed ? (s_currentPlayerIndex - 2) : (s_currentPlayerIndex + 2));
        if (s_currentPlayerIndex > (Helpers::s_totalPlayerCount-1) || s_currentPlayerIndex < 0) clamPlayerIndex();
    }
    else
    {
        // Normal Case just Move over players
        s_currentPlayerIndex = s_isCycleReversed ? (s_currentPlayerIndex - 1) : (s_currentPlayerIndex + 1);
        if (s_currentPlayerIndex > (Helpers::s_totalPlayerCount-1) || s_currentPlayerIndex < 0) clamPlayerIndex();
    }
}

int GameOperations::getCurrentPlayer()
{
    return s_currentPlayerIndex;
}