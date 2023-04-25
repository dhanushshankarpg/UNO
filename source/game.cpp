#include"../header/game.h"
#include<iostream>

void Game::initGame()
{
    std::cerr << "...UNO++...\n" << std::endl;
    std::cout << "Press Enter to Continue..." << std::endl;
    std::cin.get();
}

Game::Game()
{

}

Game::Game(Deck &d)
{

    this->m_deck = &d;
    m_deck->displayDeltStacks(m_deck->dealtStack);
}

void Game::setTopCard()
{
    
}

void Game::displayheaders()
{   
    
    std::cout << "Player 1:   " << m_deck->player->name << std::endl;
}
