//
// Created by 222ro on 13-Jun-22.
//
#include "Fighter.h"

Fighter::Fighter(const std::string &name): Player(name)
{}

int Fighter::getAttackStrength() const {
    return m_force * 2 + m_level;
}

void Fighter::printInfo(std::ostream &output) const {
    printPlayerDetails(output, m_name, "Fighter", m_level, m_force, m_HP, m_coins);
}


