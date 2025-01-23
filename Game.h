#pragma once
#include "Player.h"
#include "Strategy.h"
#include <vector>
#include "EndCondition.h"

class Game{
    private:
    int maxThreads;

    public:
    std::vector<Player*> Players;
    int currentRound;
    EndCondition* endCondition;
    void play();
    void runRound(int roundNumber);
    Game(int NumberOfPlayers, int NumberOfRounds, std::vector<Strategy*> Strategies, int maxThreads){
        // this->NumberOfPlayers = NumberOfPlayers;
        this->currentRound = 0;
        this->endCondition = new RoundEndCondition();
        this->maxThreads = maxThreads;
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