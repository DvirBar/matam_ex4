#include <memory>

#include "Battle.h"
#include "Vampire.h"

const std::string Vampire::CARD_NAME = "Vampire";

Vampire::Vampire():
    Battle(CARD_NAME, FORCE, DAMAGE_UPON_LOSS, LOOT)
{}

void Vampire::loseBattle(Player &player) const {
    player.buff(-FORCE_DAMAGE);
    Battle::handleLoss(player, m_damageUponLoss, m_name, false);
}

void Vampire::applyEncounter(Player &player) const {
    if(Battle::isWon(player.getAttackStrength(), m_force)) {
        Battle::handleWin(player, m_loot, m_name);
    }
    
    else {
        Vampire::loseBattle(player);
    }
}

std::unique_ptr<Battle> Vampire::cloneCard() const {
    return std::unique_ptr<Battle>(new Vampire());
}
