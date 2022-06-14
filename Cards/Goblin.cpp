#include <string>
#include "Goblin.h"
#include "Battle.h"

Goblin::Goblin():
    Battle(NAME, FORCE, DAMAGE_UPON_LOSS, COINS, IS_DRAGON)
{}

void Goblin::applyEncounter(Player &player) const {
    if(Battle::isWon(player.getAttackStrength(), m_force)) {
        Battle::handleWin(player, m_coins, m_name);
    }
    
    else {
        // TODO: Should we use a weaken method here?
        Battle::handleLoss(player, m_damageUponLoss, m_name, false);
    }
}
