#include "Strategy.h"
#include <random>
#include "enuim.h"
#include "Player.h"
#include <iostream>

Move AlwaysCooperateStrategy::execute(Player* player, Player* enemyPlayer){
    return Move::Cooperation;
}
Move AlwaysRivalryStrategy::execute(Player* player, Player* enemyPlayer){
    return Move::Rivalry;
}
Move TitForTatStrategy::execute(Player* player, Player* enemyPlayer){
    if(enemyPlayer->previousMoves.size() == 0){
        return Move::Cooperation;
    }
    if(enemyPlayer->previousMoves.back() == Move::Cooperation){
        return Move::Cooperation;
    }
    else{
        return Move::Rivalry;
    }
}
Move RandomStrategy::execute(Player* player, Player* enemyPlayer){
    return rand() % 2 == 0 ? Move::Cooperation : Move::Rivalry;
}