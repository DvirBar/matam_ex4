#ifndef Goblin_h
#define Goblin_h

#include "Battle.h"

const std::string NAME = "Goblin";
const int FORCE = 6;
const int DAMAGE_UPON_LOSS = 10;
const int COINS = 2;
const bool IS_DRAGON = false;


class Goblin: public Battle {
public:
    Goblin();
    
    // TODO: Constructors?
    Goblin(const Goblin& goblin) = default;
    ~Goblin() = default;
};

#endif
