#ifndef Battle_h
#define Battle_h

#include <string>
#include "Card.h"

class Battle: public Card {
public:
    explicit Battle(std::string name, int force, int damageUponLoss, int loot);

    Battle(const Battle& battle) = default;

    Battle& operator=(const Battle& battle) = default;

    int getForce() const;

    int getDamageUponLoss() const;

    int getCoins() const;

    /**
     * Virtual function to determine lose of player to a certain battle card.
     * @param player - The player that encounters the battle card.
     */
    virtual void loseBattle(Player& player) const = 0;

    ~Battle() override = default;
    
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
