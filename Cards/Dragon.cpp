#include <string>
#include "Dragon.h"
#include "Battle.h"

const std::string CARD_NAME = "Dragon";

Dragon::Dragon():
    Battle(CARD_NAME, FORCE, DAMAGE_UPON_LOSS, COINS)
{}

void Dragon::applyEncounter(Player &player) const {
    if(Battle::isWon(player.getAttackStrength(), m_force)) {
        Battle::handleWin(player, m_loot, m_name);
    }
    
    else {
        Battle::handleLoss(player, m_damageUponLoss, m_name, true);
    }
}
