#include "Player.h"
#include <iostream>
void Player::fight(Player* enemyPlayer){
    Move move = this->strategy->execute(this, enemyPlayer);
    Move enemyMove = enemyPlayer->strategy->execute(enemyPlayer, this);
    if(move == Move::Cooperation && enemyMove == Move::Cooperation){
        this->points+=6;
        enemyPlayer->points+=6;
    }
    else if(move == Move::Rivalry && enemyMove == Move::Rivalry){
        this->points+=1;
        enemyPlayer->points+=1;

    }
    else if(move == Move::Rivalry && enemyMove == Move::Cooperation){
        this->points += 5;
    }
    else if(move == Move::Cooperation && enemyMove == Move::Rivalry){
        enemyPlayer->points += 5;
    }
    this->previousMoves.push_back(move);
    enemyPlayer->previousMoves.push_back(enemyMove);
}