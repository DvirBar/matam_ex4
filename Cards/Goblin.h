#ifndef Goblin_h
#define Goblin_h

#include "Battle.h"

class Goblin: public Battle {
public:
    explicit Goblin();
    
    void applyEncounter(Player &player) const override;

    void loseBattle(Player &player) const override;
    
    // TODO: Constructors?
    Goblin(const Goblin& goblin) = default;
    ~Goblin() = default;
    
    static const std::string CARD_NAME;
    static const int FORCE = 6;
    static const int DAMAGE_UPON_LOSS = 10;
    static const int LOOT = 2;
};

#endif
