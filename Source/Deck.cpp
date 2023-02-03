
#include "Deck.h"

Deck::Deck()
{
    getPlayerCount();
    getCardCount();
}

int Deck::count = 0;

void Deck::getPlayerCount()
{
    std::cout << "Enter number of Players" << std::endl;
    std::cin >> playerCount;
}

void Deck::getCardCount()
{
    std::cout << "Enter number of Card" << std::endl;
    std::cin >> cardCount;
}

void Deck::checkEmptyDeck(std::vector<Card> &d)
{
    if (d.empty())
    {
        std::cout << "Deck not initialized, YET!!";
        return;
    }
}

void Deck::initializeDeck()
{
    Card card;

    for (int i = 0; i < card.maxColor; i++)
    {
        for (int j = 0; j < card.maxRank; j++)
        {
            card.color = Color(i);
            card.rank = Rank(j);
            overallDeck.push_back(card);
        }
    }
}

void Deck::displayDeck(std::vector<Card> &deckofCards)
{
    checkEmptyDeck(deckofCards);
    for (auto i : deckofCards)
    {
        displayCard(i);
    }
    std::cout << "------------------" << std::endl;
}

void Deck::displayCard(Card &i)
{
    // int count = 0;
    std::cout << count << " ";
    std::cout << "Color: " << i.color << "    "
              << "Rank: " << i.rank << std::endl;
    count++;
}

void Deck::shuffleDeck(std::vector<Card> &deckofCards)
{
    checkEmptyDeck(overallDeck);
    std::random_shuffle(overallDeck.begin(), overallDeck.end());
}

void Deck::dealCards(std::vector<Card> &deckofCards)
{
    std::vector<std::vector<Card>> dealtStack; // Dealt cards in hand are mini version of decks?
    std::vector<Card> hand;
    for (int i = 0; i < playerCount; i++)
    {
        for (int j = 0; j < cardCount; j++)
        {
            hand.push_back(deckofCards[0]);
            deckofCards.erase(deckofCards.begin());
        }
        dealtStack.push_back(hand);
        hand.clear();
    }
    
    for(auto i: dealtStack){
        displayDeck(i);
    }
}