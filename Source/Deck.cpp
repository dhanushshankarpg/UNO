
#include "Deck.h"

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

void Deck::initializeDeck()
{
    Card card;
    for (int count = 0; count < max_deck_size; count++){

        for (int i = 0; i < card.maxColor; i++)
        {
            for (int j = 0; j < card.maxRank; j++)
            {
                card.color = Color(i);
                card.rank = Rank(j);
                std::cout << Color(card.color) << " " << card.rank << std::endl;
                overallDeck.push_back(card);
            }
        }
    }    
}

void Deck::displayDeck()
{
    if(overallDeck.empty()){
        std::cout << "Deck not initialized, YET!!";
    }

    for (auto i: overallDeck){
        displayCard(i);
    }

}

void Deck::displayCard(Card& i){
    std::cout << i.color << " dfdf  " << i.rank << std::endl;
}