#ifndef Goblin_h
#define Goblin_h

#include <memory>

#include "Battle.h"

class Goblin: public Battle {
public:
    explicit Goblin();

    /**
     * Encounter with a Goblin:
     *     Upon win - the player gets loot of 2 coins and levels up.
     *     Upon lose - the player gets damage of 10 HP.
     */
    void applyEncounter(Player &player) const override;
    
    /**
     * Handles a player's loss to a goblin.
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
    Goblin(const Goblin& goblin) = default;
    Goblin& operator=(const Goblin& goblin) = default;
    ~Goblin() override = default;
    
    static const std::string CARD_NAME;
    static const int FORCE = 6;
    static const int DAMAGE_UPON_LOSS = 10;
    static const int LOOT = 2;
};

#endif
