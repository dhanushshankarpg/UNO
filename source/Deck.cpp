#include "../header/deck.h"

Deck::Deck()
{
    std::cout << "Constructor Deck" << std::endl;

}
Deck::Deck( Player &p)
{

    this->player = &p;
    initializeDeck();
    //std::cout << p.name<< std::endl;
}

int Deck::count = 0;

template <typename T>
bool Deck::checkEmptyDeck(std::vector<T> d)
{
    if (d.empty())
    {
        std::cout << "Deck not initialized, YET!!";
        return false;
    }
    else{
        return true;
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
    shuffleDeck(overallDeck);
    dealCards(overallDeck);
}

void Deck::displayDeck(std::vector<Card> &deckofCards)
{
    if(checkEmptyDeck(deckofCards))
    {
        for (auto i : deckofCards)
        {
            displayCard(i);
        }
        std::cout << "------------------" << std::endl;
    }
}

void Deck::displayCard(Card &i)
{
    std::string colors[] = {"RED", "GREEN", "BLUE", "YELLOW"};
    std::string asciicolorCodes[] = {"\033[31m", "\033[32m", "\033[34m", "\033[33m", "\033[0m"};
    std::string result = asciicolorCodes[i.color] + colors[i.color] + asciicolorCodes[4];
    std::cout << "Color: " << result << "    "
              << "Rank: " << i.rank << std::endl;
}

void Deck::shuffleDeck(std::vector<Card> &deckofCards)
{
    checkEmptyDeck(overallDeck);
    std::random_shuffle(overallDeck.begin(), overallDeck.end());
}

void Deck::dealCards(std::vector<Card> &deckofCards)
{
    std::vector<Card> hand;
    for (int i = 0; i < this->player->playerCount ; i++)
    {
        for (int j = 0; j < this->player->cardCount; j++)
        {
            hand.push_back(deckofCards[0]);
            deckofCards.erase(deckofCards.begin());
        }
        dealtStack.push_back(hand);
        hand.clear();
    }
}

void Deck::displayDeltStacks(std::vector<std::vector<Card>> &dealtStack)
{
    if (checkEmptyDeck(dealtStack)){
        for (int i = 0; i < dealtStack.size(); i++)
        {
            displayDeck(dealtStack[i]);
        }
    }
}



void Deck::testme(){
    std::cout << "Test Function Called: Class DECK\n Fucking learn me soon!!!" << std::endl;
}