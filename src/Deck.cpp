#include "../include/Deck.h"

Deck::Deck() = default;

void Deck::initializeDeck()
{
    for (int i = 1; i <= MAXCOLOR ; i++)
    {
        for (int j = 1; j <= MAXRANK; j++)
        {
            Card card{};
            card.color = Color(i);
            card.rank = Rank(j);
            m_overallDeck.push_back(card);
        }
    }
}

void Deck::shuffleDeck(std::vector<Card> &deckofCards)
{
    if(!deckofCards.empty())
    {
        std::shuffle(deckofCards.begin(), deckofCards.end(), std::mt19937(std::random_device()()));
    }
}

void Deck::dealCards(std::vector<Card> &deckofCards)
{
    for (int i = 0; i < Helpers::s_totalPlayerCount ; i++)
    {
        std::vector<Card> hand;
        for (int j = 0; j < CARD_COUNT_PER_HAND; j++)
        {
            hand.push_back(deckofCards.front());
            deckofCards.erase(deckofCards.begin());
        }
        m_dealtStack.push_back(hand);
    }
    //sets the top card Initially
    deckofCards.front().isAlive = true;
    m_dropDeck.push(deckofCards.front());
}


