#include "Warrior.h"

Warrior::Warrior(const std::string &name) : Player(name)
{}

int Warrior::getAttackStrength() const {
    return m_force * 2 + m_level;
}

std::ostream& operator<<(std::ostream& output, Warrior& warrior) {
    printPlayerDetails(output, warrior.m_name, "Warrior", warrior.m_level, warrior.m_force, warrior.m_HP, warrior.m_coins);
    return output;
}


