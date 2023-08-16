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


Game::Game(Deck &d)
{

    this->m_deck = &d;
}


void Game::setSubsequentTopCard(Card &card)
{
    m_deck->dropDeck.push(card);
    m_deck->m_topCard = m_deck->dropDeck.top();
}

void Game::gameStart()
{
    while(!m_shouldBreak) 
    {
        gameDisplay();
    }
}

void Game::staticDisplay(){
    std::cout << "TOP CARD:\t" << std::endl;
    m_deck->displayCard(m_deck->dropDeck.top());
    if (!m_deck->isEmpty(m_deck->dealtStack[0]))
    {
        std::cout << "Your CARDS:\t" << std::endl;
        m_deck->displayDeck(m_deck->dealtStack[0]);
        std::cout << "\"d/D\"->\t Drop\t\t\"p/P\"->\tPick" << std::endl;
    }
    else
    {
        //std::cout << "YOU WON" << std::endl;
        std::cout << "No Cards in Hand" << std::endl;
    }
}


void Game::gameDisplay()
{
    if (m_deck->overallDeck.size())
    {
        char playerAction;
        // clearScreen();
        staticDisplay();

        std::cin >> playerAction;
        if (std::cin.fail())
            std::cerr << "Input Failure";
        switch (playerAction)
        {
        case 'd':
        case 'D':
            initdropCardPlayer();
            break;

        case 'p':
        case 'P':
            pickCardPlayer();
            break;

        default:
            std::cout << "Invalid Option" << std::endl;
            break;
        }
    }
    else{
        std::cout << "The Play Deck is Empty";
        m_shouldBreak = true;
    }

}

void Game::initdropCardPlayer()
{
    int index;
    std::cout << "Enter drop Card Index" << std::endl;
    std::cin >> index;
    if (std::cin.fail())
        std::cerr << "Input Failure";
    this->dropCardPlayer(index);
}

void Game::dropCardPlayer(int index)
{
    try
    {
        if (index <= ((m_deck->dealtStack[0].size()) - 1))
        {
            std::cout << "Dropping Card..." << std::endl;
            setSubsequentTopCard(m_deck->dealtStack[0][index]);
            m_deck->dealtStack[0].erase(m_deck->dealtStack[0].begin() + index);
        }
        else
        {
            throw std::runtime_error("Invalid Index !!! Perform card Drop Again\n\n");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        initdropCardPlayer();
    }
}

void Game::pickCardPlayer()
{
    std::cout << "Picking Card..." << std::endl;
    m_deck->dealtStack[0].push_back(m_deck->overallDeck.back());
    if ((m_deck->dropDeck.top().color == m_deck->dealtStack[0].back().color) || (m_deck->dropDeck.top().rank == m_deck->dealtStack[0].back().rank))
    {
        dropCardPlayer((m_deck->dealtStack[0].size()) - 1);
    }
    m_deck->overallDeck.erase(m_deck->overallDeck.end());
}