#include "Fairy.h"


const std::string CARD_NAME = "Fairy";

Fairy::Fairy() : Card(CARD_NAME)
{}

void Fairy::applyEncounter(Player &player) const {
    Wizard* wizardCheck = dynamic_cast<Wizard*>(&player);
    if(wizardCheck != nullptr) {
        player.heal(HEAL);
        printFairyMessage(true);
    }
    else {
        printFairyMessage(false);
    }
}
