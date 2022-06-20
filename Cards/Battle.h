#ifndef Battle_h
#define Battle_h

#include <string>
#include "Card.h"

class Battle: public Card {
public:
    // TODO: Should we init it with constructor or use fields and protected?
    explicit Battle(std::string name, int force, int damageUponLoss, int loot);
    
    // TODO: Should I use pure virtual here for apply encounter
    
    int getForce() const;
    int getDamageUponLoss() const;
    int getCoins() const;
    virtual void loseBattle(Player& player) const = 0;
    
    // TODO: Copy c'tor, =operator, destructor?
    Battle(const Battle& battle) = default;
    ~Battle() = default;
    
    static const std::string CARD_NAME;
    
protected:
    static bool isWon(int playerForce, int cardForce);
    static void handleWin(Player &player, int coins, std::string name);
    static void handleLoss(Player &player, int damage, std::string name, bool killOnLoss);
    std::string m_name;
    int m_force;
    int m_damageUponLoss;
    int m_loot;
};

#endif
