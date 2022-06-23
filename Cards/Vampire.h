#ifndef Vampire_h
#define Vampire_h

#include <string>
#include <memory>
#include "Battle.h"

class Vampire: public Battle {
public:
    /**
     * Vampire class constructor
     */
    explicit Vampire();
    
    /**
     * Encounter with a Vampire:
     *    Upon win: The player gets loot of 2 coins and levels up.
     *    Upon lose: The player gets damage of 10 HP, and de-buffed by 1 force point.
     *
     * @param player - The player to apply card encounter to.
     */
    void applyEncounter(Player &player) const override;

    /**
     * Handles a player's loss to a vampire
     * 
     * @param player - The player to modify.
     */
    void loseBattle(Player &player) const override;
    
    /**
     * A method that creates a new instance of a card and returns it.
     */
    std::unique_ptr<Battle> cloneCard() const override;

    /**
     * Copy contstructor, =operator and destructor.
     */
    ~Vampire() override = default;
    Vampire(const Vampire& vampire) = default;
    Vampire& operator=(const Vampire& vampire) = default;
    
    static const std::string CARD_NAME;
    static const int FORCE = 10;
    static const int DAMAGE_UPON_LOSS = 10;
    static const int LOOT = 2;
    static const int FORCE_DAMAGE = 1;
};

#endif
