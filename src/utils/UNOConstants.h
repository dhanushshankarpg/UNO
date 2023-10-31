#pragma once

#define MAXCOLOR 4
#define MAXRANK 12
#define CARD_COUNT_PER_HAND 3

enum Color
{
    RED = 1,
    GREEN,
    BLUE,
    YELLOW
};

enum Rank
{
    ONE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    REVERSE,
    SKIP,
    DRAW2,
};

 enum SpecialColor
 {
     BLACK
 };

 enum Wild
 {
    DRAW4,
    CHANGECOLOR
 };

 // soruce: https://www.letsplayuno.com/news/guide/20181213/30092_732567.html#:~:text=A%20UNO%20deck%20consists%20of,%2C%20yellow%2C%20blue%20and%20green.
