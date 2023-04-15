#include "../header/deck.h"

Deck::Deck()
{
    std::cout << "Constructor Deck" << std::endl;
    getPlayerCount();
    getCardCount();
    initializeDeck();
    shuffleDeck(overallDeck);
    dealCards(overallDeck);
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
    std::string colors[] = {"RED", "GREEN", "BLUE", "YELLOW"};
    std::string colorCodes[] = {"\033[31m", "\033[32m", "\033[34m", "\033[33m", "\033[0m"};
    std::string result = colorCodes[i.color] + colors[i.color] + colorCodes[4];
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