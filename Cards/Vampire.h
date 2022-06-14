#ifndef Vampire_h
#define Vampire_h

#include <string>
#include "Battle.h"

const std::string NAME = "Vampire";
const int FORCE = 10;
const int DAMAGE_UPON_LOSS = 10;
const int COINS = 2;

class Vampire: public Battle {
public:
    Vampire();
    
    void applyEncounter(Player &player) const override;
    
    // TODO: constructors?
    Vampire(const Vampire& vampire) = default;
    ~Vampire() = default;
    
private:
    static int FORCE_DAMAGE;
};

#endif
