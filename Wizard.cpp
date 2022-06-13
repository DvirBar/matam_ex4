#include "Wizard.h"

Wizard::Wizard(const std::string &name) : Player(name)
{ }

void Wizard::heal(int HPToHeal) {
    int doubleTheHP = 2 * HPToHeal;
    Player::heal(doubleTheHP);
}

std::ostream& operator<<(std::ostream& output, Wizard& wizard) {
    printPlayerDetails(output, wizard.m_name, "Wizard", wizard.m_level, wizard.m_force, wizard.m_HP, wizard.m_coins);
    return output;
}

