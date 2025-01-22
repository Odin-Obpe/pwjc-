#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <tuple>
#include "Strategy.h"
#include "Player.h"
#include "inputHandler.h"
#include "inputParser.h"
#include "Game.h"
#include "memory"


int main(int argc, char *argv[])
{
    srand(time(nullptr));   
    inputHandler inputHandler;
    std::vector<std::string> input = inputHandler.getInput(argc, argv);
    InputParser inputParser;
    std::vector<Strategy*> Strategies;
    std::tuple<int, int> parsedInput = inputParser.ParseInput(input, Strategies);
    std::cout << std::get<0>(parsedInput) << std::endl;
    std::cout << std::get<1>(parsedInput) << std::endl;
    inputParser.selectStrategiesForPlayers();
    Game game(std::get<0>(parsedInput), std::get<1>(parsedInput), Strategies);
    game.play();
    return 0;
}


