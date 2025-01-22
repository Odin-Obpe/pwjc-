#include "Game.h"
#include "Player.h"
#include <iostream>

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
