#include "Gang.h"

const std::string Gang::GANG_NAME = "Gang";

Gang::Gang():
    Card(GANG_NAME)
{}

void Gang::printGangWin(const std::string& playerName) {
    std::cout << "Player " << playerName << " has defeated A Gang and rose 1 Level!" << std::endl;
}

void Gang::applyEncounter(Player &player) const {
    bool hasLost = false;

    if(m_monsterQueue.empty()) {
        player.levelUp();
        Gang::printGangWin(player.getName());
        return;
    }
    
    for(const std::unique_ptr<Battle> &currentMonster : m_monsterQueue) {
        if(player.getAttackStrength() >= currentMonster->getForce() && !hasLost) {
            player.addCoins(currentMonster->getCoins());
        }
        else {
            hasLost = true;
            currentMonster->loseBattle(player);
        }
    }

    if(!hasLost) {
        player.levelUp();
        Gang::printGangWin(player.getName());
    }
}
