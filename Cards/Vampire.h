#ifndef Vampire_h
#define Vampire_h

#include <string>
#include "Battle.h"



class Vampire: public Battle {
public:
    explicit Vampire();
    
    void applyEncounter(Player &player) const override;
    void loseBattle(Player &player) const override;
    
    // TODO: constructors?
    Vampire(const Vampire& vampire) = default;
    ~Vampire() = default;
    
    static const std::string CARD_NAME;
    static const int FORCE = 10;
    static const int DAMAGE_UPON_LOSS = 10;
    static const int LOOT = 2;
    static const int FORCE_DAMAGE = 1;
};

#endif
