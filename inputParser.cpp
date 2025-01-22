#include "inputParser.h"
#include "Strategy.h"
#include <vector>
#include <string>
#include <tuple>

std::tuple<int, int> InputParser::ParseInput(std::vector<std::string> input, std::vector<Strategy*> Strategies){
    this->NumberOfPlayers = std::stoi(input[0]);
    this->NumberOfRounds = std::stoi(input[1]);
    this->Strategies = Strategies;
    return std::make_tuple(this->NumberOfPlayers, this->NumberOfRounds);
}
