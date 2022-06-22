#ifndef Treasure_h
#define Treasure_h

#include "Card.h"
#include "../Players/Player.h"

class Treasure: public Card {
public:

    explicit Treasure();

    Treasure(const Treasure& treasure) = default;

    Treasure& operator=(const Treasure& treasure) = default;

    /**
     * The player gets 10 coins.
     */
    void applyEncounter(Player &player) const override;
    
    static const std::string CARD_NAME;
    static const int CARD_LOOT = 10;
};

#endif
