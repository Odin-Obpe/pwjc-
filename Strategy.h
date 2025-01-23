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
class TitForTwoTatsStrategy: public Strategy {
public:
    TitForTwoTatsStrategy() : Strategy("TitForTwoTats") {}
    Move execute(Player* player, Player* enemyPlayer) override;
};
class Cooperate_Rival: public Strategy {
public:
    Cooperate_Rival() : Strategy("Rival, then cooperate") {}
    Move execute(Player* player, Player* enemyPlayer) override;
};
class Rival_Cooperate: public Strategy {
public:
    Rival_Cooperate() : Strategy("Cooperate, then rival") {}
    Move execute(Player* player, Player* enemyPlayer) override;
};
class Rival_If_Enemy_Cooperates: public Strategy {
public:
    Rival_If_Enemy_Cooperates() : Strategy("TitForTwoTats") {}
    Move execute(Player* player, Player* enemyPlayer) override;
};

class RandomStrategyFactory {
    public:
    static Strategy* createStrategy() {
        int choice = rand() % 8;  // 0-7 for 4 strategies
        switch(choice) {
            case 0: return new AlwaysCooperateStrategy();
            case 1: return new AlwaysRivalryStrategy();
            case 2: return new TitForTatStrategy();
            case 3: return new TitForTwoTatsStrategy();
            case 4: return new Cooperate_Rival();
            case 5: return new Rival_Cooperate();
            case 6: return new Rival_If_Enemy_Cooperates();
            default: return new RandomStrategy();
        }
    }
};

#endif // STRATEGY_H

