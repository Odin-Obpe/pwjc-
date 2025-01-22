#pragma once
#include <tuple>
#include <vector>
#include <string>
class Strategy;

class InputParser {
public:
    std::tuple<int, int> ParseInput(std::vector<std::string> input, std::vector<Strategy*>& strategies);
    int NumberOfPlayers;
    int NumberOfRounds;
    std::vector<Strategy*>* strategies;
    void selectStrategiesForPlayers();
};
