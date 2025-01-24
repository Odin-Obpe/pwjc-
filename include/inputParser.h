#pragma once
#include <tuple>
#include <vector>
#include <string>
class Strategy;

class InputParser {
public:
    std::tuple<int, int, int> ParseInput(std::vector<std::string> input, std::vector<Strategy*>& strategies);
    int NumberOfPlayers;
    int NumberOfRounds;
    int NumberOfThreads;
    std::vector<Strategy*>* strategies;
    void selectStrategiesForPlayers();
};
