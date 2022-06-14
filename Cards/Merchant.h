#ifndef MATAM_EX4_MERCHANT_H
#define MATAM_EX4_MERCHANT_H

#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>

// --------------------------------------- Merchant Card Class --------------------------------------- //

static const std::string MERCHANT_NAME = "Merchant";
static const int HEALTH_POTION_OPTION = 1;
static const int FORCE_BOOST_OPTION = 2;
static const int LEAVE_OPTION = 0;
static const int HEALTH_POTION_COST = 5;
static const int FORCE_BOOST_COST = 10;
static const int HEALTH_TO_BOOST = 1;
static const int FORCE_TO_BOOST = 1;

class Merchant : public Card {
public:
    /**
     * Constructor for the Merchant Card
     */
    Merchant();

    /**
     * Applies encounter according to given rules:
     *      A player can pay 5 coins to buy 1 Health Point boost.
     *      A player can pay 10 coins to but 1 Force Point boost.
     *      A player can choose to leave without action.
     *      If A player has insufficient funds, no action will be taken and the turn will end.
     */
    void applyEncounter(Player &player) const override;
};

#endif //MATAM_EX4_MERCHANT_H
