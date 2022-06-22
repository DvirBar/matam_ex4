#ifndef Vampire_h
#define Vampire_h

#include <string>
#include "Battle.h"

class Vampire: public Battle {
public:

    Vampire();

    Vampire(const Vampire& vampire) = default;

    Vampire& operator=(const Vampire& vampire) = default;

    /**
     * Encounter with a Vampire:
     *    Upon win: The player gets loot of 2 coins and levels up.
     *    Upon lose: The player gets damage of 10 HP, and de-buffed by 1 force point.
     * @param player
     */
    void applyEncounter(Player &player) const override;

    void loseBattle(Player &player) const override;

    ~Vampire() override = default;
    
    static const std::string CARD_NAME;
    static const int FORCE = 10;
    static const int DAMAGE_UPON_LOSS = 10;
    static const int LOOT = 2;
    static const int FORCE_DAMAGE = 1;
};

#endif
