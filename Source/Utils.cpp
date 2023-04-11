#include "Utils.h"

Utils::Utils(/* args */)
{
}

Utils::~Utils()
{
}

void Utils::showActualCard(Card card)
{
    std::cout << "Colorasdadasd: ";

    std::cout << "Color: " << rankArray[card.rank] << "    "
              << "Rank: " << colorArray[card.color]  << std::endl;
}

