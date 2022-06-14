#include <string>
#include "Card.h"
#include "Battle.h"
#include "../Players/Player.h"
#include "../utilities.h"


const std::string Battle::CARD_NAME;

bool Battle::isWon(int attackStrength, int cardForce) {
    return attackStrength >= cardForce;
}

void Battle::handleWin(Player &player, int coins, std::string name) {
    player.levelUp();
    player.addCoins(coins);
    printWinBattle(player.getName(), name);
}

void Battle::handleLoss(Player &player, int damage, std::string name, bool killOnLoss) {
    if(killOnLoss) {
        player.damage(INIT_MAXHP);
    }
    
    else {
        player.damage(damage);
    }
    
    printLossBattle(player.getName(), name);
}

Battle::Battle(std::string name, int force, int damageUponLoss, int coins, bool isDragon):
    Card(Battle::CARD_NAME),
    m_name(name),
    m_force(force),
    m_damageUponLoss(damageUponLoss),
    m_coins(coins),
    m_isDragon(isDragon)
{}
