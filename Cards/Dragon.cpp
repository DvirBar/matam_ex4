#include <string>
#include "Dragon.h"
#include "Battle.h"

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
