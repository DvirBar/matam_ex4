#ifndef MATAM_EX4_ROGUE_H
#define MATAM_EX4_ROGUE_H

#include "Player.h"
#include "utilities.h"
#include <string>
#include <iostream>

// --------------------------------------- Rogue Player Class --------------------------------------- //

class Rogue : public Player {
public:
    /**
     * Constructor of Rogue Class.
     *
     * Sets the parameters of the Player class.
     * @param name - name of the player
     */
    explicit Rogue(const std::string& name);

    ~Rogue() override = default;

    /**
     * Adds to the Rogue double the coins that are received.
     * @param coinsToAdd - coin amount to double before adding
     */
    void addCoins(int coinsToAdd) override;

    /**
     * Outputs Rogue's Parameters according to given structure
     */
    friend std::ostream& operator<<(std::ostream& output, Rogue& rogue);



};

#endif //MATAM_EX4_ROGUE_H
