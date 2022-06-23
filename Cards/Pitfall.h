#ifndef MATAM_EX4_PITFALL_H
#define MATAM_EX4_PITFALL_H

#include "../Players/Player.h"
#include "../Players/Rogue.h"
#include "Card.h"
#include "../utilities.h"
#include <string>

// --------------------------------------- Pitfall Card Class --------------------------------------- //

class Pitfall: public Card {
public:
    /**
     * Constructor for Pitfall card.
     */
    explicit Pitfall();

    /**
     * Applies encounter according to given rules:
     *     If a the player is not a rogue, the player will get 10 HP damage.
     *     If the player is a rogue, the player will get no damage.
     *
     * @param player - The player to apply card encounter to.
     */
    void applyEncounter(Player &player) const override;
    
    /**
     * Copy contstructor, =operator and destructor.
     */
    Pitfall(const Pitfall& pitfall) = default;
    Pitfall& operator=(const Pitfall& pitfall) = default;
    ~Pitfall() override = default;
    
    static const std::string CARD_NAME;
    static const int DAMAGE = 10;
};

#endif //MATAM_EX4_PITFALL_H
