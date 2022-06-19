#include <string>
#include "Card.h"
#include "Battle.h"
#include "../Players/Player.h"
#include "../utilities.h"


const std::string Battle::CARD_NAME = "Battle";

Battle::Battle(std::string name, int force, int damageUponLoss, int loot):
    Card(CARD_NAME),
    m_name(name),
    m_force(force),
    m_damageUponLoss(damageUponLoss),
    m_loot(loot)
{}

bool Battle::isWon(int attackStrength, int cardForce) {
    return attackStrength >= cardForce;
}

void Battle::handleWin(Player &player, int loot, std::string name) {
    player.levelUp();
    player.addCoins(loot);
    printWinBattle(player.getName(), name);
}

void Battle::handleLoss(Player &player, int damage, std::string name, bool killOnLoss) {
    if(killOnLoss) {
        player.killPlayer();
    }
    
    else {
        player.damage(damage);
    }
    
    printLossBattle(player.getName(), name);
}

int Battle::getForce() const {
    return m_force;
}

int Battle::getDamageUponLoss() const {
    return m_damageUponLoss;
}

int Battle::getCoins() const {
    return m_loot;
}


