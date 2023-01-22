
#include "Deck.h"

Deck::Deck(){
    getPlayerCount();
    getCardCount();
}

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

void Deck::displayDeck()
{
    checkEmptyDeck(overallDeck);
    for (auto i : overallDeck)
    {
        displayCard(i);
    }
}

void Deck::displayCard(Card &i)
{
    std::cout << "Color: " << i.color << "    "
              << "Rank: " << i.rank << std::endl;
}

void Deck::shuffleDeck()
{
    checkEmptyDeck(overallDeck);
    std::random_shuffle(overallDeck.begin(), overallDeck.end());
}

void Deck::dealCards()
{
    std::vector<std::vector<Card>> dealtStack;
    for (int i = 0; i < playerCount; i++){
        for (int j = 0; j < cardCount; j++){
            dealtStack[i].push_back(overallDeck[j]); // Adds 7 random cards to the player1
            overallDeck.erase(overallDeck[j]);
        }
    }

}