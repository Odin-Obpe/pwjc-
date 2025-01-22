#include "inputParser.h"
#include "Strategy.h"
#include <vector>
#include <string>
#include <tuple>
#include <iostream>

std::tuple<int, int> InputParser::ParseInput(std::vector<std::string> input, std::vector<Strategy*>& strategies){
    this->NumberOfPlayers = std::stoi(input[0]);
    this->NumberOfRounds = std::stoi(input[1]);
    this->strategies = &strategies;
    return std::make_tuple(this->NumberOfPlayers, this->NumberOfRounds);
}

bool isNumber(const std::string& str) {
    for (char const &ch : str) {
        if (std::isdigit(ch) == 0) return false;
    }
    return true;
}

void InputParser::selectStrategiesForPlayers(){
    int choice;
    std::cout << "If you want to select a strategy for each player, press 1, else press 2: ";
    while (true) {
        std::string input;
        std::cin >> input;
        if (isNumber(input))  {
            choice = std::stoi(input);
            if (choice == 1 || choice == 2) {
                break;
            }
            else
            {
                std::cout << "Invalid choice. Please press 1 to select strategies or 2 to skip: ";
            }
        }
        else
        {
            std::cout << "Invalid argument, please input 1 to select strategies, or 2 to skip: ";
        }
    }

     if (choice == 1) {
        // Loop to ask for strategy selection for each player
        for (int i = 0; i < this->NumberOfPlayers; i++) {
            int strategyChoice;
            std::cout << "Player ID: " << i << " - Select strategy: " << std::endl;
            std::cout << "1 - Always Cooperate" << std::endl;
            std::cout << "2 - Always Rivalry" << std::endl;
            std::cout << "3 - Tit for Tat" << std::endl;
            std::cout << "4 - Random" << std::endl;

            while (true) {
                std::string strategyInput;
                std::cout << "Enter your choice for Player " << i << ": ";
                std::cin >> strategyInput;
                if (isNumber(strategyInput)) {
                    strategyChoice = std::stoi(strategyInput);
                    if (strategyChoice >= 1 && strategyChoice <= 4) {
                        switch (strategyChoice) {
                            case 1:
                                strategies->push_back(new AlwaysCooperateStrategy());
                                break;
                            case 2:
                                strategies->push_back(new AlwaysRivalryStrategy());
                                break;
                            case 3:
                                strategies->push_back(new TitForTatStrategy());
                                break;
                            case 4:
                                strategies->push_back(new RandomStrategy());
                                break;
                        }
                        break;
                    }
                    else
                    {
                        std::cout << "Invalid choice, please select between 1 and 4." << std::endl;
                    }
                }
                else
                {
                    std::cout << "Invalid argument, please input a number between 1 and 4." << std::endl;
                }
            }
        }
    }

}
