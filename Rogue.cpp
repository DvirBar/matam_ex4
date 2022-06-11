//
// Created by 222ro on 11-Jun-22.
//

#include "Rogue.h"

Rogue::Rogue(const std::string name, const int maxHP, const int force) :
    Player(name, maxHP, force)
{ }

void Rogue::addCoins(int coinsToAdd) {
    int doubleTheCoins = 2 * coinsToAdd;
    Player::addCoins(doubleTheCoins);
}
