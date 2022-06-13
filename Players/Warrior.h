#ifndef MATAM_EX4_WARRIOR_H
#define MATAM_EX4_WARRIOR_H

#include "Player.h"
#include "utilities.h"
#include <string>

// --------------------------------------- Wizard Player Class --------------------------------------- //

class Warrior : public Player {

    /**
     * Constructor of Warrior Class.
     *
     * Sets the parameters of the Player class.
     * @param name - name of the player
     */
    explicit Warrior(const std::string &name);

    ~Warrior() override = default;

    /**
     * Calculates and the attack strength according to the formula: 2 * m_force + m_level.
     */
    int getAttackStrength() const override;


    /**
    * Outputs Warrior's Parameters according to given structure
    */
    friend std::ostream& operator<<(std::ostream& output, Warrior& warrior);

};

#endif //MATAM_EX4_WARRIOR_H
