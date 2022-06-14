#include "Barfight.h"

Barfight::Barfight() : Card(BARFIGHT_NAME)
{ }

void Barfight::applyEncounter(Player &player) const {
    Fighter* fighterCheck = dynamic_cast<Fighter*>(&player);
    if(fighterCheck != nullptr) {
        printBarfightMessage(true);
    }
    else {
        player.damage(BARFIGHT_DAMAGE);
        printBarfightMessage(false);
    }
}
