
#include "include/gameOps.h"

int GameOperations::s_currentPlayerIndex = 0;
bool GameOperations::s_isCycleReversed = false;

GameOperations::GameOperations() = default;

void GameOperations::pickCardHumanOrCPU(Player& currentPlayer, Deck& deck)
{
    currentPlayer.m_playerHandCards.push_back(deck.m_overallDeck.back());
    deck.m_overallDeck.erase( deck.m_overallDeck.cend());
    std::cout<<currentPlayer.m_playerName<<" Picks...\t"; // for debugging purpose strictly dont display this info
    displayCard(currentPlayer.m_playerHandCards.back());
    checkEquivalentCard(currentPlayer.m_playerHandCards.back(), deck.m_dropDeck); // Bro wtf is this
    if(checkEquivalentCard(currentPlayer.m_playerHandCards.back(), deck.m_dropDeck))
    {
        dropCardCPU(currentPlayer, currentPlayer.m_playerHandCards.back(),deck);
        std::cout<<"Reason: Equivalent Card Rank/Color"<<std::endl;
    }
}

void GameOperations::dropCardHuman(Player& currentPlayer, Deck& deck)
{
    int index;
    std::cout<<"Enter the Card to Drop"<<std::endl;
    std::cin >> index;

    deck.m_dropDeck.push(currentPlayer.m_playerHandCards.at(index));

    deck.m_dropDeck.top().isAlive = true; // making top card active
    std::cout<<currentPlayer.m_playerName<<" Drops...\t";
    displayCard(currentPlayer.m_playerHandCards.at(index));
    currentPlayer.m_playerHandCards.erase(currentPlayer.m_playerHandCards.begin() + index);
}

void GameOperations::dropCardCPU(Player& currentPlayer, Card& card, Deck& deck)
{
    deck.m_dropDeck.push(card);
    deck.m_dropDeck.top().isAlive = true;
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
}

void GameOperations::clampPlayerIndex()
{
    s_currentPlayerIndex = (s_currentPlayerIndex < 0) ? (s_currentPlayerIndex + Helpers::s_totalPlayerCount) : s_currentPlayerIndex;
    s_currentPlayerIndex = (s_currentPlayerIndex > (Helpers::s_totalPlayerCount - 1)) ? (s_currentPlayerIndex - Helpers::s_totalPlayerCount) : s_currentPlayerIndex;
}

void GameOperations::setGameCycle(Deck& deck)
{
//    std::cout<<"Print from GameOps"<<std::endl;displayTopCard(deck.m_dropDeck.top());
    if (deck.m_dropDeck.top().rank == 10 && deck.m_dropDeck.top().isAlive)
    {
        // Rank 10 = REVERSE
        s_isCycleReversed = !s_isCycleReversed;
        std::cout<<"Cycle Reversed"<<std::endl;
        deck.m_dropDeck.top().isAlive = false;
        setPlayerIndex( 1);
    }
    else if (deck.m_dropDeck.top().rank == 11 && deck.m_dropDeck.top().isAlive)
    {
        // Rank 11 = SKIP
        std::cout<<"Skipping Next Player "<<std::endl;
        std::cout<<"------------------------------------------------"<<std::endl;
        deck.m_dropDeck.top().isAlive = false;
        setPlayerIndex( 2);
    }
    else
    {
        // Normal Case just Move over players
        setPlayerIndex(1);
    }
}

void GameOperations::setPlayerIndex(int offsetPlayerIndex)
{
    s_currentPlayerIndex = (s_isCycleReversed ? (s_currentPlayerIndex - offsetPlayerIndex) : (s_currentPlayerIndex + offsetPlayerIndex));
    if (s_currentPlayerIndex > (Helpers::s_totalPlayerCount-1) || s_currentPlayerIndex < 0) clampPlayerIndex();
}

int GameOperations::getCurrentPlayer()
{
    return s_currentPlayerIndex;
}

