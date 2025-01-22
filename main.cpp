#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <tuple>
#include "Strategy.h"
#include "Player.h"
#include "memory"

class inputHandler{
    public:
    std::vector<std::string> getInput(int argc, char *argv[]);
};

// class GameResult{
//     public:
//     void showResult(Game game);
// };

std::vector<std::string> inputHandler::getInput(int argc, char *argv[]){
    std::vector<std::string> input;
    for(int i = 1; i < argc; i++){
        input.push_back(argv[i]);
    }
    return input;
}

class InputParser{
    public:
    std::tuple<int, int> ParseInput(std::vector<std::string> input, std::vector<Strategy*> Strategies);
    int NumberOfPlayers;
    int NumberOfRounds;
    std::vector<Strategy*> Strategies;
};

std::tuple<int, int> InputParser::ParseInput(std::vector<std::string> input, std::vector<Strategy*> Strategies){
    this->NumberOfPlayers = std::stoi(input[0]);
    this->NumberOfRounds = std::stoi(input[1]);
    this->Strategies = Strategies;
    return std::make_tuple(this->NumberOfPlayers, this->NumberOfRounds);
}

bool isNumber(const std::string& str) {
    for (char const &ch : str) {
        if (std::isdigit(ch) == 0) return false;
    }
    return true;
}

void selectStrategiesForPlayers(std::vector<Strategy*>& strategies, int numPlayers) {
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
        for (int i = 0; i < numPlayers; i++) {
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
                                strategies.push_back(new AlwaysCooperateStrategy());
                                break;
                            case 2:
                                strategies.push_back(new AlwaysRivalryStrategy());
                                break;
                            case 3:
                                strategies.push_back(new TitForTatStrategy());
                                break;
                            case 4:
                                strategies.push_back(new RandomStrategy());
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


class Game{
    public:
    std::vector<Player*> Players;
    int NumberOfRounds;
    void play();
    Game(int NumberOfPlayers, int NumberOfRounds, std::vector<Strategy*> Strategies){
        // this->NumberOfPlayers = NumberOfPlayers;
        this->NumberOfRounds = NumberOfRounds;
        for(int i = 0; i < NumberOfPlayers; i++){
            if(i<Strategies.size()){
                this->Players.push_back(new Player(i, Strategies[i]));
            }
            else{
                this->Players.push_back(new Player(i, RandomStrategyFactory::createStrategy()));
            }
        }
        // this->Strategies = Strategies;
    }
};

void Game::play(){
    for(int i = 0; i < this->NumberOfRounds; i++){
        for(int j = 0; j < this->Players.size(); j++){
            for(int k = j + 1; k < this->Players.size(); k++){
                this->Players[j]->fight(this->Players[k]);
            }
        }
    }
    for(int i = 0; i < this->Players.size(); i++){
        std::cout << this->Players[i]->Id << " " << this->Players[i]->strategy->name << " " << this->Players[i]->points << std::endl;
    }
}

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
    selectStrategiesForPlayers(Strategies, std::get<0>(parsedInput));
    Game game(std::get<0>(parsedInput), std::get<1>(parsedInput), Strategies);
    game.play();
    return 0;
}


