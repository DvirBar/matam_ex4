#ifndef Dragon_h
#define Dragon_h

#include "Battle.h"

class Dragon: public Battle {
public:
    explicit Dragon();

    void loseBattle(Player &player) const override;
    void applyEncounter(Player &player) const override;
    
    // TODO: Constructors?
    Dragon(const Dragon& dragon) = default;
    ~Dragon() = default;
    
    static const std::string CARD_NAME;
    static const int FORCE = 25;
    // Infinite damage?
    static const int DAMAGE_UPON_LOSS = -1;
    static const int COINS = 1000;
};

#endif
