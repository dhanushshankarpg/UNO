#include "../header/helpers.h"

void Helpers::clearScreen()
{
    std::cout << "\033[2J\033[1;1H"; // ANSI escape sequence to clear screen
}