//
// Created by 222ro on 14-Jun-22.
//
#include "Pitfall.h"

Pitfall::Pitfall() : Card(PITFALL_NAME)
{}

void Pitfall::applyEncounter(Player& player) const {
    Rogue* rogueCheck = dynamic_cast<Rogue*>(&player);
    if(rogueCheck != nullptr) {
        printPitfallMessage(true);
    }
    else {
        player.damage(PITFALL_DAMAGE);
        printPitfallMessage(false);
    }
}