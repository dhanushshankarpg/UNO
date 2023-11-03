
#include "../include/gameOps.h"

int GameOperations::s_currentPlayerIndex = 0;
bool GameOperations::s_isCycleReversed = false;

GameOperations::GameOperations() = default;

void GameOperations::pickCardHumanOrCPU(Player& currentPlayer, Deck& deck)
{
    Card* card = nullptr;
    currentPlayer.m_playerHandCards.push_back(deck.m_overallDeck.back());
    deck.m_overallDeck.erase( deck.m_overallDeck.cend());
    card = checkEquivalentCard(currentPlayer, deck);
    if(checkEquivalentCard(currentPlayer, deck) == nullptr)
    {
        dropCardCPU(*card, deck);
    }
    else
    {
        std::cout<<"Card Picked by : "<<currentPlayer.m_playerName<<std::endl;
    }
    // #Todo: check for drop due to color/rank clash with top card
}

void GameOperations::dropCardHuman(Player& currentPlayer, Deck& deck)
{
    int index;
    std::cout<<"Enter the Card to Drop"<<std::endl;
    std::cin >> index;

    deck.m_dropDeck.push(currentPlayer.m_playerHandCards.at(index));
    currentPlayer.m_playerHandCards.erase(currentPlayer.m_playerHandCards.begin() + index);
    std::cout<<"Card Dropped by : "<<currentPlayer.m_playerName<<std::endl;
}

void GameOperations::dropCardCPU(Card& card, Deck& deck)
{
    deck.m_dropDeck.push(card);
}

Card * GameOperations::checkEquivalentCard(Player& currentPlayer, Deck& deck)
{
    Card* equiCard = nullptr;
    for(auto & playerHandCard : currentPlayer.m_playerHandCards)
    {
        if( playerHandCard.rank == deck.m_dropDeck.top().rank ||
            playerHandCard.color == deck.m_dropDeck.top().color)
        {
            equiCard = &playerHandCard;
        }
    }
    return equiCard;

}

void GameOperations::AIplay(Player& currentPlayer, Deck& deck)
{
    Card* card = nullptr;
    card = checkEquivalentCard(currentPlayer, deck);
    if(card == nullptr)
    {
        pickCardHumanOrCPU(currentPlayer,deck);
    }
    else
    {
        dropCardCPU(*card,deck);
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