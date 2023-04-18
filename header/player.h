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

        std::string name;
        int playerCount;
        int cardCount;
};