#include "Fairy.h"

Fairy::Fairy() : Card(FAIRY_NAME)
{}

void Fairy::applyEncounter(Player &player) const {
    Wizard* wizardCheck = dynamic_cast<Wizard*>(&player);
    if(wizardCheck != nullptr) {
        player.heal(FAIRY_HEAL);
        printFairyMessage(true);
    }
    else {
        printFairyMessage(false);
    }
}
