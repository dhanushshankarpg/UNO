#include "../include/game.h"

Game::Game()
{
    m_isGameOver = false;
    m_isCycleReversed = false;
    m_deck.initializeDeck();
    m_deck.dealCards(m_deck.m_overallDeck);
    for(unsigned i(0); i < Helpers::s_totalPlayerCount; i++)
        m_players.emplace_back(m_deck);
}

void Game::initGame()
{
    while(!m_isGameOver)
    {
        startGame();
    }
}

void Game::startGame()
{
    GameOperations gameOps;
    if (gameOps.getCurrentPlayer() == 0)
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
                gameOps.dropCardHuman(m_players, m_deck);
                break;

            case 'p':
            case 'P':
                gameOps.pickCardHuman(m_players, m_deck);
                break;

            default:
                std::cout << "Invalid Option" << std::endl;
                break;
        }
    }
    else
    {
        staticDisplayForCPUPlayer();
    }
}


void Game::staticDisplayForHumanPlayer()
{
    Helpers::clearScreen();
    CardOperation cardOps;
    cardOps.displayTopCard(m_deck.m_dropDeck.top());
    cardOps.displayDeck(m_players.at(0).m_playerHandCards);
    std::cout << "\"d/D\"->\t Drop\t\t\"p/P\"->\tPick" << std::endl;
}

void Game::staticDisplayForCPUPlayer()
{
    GameOperations gameOps;
    std::cout<<m_players.at(gameOps.getCurrentPlayer()).m_playerName<<"'s Turn"<<std::endl;
    gameOps.AIplay(m_deck);
}

