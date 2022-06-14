#ifndef MATAM_EX4_PITFALL_H
#define MATAM_EX4_PITFALL_H

#include "../Players/Player.h"
#include "../Players/Rogue.h"
#include "Card.h"
#include "../utilities.h"
#include <string>

// --------------------------------------- Pitfall Card Class --------------------------------------- //

static const std::string PITFALL_NAME = "Pitfall";
static const int PITFALL_DAMAGE = 10;

class Pitfall : public Card {
public:
    /**
     * Constructor for Pitfall card.
     */
    Pitfall();

    /**
     * Applies encounter according to given rules:
     *     If a the player is not a rogue, the player will get 10 HP damage.
     *     If the player is a rogue, the player will get no damage.
     */
    void applyEncounter(Player &player) const override;
};

#endif //MATAM_EX4_PITFALL_H
