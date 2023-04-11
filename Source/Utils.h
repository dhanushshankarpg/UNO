#pragma once
#include<iostream>

#include "Deck.h"


class Utils
{
private:
    const char *rankArray[9] = {"ONE", "TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
    const char *colorArray[4] = {"RED","GREEN","BLUE","YELLOW"};

public:
    Utils(/* args */);
    void showActualCard(Card);
    ~Utils();
};


