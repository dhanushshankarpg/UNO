#pragma once

#include "UNOConstants.h"

struct Card
{
    Card() = default;
    Color color;
    Rank rank;
    bool isAlive; // used for TOP CARDS*
    inline bool operator!=(const Card& card) const
    {
        return (this->color == card.color) && (this->rank == card.rank); // bro wtf is this!
    }
    inline bool isEmpty() const
    {
        return (this->color == 0 && this->rank == 0);
    }
};
