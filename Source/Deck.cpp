
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

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 9; j++){
            std::map<std::string, std::string> Card;
            Card.insert({color[i], rank[j]});
            overallDeck.push_back(Card);
        }
    }

    for (auto i: overallDeck){
        for(auto j: i){
            std::cout << j.first << " " << j.second << std::endl;
        }
    }
}