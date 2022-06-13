#ifndef Treasure_h
#define Treasure_h

#include "Card.h"
#include "../Players/Player.h"

const std::string TREASURE_CARD_NAME = "Treasure";
const int TREASURE_LOOT = 10;

class Treasure: public Card {
public:
    Treasure();
    
    void applyEncounter(Player &player) const override;
};

#endif
