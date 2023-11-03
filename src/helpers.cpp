#include "../include/helpers.h"

void Helpers::intro()
{
    std::cout<<"...Welcome to UNO++..."<<std::endl;
}

int Helpers::s_totalPlayerCount;

int Helpers::getPlayerCount() {
    std::cout << "Enter number of Players" << std::endl;
    std::cin >> s_totalPlayerCount;
    if (std::cin.fail())
        std::cerr << "Input Failure";
    return s_totalPlayerCount;
}

void Helpers::clearScreen()
{
#ifdef _WIN32
    system("cls");
#endif
}

void Helpers::introGame()
{
    clearScreen();
    std::cout<<"...Welcome to UNO++..."<<std::endl;
    std::cout<<"Deck is initialized, Shuffled and Dealt..."<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    clearScreen();
}
