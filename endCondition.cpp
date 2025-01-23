#include "EndCondition.h"
#include "Game.h"

bool EndCondition::isEnd(int currentRound) {
    return currentRound == 9;
}