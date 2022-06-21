#ifndef MATAM_EX4_FAIRY_H
#define MATAM_EX4_FAIRY_H

#include "Card.h"
#include "../Players/Player.h"
#include "../Players/Wizard.h"
#include "../utilities.h"
#include <string>

// --------------------------------------- Fairy Card Class --------------------------------------- //

class Fairy: public Card {
public:
    /**
     * Constructor for Fairy Card
     */
    explicit Fairy();

    Fairy(const Fairy& fairy)  = default;

    Fairy& operator=(const Fairy& fairy) = default;

    /**
     * Heals 10 HP for A WIZARD ONLY.
     */
    void applyEncounter(Player &player) const override;
    
    static const std::string CARD_NAME;
    static const int HEAL = 10;
};

#endif //MATAM_EX4_FAIRY_H
