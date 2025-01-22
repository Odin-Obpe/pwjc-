#pragma once
#include "Player.h"
#include "Strategy.h"
#include <vector>

class Game{
    public:
    std::vector<Player*> Players;
    int NumberOfRounds;
    void play();
    Game(int NumberOfPlayers, int NumberOfRounds, std::vector<Strategy*> Strategies){
        // this->NumberOfPlayers = NumberOfPlayers;
        this->NumberOfRounds = NumberOfRounds;
        for(int i = 0; i < NumberOfPlayers; i++){
            if(i<Strategies.size()){
                this->Players.push_back(new Player(i, Strategies[i]));
            }
            else{
                this->Players.push_back(new Player(i, RandomStrategyFactory::createStrategy()));
            }
        }
        // this->Strategies = Strategies;
    }
};