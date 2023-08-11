#include "../header/player.h"


Player::Player() 
{
    getPlayerName();
    getPlayerCount();
    getCardCount();
}


void Player::getPlayerName()
{
    std::cout << "Enter Player 1 name:" << std::endl;
    std::cin >> name;
    if (std::cin.fail())
        std::cerr << "Input Failure";
}

void Player::getPlayerCount()
{
    std::cout << "Enter number of Players" << std::endl;
    std::cin >> playerCount;
    if (std::cin.fail())
        std::cerr << "Input Failure";
}

void Player::getCardCount()
{
    std::cout << "Enter number of Card" << std::endl;
    std::cin >> cardCount;
    if (std::cin.fail())
        std::cerr << "Input Failure";
}