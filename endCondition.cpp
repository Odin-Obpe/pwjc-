#include "EndCondition.h"
#include "Game.h"
#include "algorithm"
#include <iostream>

bool RoundEndCondition::isEnd(Game* game) {
    return game->currentRound == 9;
}

bool PointsEndCondition::isEnd(Game* game) {
    std::cout << "PointsEndCondition::isEnd called" << std::endl;  // Debug line
    int maxPoints = this->points;
    int currentMax = 0;
    for(auto player : game->Players){
        if(player->points > currentMax){
            currentMax = player->points;
        }
    }
    return currentMax >= maxPoints;
}


