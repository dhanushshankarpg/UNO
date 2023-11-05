#include "../include/game.h"

Game::Game()
{
    m_isGameOver = false;
    m_deck.initializeDeck();
    m_deck.shuffleDeck(m_deck.m_overallDeck);
    m_deck.dealCards(m_deck.m_overallDeck);
    for(unsigned i(0); i < Helpers::s_totalPlayerCount; i++)
        m_players.emplace_back(m_deck);
}

void Game::initGame()
{
    while(!m_isGameOver)
    {
        startGame();
        m_gameOps.setGameCycle(m_deck);
    }
}

void Game::startGame()
{
    if (m_gameOps.getCurrentPlayer() == 0)
    {
        staticDisplayForHumanPlayer();

        char playerAction;
        std::cin >> playerAction;
        if (std::cin.fail())
            std::cerr << "Input Failure";
        switch (playerAction)
        {
            case 'd':
            case 'D':
                m_gameOps.dropCardHuman(m_players.at(0), m_deck);
                std::cout<<"------------------------------------------------"<<std::endl;
                break;

            case 'p':
            case 'P':
                m_gameOps.pickCardHumanOrCPU(m_players.at(0), m_deck);
                std::cout<<"------------------------------------------------"<<std::endl;
                break;

            default:
                std::cout << "Invalid Option" << std::endl;
                break;
        }
    }
    else
    {
        staticDisplayForCPUPlayer();
        std::cout<<"------------------------------------------------"<<std::endl;
    }
}


void Game::staticDisplayForHumanPlayer()
{
    //Helpers::clearScreen();
    std::cout<<"Your Turn"<<std::endl;
    m_cardOps.displayTopCard(m_deck.m_dropDeck.top());
    m_cardOps.displayDeck(m_players.at(m_gameOps.getCurrentPlayer()).m_playerHandCards);
    std::cout << "\"d/D\"->\t Drop\t\t\"p/P\"->\tPick" << std::endl;
}

void Game::staticDisplayForCPUPlayer()
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout<<"\n";
    std::cout << m_players.at(m_gameOps.getCurrentPlayer()).m_playerName << "'s Turn" << std::endl;
    m_cardOps.displayTopCard(m_deck.m_dropDeck.top());
    m_gameOps.AIplay(m_players.at(m_gameOps.getCurrentPlayer()), m_deck);
    std::cout<<"\n";
}

