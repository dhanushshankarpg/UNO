#pragma once
#include<iostream>
#include<string>

class Player{
    public:
        Player();
        Player(Player const &) = delete;
        void getPlayerName();
        void getPlayerCount();
        void getCardCount();

    public:
        std::string name;
        int playerCount;
        int cardCount;
};