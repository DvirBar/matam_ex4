#include "Rogue.h"

Rogue::Rogue(const std::string& name) : Player(name)
{ }

void Rogue::addCoins(int coinsToAdd) {
    int doubleTheCoins = 2 * coinsToAdd;
    Player::addCoins(doubleTheCoins);
}

void Rogue::printInfo(std::ostream &output) const {
    printPlayerDetails(output, m_name, "Rogue", m_level, m_force, m_HP, m_coins);
}

