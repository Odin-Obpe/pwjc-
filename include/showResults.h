#ifndef SHOWRESULTS_H
#define SHOWRESULTS_H

#include "Player.h"
#include <vector>
#include <unordered_map>
#include "Strategy.h"

class ShowResults {
    private:
    std::unordered_map<std::string,int> calculateStartegyAvgPoints(std::vector<Player*> players);
    public:
    void showResults(std::vector<Player*> players);
};

#endif