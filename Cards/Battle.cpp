#include <string>
#include "Card.h"
#include "Battle.h"
#include "../Players/Player.h"
#include "../utilities.h"


Battle::Battle(std::string name, int force, int damageUponLoss, int coins, bool isDragon):
    Card(BATTLE_CARD_NAME),
    m_name(name),
    m_force(force),
    m_damageUponLoss(damageUponLoss),
    m_coins(coins),
    m_isDragon(isDragon)
{}

void Battle::applyEncounter(Player &player) const {
    if(player.getAttackStrength() >= m_force) {
        player.levelUp();
        player.addCoins(m_coins);
        printWinBattle(player.getName(), m_name);
    }
    
    else {
        if(m_isDragon) {
            // TODO: Should we do it like that?
            player.damage(INIT_MAXHP);
        }
        
        else {
            player.damage(m_damageUponLoss);
        }
        
        printLossBattle(player.getName(), m_name);
    }
}
