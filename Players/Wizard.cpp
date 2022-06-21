#include "Wizard.h"

const std::string Wizard::JOB_NAME = "Wizard";

Wizard::Wizard(const std::string &name): Player(name)
{}

void Wizard::heal(int HPToHeal) {
    int doubleTheHP = 2 * HPToHeal;
    Player::heal(doubleTheHP);
}

void Wizard::printInfo(std::ostream &output) const {
    printPlayerDetails(output, m_name, JOB_NAME, m_level, m_force, m_HP, m_coins);
}


