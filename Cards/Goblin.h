#ifndef Goblin_h
#define Goblin_h

#include "Battle.h"


// TODO: Should we define these as static?
const std::string NAME = "Goblin";
const int FORCE = 6;
const int DAMAGE_UPON_LOSS = 10;
const int COINS = 2;
const bool IS_DRAGON = false;


class Goblin: public Battle {
public:
    Goblin();
    
    void applyEncounter(Player &player) const override;
    
    // TODO: Constructors?
    Goblin(const Goblin& goblin) = default;
    ~Goblin() = default;
};

#endif
