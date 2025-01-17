#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <tuple>
#include "Strategy.h"
#include "Player.h"


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
    Game game(std::get<0>(parsedInput), std::get<1>(parsedInput), Strategies);
    game.play();
    return 0;
}


