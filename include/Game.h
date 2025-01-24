#pragma once
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Strategy.h"
#include <vector>
#include "EndCondition.h"
#include "showResults.h"

class Game{
    private:
    int maxThreads;

    public:
    std::vector<Player*> Players;
    int currentRound;
    EndCondition* endCondition;
    ShowResults showResults;

    void play();
    void runRound(int roundNumber);
    Game(int NumberOfPlayers, int NumberOfRounds, std::vector<Strategy*> Strategies, int maxThreads){
        this->currentRound = 0;
        this->endCondition = new RoundEndCondition(NumberOfRounds);
        this->maxThreads = maxThreads;
        for(int i = 0; i < NumberOfPlayers; i++){
            if(i<Strategies.size()){
                this->Players.push_back(new Player(i, Strategies[i]));
            }
            else{
                this->Players.push_back(new Player(i, RandomStrategyFactory::createStrategy()));
            }
        }
    }
};
#endif