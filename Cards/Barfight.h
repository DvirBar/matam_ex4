#ifndef MATAM_EX4_BARFIGHT_H
#define MATAM_EX4_BARFIGHT_H

#include "Card.h"
#include "../Players/Player.h"
#include "../Players/Fighter.h"
#include "../utilities.h"
#include <string>

// --------------------------------------- Barfight Card Class --------------------------------------- //

static const std::string BARFIGHT_NAME = "Barfight";
static const int BARFIGHT_DAMAGE = 10;

class Barfight : public Card {
public:
    /**
     * Constructor for Barfight card.
     */
    Barfight();

    /**
     * applies the barfight effect according to given rules:
     *     if the player is not a fighter, the player will get 10 HP damage.
     *     if the player is a fighter, the player will not get damage.
     */
    void applyEncounter(Player &player) const override;
};


#endif //MATAM_EX4_BARFIGHT_H
