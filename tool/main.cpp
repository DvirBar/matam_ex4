#include <iostream>
#include <exception>

#include "../Mtmchkin.h"
#include "../Exception.h"



int main() {
    try {
        Mtmchkin game("deck.txt");
        while(!game.isGameOver()) {
            game.playRound();
        }
        
        game.printLeaderBoard();
    }
    catch(const std::exception& error) {
        std::cout << error.what() << std::endl;
        return 0;
    }
    
    return 0;
}


