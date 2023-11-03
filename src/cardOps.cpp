#include "../include/cardOps.h"

CardOperation::CardOperation() = default;

void CardOperation::setInitialTopCard()
{

}

template <typename T>
bool CardOperation::isEmpty(std::vector<T> bundleOfAnyThing)
{
    if (bundleOfAnyThing.empty())
    {
        std::cout << "Empty Entity!!!";
        return true;
    }
    else
    {
        return false;
    }
}

void CardOperation::displayDealtStacks(const std::vector<std::vector<Card>> &dealtstack) {
    if (!isEmpty(dealtstack))
    {
        for (const auto& deck: dealtstack)
        {
            displayDeck(deck);
        }
    }
}

void CardOperation::displayDeck(const std::vector<Card> & deck)
{
    std::cout<<"Your Hand::"<<std::endl;
    if (!isEmpty(deck))
    {
        int cardIndex = 0;
        for (const auto& card: deck)
        {
            std::cout<<cardIndex<<"\t";
            displayCard(card);
            cardIndex++;
        }
    }
}

void CardOperation::displayCard(const Card & card)
{
    std::string colors[] = {"","RED", "GREEN", "BLUE", "YELLOW"};
    std::string rank[] = {    "","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","REVERSE","SKIP", "DRAW2",};
    std::cout << "Color: " << colors[card.color] << "\t"
              << "Rank: " << rank[card.rank]<< std::endl;
}

void CardOperation::displayTopCard(const Card & card)
{
    std::cout << "TOP CARD::";
    std::string colors[] = {"","RED", "GREEN", "BLUE", "YELLOW"};
    std::string rank[] = {    "","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","REVERSE","SKIP", "DRAW2",};
    std::cout << "Color: " << colors[card.color] << "\t"
              << "Rank: " << rank[card.rank]<< std::endl;
}
