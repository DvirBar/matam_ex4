//
// Created by 222ro on 14-Jun-22.
//
#include "Pitfall.h"

const std::string CARD_NAME = "Pitfall";

Pitfall::Pitfall() : Card(CARD_NAME)
{}

void Pitfall::applyEncounter(Player& player) const {
    Rogue* rogueCheck = dynamic_cast<Rogue*>(&player);
    if(rogueCheck != nullptr) {
        printPitfallMessage(true);
    }
    else {
        player.damage(DAMAGE);
        printPitfallMessage(false);
    }
}
