
#include "../include/gameOps.h"

int GameOperations::s_currentPlayerIndex = 0;
bool GameOperations::s_isCycleReversed = false;

GameOperations::GameOperations() = default;

void GameOperations::pickCardHumanOrCPU(Player& currentPlayer, Deck& deck)
{
    currentPlayer.m_playerHandCards.push_back(deck.m_overallDeck.back());
    deck.m_overallDeck.erase( deck.m_overallDeck.cend());
    std::cout<<currentPlayer.m_playerName<<" Picks...\t"; // for debugging purpose strictly dont display this info
    displayCard(currentPlayer.m_playerHandCards.back());
    checkEquivalentCard(currentPlayer.m_playerHandCards.back(), deck.m_dropDeck);
    if(checkEquivalentCard(currentPlayer.m_playerHandCards.back(), deck.m_dropDeck))
    {
        dropCardCPU(currentPlayer, currentPlayer.m_playerHandCards.back(),deck);
        std::cout<<"Reason: Equivalent Card"<<std::endl;
    }
}

void GameOperations::dropCardHuman(Player& currentPlayer, Deck& deck)
{
    int index;
    std::cout<<"Enter the Card to Drop"<<std::endl;
    std::cin >> index;

    deck.m_dropDeck.push(currentPlayer.m_playerHandCards.at(index));
    std::cout<<currentPlayer.m_playerName<<" Drops...\t";
    displayCard(currentPlayer.m_playerHandCards.at(index));
    currentPlayer.m_playerHandCards.erase(currentPlayer.m_playerHandCards.begin() + index);
}

void GameOperations::dropCardCPU(Player& currentPlayer, Card& card, Deck& deck)
{
    deck.m_dropDeck.push(card);
    std::cout<<currentPlayer.m_playerName<<" Drops...\t";
    displayCard(card);
    currentPlayer.m_playerHandCards.pop_back();
}

void GameOperations::AIplay(Player& currentPlayer, Deck& deck)
{
    Card* card = nullptr;
    card = checkEquivalentCardInADeck(currentPlayer, deck);
    if(card == nullptr)
    {
        pickCardHumanOrCPU(currentPlayer,deck);
    }
    else
    {
        dropCardCPU(currentPlayer,*card,deck);
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void GameOperations::clampPlayerIndex()
{
    s_currentPlayerIndex = (s_currentPlayerIndex < 0) ? (s_currentPlayerIndex + Helpers::s_totalPlayerCount) : s_currentPlayerIndex;
    s_currentPlayerIndex = (s_currentPlayerIndex > (Helpers::s_totalPlayerCount - 1)) ? (s_currentPlayerIndex - Helpers::s_totalPlayerCount) : s_currentPlayerIndex;
}

void GameOperations::setGameCycle(Deck& deck)
{
//    std::cout<<"The Rank of TOP CARD"<<deck.m_dropDeck.top().rank<<std::endl;
    if (deck.m_dropDeck.top().rank == 10)
    {
        // Rank 10 = REVERSE
        s_isCycleReversed = !s_isCycleReversed;
        std::cout<<"Cycle Reversed"<<std::endl;
        s_currentPlayerIndex = s_isCycleReversed ? (s_currentPlayerIndex - 1) : (s_currentPlayerIndex + 1);
        if (s_currentPlayerIndex > (Helpers::s_totalPlayerCount-1) || s_currentPlayerIndex < 0) clampPlayerIndex();
    }
    else if (deck.m_dropDeck.top().rank == 11)
    {
        // Rank 11 = SKIP
        std::cout<<"Skip Player - "<<s_currentPlayerIndex<<std::endl;
        s_currentPlayerIndex = (s_isCycleReversed ? (s_currentPlayerIndex - 2) : (s_currentPlayerIndex + 2));
        if (s_currentPlayerIndex > (Helpers::s_totalPlayerCount-1) || s_currentPlayerIndex < 0) clampPlayerIndex();
    }
    else
    {
        // Normal Case just Move over players
        s_currentPlayerIndex = s_isCycleReversed ? (s_currentPlayerIndex - 1) : (s_currentPlayerIndex + 1);
        if (s_currentPlayerIndex > (Helpers::s_totalPlayerCount-1) || s_currentPlayerIndex < 0) clampPlayerIndex();
    }
}

int GameOperations::getCurrentPlayer()
{
    return s_currentPlayerIndex;
}
