#include "Battle.h"
#include "Vampire.h"

const std::string Vampire::CARD_NAME = "Vampire";

Vampire::Vampire():
    Battle(CARD_NAME, FORCE, DAMAGE_UPON_LOSS, LOOT)
{}

void Vampire::applyEncounter(Player &player) const {
    if(Battle::isWon(player.getAttackStrength(), m_force)) {
        Battle::handleWin(player, m_loot, m_name);
    }
    
    else {
        // TODO: Should we use a weaken method here?
        player.buff(-FORCE_DAMAGE);
        Battle::handleLoss(player, m_damageUponLoss, m_name, false);
    }
}
