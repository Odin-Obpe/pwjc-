#include "endCondition.h"
#include "Game.h"
#include "algorithm"
#include <iostream>

bool RoundEndCondition::isEnd(Game* game) {
    return game->currentRound == this->roundNum;
}

bool PointsEndCondition::isEnd(Game* game) {
    int maxPoints = this->points;
    int currentMax = 0;
    for(auto player : game->Players){
        if(player->points > currentMax){
            currentMax = player->points;
        }
    }
    return currentMax >= maxPoints;
}


