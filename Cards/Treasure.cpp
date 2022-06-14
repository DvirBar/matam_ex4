#include <string>

#include "Treasure.h"
#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"

const std::string Treasure::CARD_NAME = "Treasure";
const int Treasure::CARD_LOOT = 10;

Treasure::Treasure():
    Card(Treasure::CARD_NAME)
{}

void Treasure::applyEncounter(Player &player) const {
    player.addCoins(Treasure::CARD_LOOT);
    printTreasureMessage();
}
