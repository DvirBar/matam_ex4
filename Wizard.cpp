//
// Created by 222ro on 11-Jun-22.
//

#include "Wizard.h"

Wizard::Wizard(const std::string name, const int maxHP, const int force) :
        Player(name, maxHP, force)
{ }

void Wizard::heal(int HPToHeal) {
    int doubleTheHP = 2 * HPToHeal;
    Player::heal(doubleTheHP);
}
