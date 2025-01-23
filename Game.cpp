#include "Game.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex mtx;

void runRound(Game* game, int roundNumber) {
    std::lock_guard<std::mutex> lock(mtx);
    for (int j = 0; j < game->Players.size(); j++) {
        for (int k = j + 1; k < game->Players.size(); k++) {
            game->Players[j]->fight(game->Players[k]);
        }
    }
}

void Game::play() {
    std::vector<std::thread> threads;

    for (int i = 0; i < this->NumberOfRounds; i++) {
        threads.push_back(std::thread(runRound, this, i));
    }


    for (auto& t : threads) {
        t.join();
    }
    threads.clear();


    std::lock_guard<std::mutex> lock(mtx);
    for (auto player : this->Players) {
        std::cout << "Player " << player->Id << " points: " << player->points << std::endl;
    }
}