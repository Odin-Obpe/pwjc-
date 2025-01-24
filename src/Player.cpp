#include "Player.h"
#include <iostream>
#include <mutex>

void Player::fight(Player* enemyPlayer) {
    std::lock_guard<std::mutex> lock(this->playerMutex);
    Move move = this->strategy->execute(this, enemyPlayer);
    std::lock_guard<std::mutex> enemyLock(enemyPlayer->playerMutex);
    Move enemyMove = enemyPlayer->strategy->execute(enemyPlayer, this);
    // std::cout << "Player " << this->Id << " move: " << move << " Enemy Player " << enemyPlayer->Id << " move: " << enemyMove << std::endl;
    
    if (move == Move::Cooperation && enemyMove == Move::Cooperation) {
        this->points += 3;
        enemyPlayer->points += 3;
    }
    else if (move == Move::Rivalry && enemyMove == Move::Rivalry) {
        this->points += 1;
        enemyPlayer->points += 1;
    }
    else if (move == Move::Rivalry && enemyMove == Move::Cooperation) {
        this->points += 5;
    }
    else if (move == Move::Cooperation && enemyMove == Move::Rivalry) {
        enemyPlayer->points += 5;
    }
    
    this->previousMoves.push_back(move);
    enemyPlayer->previousMoves.push_back(enemyMove);
}