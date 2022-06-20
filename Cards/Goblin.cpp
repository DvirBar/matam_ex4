#include <string>
#include "Goblin.h"
#include "Battle.h"

const std::string Goblin::CARD_NAME = "Goblin";

Goblin::Goblin():
    Battle(CARD_NAME, FORCE, DAMAGE_UPON_LOSS, LOOT)
{}

void Goblin::loseBattle(Player &player) const {
    Battle::handleLoss(player, m_damageUponLoss, m_name, false);
}

void Goblin::applyEncounter(Player &player) const {
    if(Battle::isWon(player.getAttackStrength(), m_force)) {
        Battle::handleWin(player, m_loot, m_name);
    }
    
    else {
        Goblin::loseBattle(player);
//        Battle::handleLoss(player, m_damageUponLoss, m_name, false);
    }
}

