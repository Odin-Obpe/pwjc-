#include "Player.h"
#include <iostream>
#include <mutex>

// Define the static mutex
std::mutex Player::playerMutex;

void Player::fight(Player* enemyPlayer) {
    Move move = this->strategy->execute(this, enemyPlayer);
    Move enemyMove = enemyPlayer->strategy->execute(enemyPlayer, this);
    
    // Use a single lock for the entire update operation
    std::lock_guard<std::mutex> lock(playerMutex);
    
    // Update points
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
    
    // Update move history
    this->previousMoves.push_back(move);
    enemyPlayer->previousMoves.push_back(enemyMove);
}