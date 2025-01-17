#ifndef STRATEGY_H
#define STRATEGY_H
#include "enuim.h"
#include <string>
class Player;  // Forward declaration

class Strategy {
    public:
    std::string name;
    virtual Move execute(Player* player, Player* enemyPlayer) = 0;
    Strategy(std::string name) : name(name) {}
};

class AlwaysCooperateStrategy: public Strategy {
    public:
    AlwaysCooperateStrategy() : Strategy("AlwaysCooperate") {}
    Move execute(Player* player, Player* enemyPlayer) override;
};

class AlwaysRivalryStrategy: public Strategy {
    public:
    AlwaysRivalryStrategy() : Strategy("AlwaysRivalry") {}
    Move execute(Player* player, Player* enemyPlayer) override;
};

class RandomStrategy: public Strategy {
    public:
    RandomStrategy() : Strategy("Random") {}
    Move execute(Player* player, Player* enemyPlayer) override;
};

class TitForTatStrategy: public Strategy {
    public:
    TitForTatStrategy() : Strategy("TitForTat") {}
    Move execute(Player* player, Player* enemyPlayer) override;
};

class RandomStrategyFactory {
    public:
    static Strategy* createStrategy() {
        int choice = rand() % 4;  // 0-3 for 4 strategies
        switch(choice) {
            case 0: return new AlwaysCooperateStrategy();
            case 1: return new AlwaysRivalryStrategy();
            case 2: return new TitForTatStrategy();
            default: return new RandomStrategy();
        }
    }
};

#endif // STRATEGY_H

