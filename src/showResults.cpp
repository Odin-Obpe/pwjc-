#include "showResults.h"
#include <iostream>
#include <vector>

void ShowResults::showResults(std::vector<Player*> players) {
    std::unordered_map<std::string,int> strategyPoints = this->calculateStartegyAvgPoints(players);
    std::cout << "Results: " << std::endl;
    for (auto const& player : players) {
        std::cout << "Player " << player->Id << " Strategy: " << player->strategy->name << " Points: " << player->points << std::endl;
    }
    for (auto const& strategyPoint : strategyPoints) {
        std::cout << "Strategy: " << strategyPoint.first << " Average points: " << strategyPoint.second << std::endl;
    }
}

std::unordered_map<std::string,int> ShowResults::calculateStartegyAvgPoints(std::vector<Player*> players){
    std::unordered_map<std::string,int> strategyPoints;
    std::unordered_map<std::string,int> strategyCount;
    for (Player* player : players) {
        strategyPoints[player->strategy->name] += player->points;
        strategyCount[player->strategy->name]++;
    }
    for (auto& strategyPoint : strategyPoints) {
        strategyPoint.second /= strategyCount[strategyPoint.first];
    }
    return strategyPoints;
}
