#ifndef Treasure_h
#define Treasure_h

#include "Card.h"
#include "../Players/Player.h"

class Treasure: public Card {
public:

    explicit Treasure();

  

    /**
     * The player gets 10 coins.
     */
    void applyEncounter(Player &player) const override;
    
    /**
     * Copy contstructor, =operator and destructor.
     */
    Treasure(const Treasure& treasure) = default;
    Treasure& operator=(const Treasure& treasure) = default;
    ~Treasure() override = default;
    
    static const std::string CARD_NAME;
    static const int CARD_LOOT = 10;
};

#endif
