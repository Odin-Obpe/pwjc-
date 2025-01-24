#ifndef PLAYER_H
#define PLAYER_H

#include "Strategy.h"
#include <vector>
#include "enuim.h"
#include <mutex>

class Player {
    private:
        std::mutex playerMutex;  // Static mutex for all players
        
    public:
        int Id;
        Strategy* strategy;
        int points;
        std::vector<Move> previousMoves;
        void fight(Player* enemyPlayer);
        
        Player(int Id, Strategy* strategy) {
            this->Id = Id;
            this->strategy = strategy;
            this->points = 0;
            this->previousMoves = std::vector<Move>();
        }
        
        Player() {
            this->Id = 0;
            this->strategy = nullptr;
            this->points = 0;
            this->previousMoves = std::vector<Move>();
        }
};

#endif // PLAYER_H