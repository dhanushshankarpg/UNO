#include"../header/game.h"



Game::Game()
{
}

void Game::initGame()
{
    std::cerr << "...UNO++...\n" << std::endl;
    std::cout << "Press Enter to Continue..." << std::endl;
    std::cin.get();
}


Game::Game(Deck &d, Helpers &h)
{

    this->m_deck = &d;
    this->m_helper = &h;
}


Card Game::setTopCard()
{
    m_topCard = m_deck->overallDeck[0];
    m_deck->displayCard(m_topCard);

    return m_topCard;
}

void Game::gameStart()
{
    int interval = 2000;
    while(1) // make a variable to find the winner
    {
        //m_helper->clearScreen();
        setTopCard();
    }
}
