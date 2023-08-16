#include "../header/deck.h"

Deck::Deck()
{
    std::cout << "Constructor Deck" << std::endl;
}
Deck::Deck(Player &p)
{

    this->player = &p;
    // this->player->getPlayerName();
    initializeDeck();
    // std::cout << p.name<< std::endl;
}

int Deck::count = 0;

template <typename T>
bool Deck::isEmpty(std::vector<T> d)
{
    if (d.empty())
    {
        std::cout << "Deck Empty!!!";
        return true;
    }
    else
    {
        return false;
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
    std::cout << "Size of Before dist OVERALL DECK::" << overallDeck.size() << std::endl;

    dealCards(overallDeck);
    std::cout << "Size of After dist OVERALL DECK::" << overallDeck.size() << std::endl;
}

void Deck::displayDeck(std::vector<Card> &deckofCards)
{
    if (!isEmpty(deckofCards))
    {
        std::cout << "----------------------------------------" << std::endl;
        size_t index = 0;
        for (const auto &i : deckofCards)
        {
            std::cout << "|Index:  --  " << index << "\t";
            displayCard(i);
            index++;
        }
        std::cout << "----------------------------------------" << std::endl;
    }
}

void Deck::displayCard(const Card &i)
{

    std::string colors[] = {"RED", "GREEN", "BLUE", "YELLOW"};
    std::string asciicolorCodes[] = {"\033[31m", "\033[32m", "\033[34m", "\033[33m", "\033[0m"}; // not working in cmd?
    std::string result = asciicolorCodes[i.color] + colors[i.color] + asciicolorCodes[4];
    std::cout << "Color: " << result << "\t"
              << "Rank: " << i.rank<< "|" << std::endl;
}

void Deck::shuffleDeck(std::vector<Card> &deckofCards)
{
    if (!isEmpty(deckofCards))
    {
        std::random_shuffle(deckofCards.begin(), deckofCards.end());
    }
}

void Deck::dealCards(std::vector<Card> &deckofCards)
{
    std::vector<Card> hand;
    for (int i = 0; i < this->player->playerCount; i++)
    {
        for (int j = 0; j < this->player->cardCount; j++)
        {
            hand.push_back(deckofCards.front());
            deckofCards.erase(deckofCards.begin());
        }
        dealtStack.push_back(hand);
        hand.clear();
    }
    setInitialTopCard();
}

void Deck::displayDeltStacks(std::vector<std::vector<Card>> &dealtStack)
{
    if (!isEmpty(dealtStack))
    {
        for (int16_t i = 0; i < dealtStack.size(); i++)
        {
            displayDeck(dealtStack[i]);
        }
    }
}

void Deck::setInitialTopCard()
{
    this->dropDeck.push(this->overallDeck.back());
    this->m_topCard = this->dropDeck.top();
    this->overallDeck.erase(this->overallDeck.end());
}

void Deck::testme()
{
    std::cout << "Test Function Called: Class DECK\n Fucking learn me soon!!!" << std::endl;
}