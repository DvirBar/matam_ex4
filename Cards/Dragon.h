#ifndef Dragon_h
#define Dragon_h

#include "Battle.h"

class Dragon: public Battle {
public:

    /**
     * Constructor of the Dragon Battle Card.
     */
    explicit Dragon();

    /**
     * Encounter with a Dragon:
     *    Upon Win - The player gets loot of 1000 coins and levels up.
     *    Upon Lose - The player gets killed and out of the game.
     */
    void applyEncounter(Player &player) const override;
    
    /**
     *
     * Method for printing card details.
     *
     * @param os - Output stream to print details to.
     */
    void printInfo(std::ostream& os) const override;

    /**
     * Handles a player's loss to a dragon.
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
    Dragon(const Dragon& dragon) = default;
    Dragon& operator=(const Dragon& dragon) = default;
    ~Dragon() override = default;
    
    static const std::string CARD_NAME;
    static const int FORCE = 25;
    // Infinite damage?
    static const int DAMAGE_UPON_LOSS = Player::INIT_MAXHP;
    static const int COINS = 1000;
};

#endif
