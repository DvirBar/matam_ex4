#include "Battle.h"
#include "Vampire.h"

int Vampire::FORCE_DAMAGE = 1;

Vampire::Vampire():
    Battle(NAME, FORCE, DAMAGE_UPON_LOSS, COINS, IS_DRAGON)
{}

void Vampire::applyEncounter(Player &player) const {
    if(Battle::isWon(player.getAttackStrength(), m_force)) {
        Battle::handleWin(player, m_coins, m_name);
    }
    
    else {
        // TODO: Should we use a weaken method here?
        player.buff(-Vampire::FORCE_DAMAGE);
        Battle::handleLoss(player, m_damageUponLoss, m_name, false);
    }
}
