#ifndef Dragon_h
#define Dragon_h

#include "Battle.h"

class Dragon: public Battle {
public:

    /**
     * Constructor of the Dragon Battle Card.
     */
    explicit Dragon();

    Dragon(const Dragon& dragon) = default;

    Dragon& operator=(const Dragon& dragon) = default;

    /**
     * Encounter with a Dragon:
     *    Upon Win - The player gets loot of 1000 coins and levels up.
     *    Upon Lose - The player gets killed and out of the game.
     */
    void applyEncounter(Player &player) const override;

    void loseBattle(Player &player) const override;

    ~Dragon() override = default;
    
    static const std::string CARD_NAME;
    static const int FORCE = 25;
    // Infinite damage?
    static const int DAMAGE_UPON_LOSS = Player::INIT_MAXHP;
    static const int COINS = 1000;
};

#endif
