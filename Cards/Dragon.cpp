#include <string>
#include <memory>

#include "Dragon.h"
#include "Battle.h"
#include "../utilities.h"

const std::string Dragon::CARD_NAME = "Dragon";

Dragon::Dragon():
    Battle(CARD_NAME, FORCE, DAMAGE_UPON_LOSS, COINS)
{}

void Dragon::loseBattle(Player &player) const {
    Battle::handleLoss(player, m_damageUponLoss, m_name, true);
}

void Dragon::applyEncounter(Player &player) const {
    if(Battle::isWon(player.getAttackStrength(), m_force)) {
        Battle::handleWin(player, m_loot, m_name);
    }
    
    else {
        Dragon::loseBattle(player);
//        Battle::handleLoss(player, m_damageUponLoss, m_name, true);
    }
}

void Dragon::printInfo(std::ostream& os) const {
    printCardDetails(os, this->m_name);
    printMonsterDetails(os, this->m_force, this->m_damageUponLoss, this->m_loot, true);
    printEndOfCardDetails(os);
}

std::unique_ptr<Battle> Dragon::cloneCard() const {
    return std::unique_ptr<Battle>(new Dragon());
}
