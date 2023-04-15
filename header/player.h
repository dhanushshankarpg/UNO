#include<iostream>
#include<string>

class Player{
    public:
        Player();
        void getPlayerName();
        void getPlayerCount();
        void getCardCount();
    private:
        std::string name;
        int playerCount;
        int cardCount;
};