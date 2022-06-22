#ifndef MATAM_EX4_FIGHTER_H
#define MATAM_EX4_FIGHTER_H

#include "Player.h"
#include "../utilities.h"
#include <string>

// --------------------------------------- Wizard Player Class --------------------------------------- //

class Fighter: public Player {
public:
    /**
     * Constructor of Fighter Class.
     *
     * Sets the parameters of the Player class.
     * @param name - name of the player
     */
    explicit Fighter(const std::string &name);

    Fighter(const Fighter& fighter) = default;

    Fighter& operator=(const Fighter& fighter) = default;


    ~Fighter() override = default;

    /**
     * Calculates and the attack strength according to the formula: 2 * m_force + m_level.
     */
    int getAttackStrength() const override;


    /**
    * Outputs Fighter's Parameters according to given structure
    */
    void printInfo(std::ostream &output) const override;
    
    static const std::string JOB_NAME;
};

#endif //MATAM_EX4_FIGHTER_H
