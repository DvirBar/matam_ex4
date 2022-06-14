#ifndef MATAM_EX4_FAIRY_H
#define MATAM_EX4_FAIRY_H

#include "Card.h"
#include "../Players/Player.h"
#include "../Players/Wizard.h"
#include "../utilities.h"
#include <string>

// --------------------------------------- Fairy Card Class --------------------------------------- //

static const std::string FAIRY_NAME = "Fairy";
static const int FAIRY_HEAL = 10;

class Fairy : public Card {
public:

    /**
     * Constructor for Fairy Card
     */
    Fairy();

    /**
     * Heals 10 HP for A WIZARD ONLY.
     */
    void applyEncounter(Player &player) const override;
};

#endif //MATAM_EX4_FAIRY_H
