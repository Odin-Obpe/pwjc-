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
    if(player->opponentMoves[enemyPlayer->Id].empty()){
        return Move::Cooperation;
    }
    if(player->opponentMoves[enemyPlayer->Id].back() == Move::Cooperation){
        return Move::Cooperation;
    }
    else{
        return Move::Rivalry;
    }
}
Move RandomStrategy::execute(Player* player, Player* enemyPlayer){
    return rand() % 2 == 0 ? Move::Cooperation : Move::Rivalry;
}
Move TitForTwoTatsStrategy::execute(Player* player, Player* enemyPlayer) {
    if (player->opponentMoves[enemyPlayer->Id].size()>=2
        && player->opponentMoves[enemyPlayer->Id][player->opponentMoves[enemyPlayer->Id].size() - 1]==Move::Rivalry
        && player->opponentMoves[enemyPlayer->Id][player->opponentMoves[enemyPlayer->Id].size() - 2]==Move::Rivalry){
        return Move::Rivalry;
    }
    else {
        return Move::Cooperation;
    }
}
Move Cooperate_Rival::execute(Player* player, Player* enemyPlayer) {
    if (!player->previousMoves.empty() && player->previousMoves.back()==Move::Cooperation) {
        return Move::Rivalry;
    }
    else {
        return Move::Cooperation;
    }
}
Move Rival_Cooperate::execute(Player* player, Player* enemyPlayer) {
    if (!player->previousMoves.empty() && player->previousMoves.back()==Move::Cooperation) {
        return Move::Cooperation;
    }
    else {
        return Move::Rivalry;
    }
}
Move Rival_If_Enemy_Cooperates::execute(Player* player, Player* enemyPlayer) {
    if (player->opponentMoves[enemyPlayer->Id].size()>=2
        && player->opponentMoves[enemyPlayer->Id][player->opponentMoves[enemyPlayer->Id].size() - 1]==Move::Cooperation
        && player->opponentMoves[enemyPlayer->Id][player->opponentMoves[enemyPlayer->Id].size() - 2]==Move::Cooperation) {
        return Move::Rivalry;
    }
    else {
        return Move::Cooperation;
    }
}