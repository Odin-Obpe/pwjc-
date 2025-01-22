#include "inputHandler.h"
#include <vector>
#include <string>

std::vector<std::string> inputHandler::getInput(int argc, char *argv[]){
    std::vector<std::string> input;
    for(int i = 1; i < argc; i++){
        input.push_back(argv[i]);
    }
    return input;
}