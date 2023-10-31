#pragma once

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "../src/utils/UNOStructs.h"

class Helpers
{
    public:
        static void intro();
        static void introGame();
        static int getPlayerCount();
        static void clearScreen();
    public:
        static int s_totalPlayerCount;
};