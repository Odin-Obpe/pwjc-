#include "Game.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <algorithm>

std::mutex mtx;

void Game::runRound(int roundNumber) {
    std::cout << "Round " << this->currentRound+1 << " started" << std::endl;
    std::vector<std::thread> threads;
    int playersPerThread = this->Players.size()/ this->maxThreads;
    if (playersPerThread == 0) {
        playersPerThread = 1;
    }
    for (size_t start = 0; start < Players.size(); start += playersPerThread) {
        size_t end = std::min(start + playersPerThread, Players.size());
        threads.emplace_back([this, start, end]() {
            for (size_t i = start; i < end; i++) {
                for (size_t j = i + 1; j < Players.size(); j++) {
                    Players[i]->fight(Players[j]);
                }
            }
        });
    }
    
    for (auto& t : threads) {
        t.join();
    }
    
    this->currentRound++;
}

void Game::play() {
    while(!this->endCondition->isEnd(this)) {
        runRound(this->currentRound);
    }
    for (auto player : this->Players) {
        std::cout << "Player " << player->Id<< " Strategy: "<<player->strategy->name << " points: " << player->points << std::endl;
    }
}