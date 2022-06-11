//
// Created by 222ro on 11-Jun-22.
//

#ifndef MATAM_EX4_ROGUE_H
#define MATAM_EX4_ROGUE_H

#include "Player.h"
#include "utilities.h"
#include <string>

//TODO: CHANGE PLAYER CONSTRUCTOR ACCORDING TO NEW RULES
class Rogue : public Player {
public:
    Rogue(const std::string name, const int maxHP = DEFAULT_MAXHP, const int force = DEFAULT_FORCE);
    ~Rogue() = default;
    void addCoins(int coinsToAdd);
};

#endif //MATAM_EX4_ROGUE_H
