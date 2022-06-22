#include "Barfight.h"

const std::string Barfight::CARD_NAME = "Barfight";

Barfight::Barfight() : Card(CARD_NAME)
{}

void Barfight::applyEncounter(Player &player) const {
    Fighter* fighterCheck = dynamic_cast<Fighter*>(&player);
    if(fighterCheck != nullptr) {
        printBarfightMessage(true);
    }
    else {
        player.damage(DAMAGE);
        printBarfightMessage(false);
    }
}
