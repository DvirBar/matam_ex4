#ifndef Dragon_h
#define Dragon_h

#include "Battle.h"

const std::string NAME = "Dragon";
const int FORCE = 25;
// Infinite damage?
const int DAMAGE_UPON_LOSS = -1;
const int COINS = 2;
const bool IS_DRAGON = true;

class Dragon: public Battle {
public:
    Dragon();
    
    void applyEncounter(Player &player) const override;
    
    // TODO: Constructors?
    Dragon(const Dragon& dragon) = default;
    ~Dragon() = default;
};

#endif
