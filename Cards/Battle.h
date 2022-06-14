#ifndef Battle_h
#define Battle_h

#include <string>
#include "Card.h"

static const std::string BATTLE_CARD_NAME = "Battle";

class Battle: public Card {
public:
    // TODO: Should we init it with constructor or use fields and protected?
    Battle(std::string name, int force, int damageUponLoss, int coins, bool isDragon);
    
    void applyEncounter(Player &player) const override;
    
    // TODO: Copy c'tor, =operator, destructor?
    Battle(const Battle& battle) = default;
    ~Battle() = default;
private:
    std::string m_name;
    int m_force;
    int m_damageUponLoss;
    int m_coins;
    bool m_isDragon;
};

#endif
