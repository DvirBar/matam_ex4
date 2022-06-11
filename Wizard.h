//
// Created by 222ro on 11-Jun-22.
//

#ifndef MATAM_EX4_WIZARD_H
#define MATAM_EX4_WIZARD_H

#include "Player.h"
#include "utilities.h"
#include <string>

class Wizard : public Player {
    Wizard(const std::string name, const int maxHP = DEFAULT_MAXHP, const int force = DEFAULT_FORCE);
    void heal(int HPToHeal);
};

#endif //MATAM_EX4_WIZARD_H
