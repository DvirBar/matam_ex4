#include "Rogue.h"

Rogue::Rogue(const std::string& name) : Player(name)
{}

void Rogue::addCoins(int coinsToAdd) {
    int doubleTheCoins = 2 * coinsToAdd;
    Player::addCoins(doubleTheCoins);
}

std::ostream& operator<<(std::ostream& output, Rogue& rogue) {
    printPlayerDetails(output, rogue.m_name, "Rogue", rogue.m_level, rogue.m_force, rogue.m_HP, rogue.m_coins);
    return output;
}
