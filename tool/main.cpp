#include <iostream>
#include <exception>

#include "../Mtmchkin.h"
#include "../Exception.h"



int main() {
    try {
        Mtmchkin game("deck.txt");
        const int MAX_NUMBER_OF_ROUNDS = 100;
        
        while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS) {
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


