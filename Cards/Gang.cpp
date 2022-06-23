#include <iostream>
#include <memory>

#include "Gang.h"
#include "Battle.h"
#include "Vampire.h"
#include "Dragon.h"
#include "Goblin.h"

const std::string Gang::CARD_NAME = "Gang";

Gang::Gang():
    Card(CARD_NAME)
{}

Gang::Gang(const Gang& gang):
    Card(CARD_NAME)
{
    cloneQueue(*this, gang.m_monsterQueue);
}

Gang& Gang::operator=(const Gang& gang) {
    if (this == &gang) {
        return *this;
    }
    
    cloneQueue(*this, gang.m_monsterQueue);
    
    return *this;
}

void Gang::cloneQueue(Gang &newGang, const std::deque<std::unique_ptr<Battle>> &queueToClone) {
    for(const std::unique_ptr<Battle> &battleCard : queueToClone) {
        newGang.addMonster(battleCard->cloneCard());
    }
}

void Gang::printGangWin(const std::string& playerName) {
    std::cout << "Player " << playerName << " has defeated Gang and rose 1 Level!" << std::endl;
}

void Gang::applyEncounter(Player &player) const {
    bool hasLost = false;
   
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
