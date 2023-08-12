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


Card Game::setSubsequentTopCard()
{
    //std::cout << sizeof(m_deck->initialTopcard) << std::endl;
   // if(sizeof(m_deck->initialTopcard == 0)){
        m_topCard = m_deck->overallDeck[0]; // This should not be OVERALLdeck it must be REMAINDERdeck
        return m_topCard;
    //}
    
}

void Game::gameStart()
{
    //int interval = 2000;
    while(1) // make a variable to find the winner
    {
        //m_helper->clearScreen();
        setSubsequentTopCard();
        gameDisplay();
        //m_helper->clearScreen();
    }
}

void Game::gameDisplay(){
    /*Show Top Card
    //Display Player hand
    //Perform Player Actions -> Get Action Request 
                                        -> Drop Card = Add Card to RemaindeDeck
                                        -> Pick Card = Pop OverallDeck

                                        */
    int playerAction;
    std::cout << "\n\n"
              << std::endl;
    std::cout << "TOP CARD:\t" << std::endl;
    m_deck->displayCard(m_topCard);
    std::cout << "Your CARDS:\t" << std::endl;
    m_deck->displayDeck(m_deck->dealtStack[0]);
    std::cout << "Enter Actions:\t 1. Drop Card \t 2. Pick Card" << std::endl;
    std::cin >> playerAction;
    if (std::cin.fail())
        std::cerr << "Input Failure";
    switch (playerAction)
    {
    case 1:
        /* code */
        std::cout << "Card Droped" << std::endl;
        // Call Drop Action
        break;

    case 2:
        /* code */
        // Call Pick Action
        std::cout << "Card Picked" << std::endl;

        break;

    default:
        std::cout << "Invalid Option" << std::endl;
        break;
    }
}   

