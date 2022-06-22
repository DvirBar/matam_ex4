#include "Gang.h"
#include "Battle.h"

const std::string Gang::CARD_NAME = "Gang";

Gang::Gang():
    Card(CARD_NAME)
{}

void Gang::printGangWin(const std::string& playerName) {
    std::cout << "Player " << playerName << " has defeated Gang and rose 1 Level!" << std::endl;
}

void Gang::applyEncounter(Player &player) const {
    bool hasLost = false;
    // TODO: Level up on an empty queue
    if(m_monsterQueue.empty()) {
        player.levelUp();
        printGangWin(player.getName());
        return;
    }
    
    for(const std::unique_ptr<Battle> &currentMonster : m_monsterQueue) {
        if(Battle::isWon(player.getAttackStrength(), currentMonster->getForce()) && !hasLost) {
            
            player.addCoins(currentMonster->getCoins());
        }
        
        else {
            hasLost = true;
            currentMonster->loseBattle(player);
        }
    }

    if(!hasLost) {
        player.levelUp();
        printGangWin(player.getName());
    }
}

void Gang::addMonster(std::unique_ptr<Battle> battleCard) {
    m_monsterQueue.push_back(std::move(battleCard));
}
