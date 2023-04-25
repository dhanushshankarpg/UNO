#include"deck.h"
#include<iostream>
#include<vector>

class Game  {
    public:
        Card m_topCard;
        Deck *m_deck = nullptr;

    public:
        Game();
        Game(Deck &);
        void initGame();
        void setTopCard();
        void displayheaders();
        // void gameDisplay(std::vector(Card));
};