#ifndef Battle_h
#define Battle_h

#include <string>
#include <memory>

#include "Card.h"

class Battle: public Card {
public:
    /**
     * Constructor of Battle card.
     */
    explicit Battle(const std::string& name, const int force, const int damageUponLoss, const int loot);

    
    /**
     * Returns the battle card's force.
     */
    int getForce() const;
    
    /**
     * Returns the battle card's damage upon loss.
     */
    int getDamageUponLoss() const;

    /**
     * Returns the battle card's loot.
     */
    int getCoins() const;

    /**
     * Virtual function to force a battle defeat upon a player.
     * @param player - The player that encounters the battle card.
     */
    virtual void loseBattle(Player& player) const = 0;
    
    /**
     * Vitual method for printing card details.
     *
     * @param os - Output stream to print details to.
     */
    virtual void printInfo(std::ostream& os) const override;
    
    /**
     * Virtual method that creates a new instance of a card and returns it.
     */
    virtual std::unique_ptr<Battle> cloneCard() const = 0;
    
    /**
     * Copy contstructor, =operator and destructor.
     */
    Battle(const Battle& battle) = default;
    Battle& operator=(const Battle& battle) = default;
    virtual ~Battle() override {};
    
    static const std::string CARD_NAME;
    
    /**
     * A helper function to decide if a player won the battle card.
     *
     * @param playerForce - Overall player's force
     * @param cardForce - The force of the card that the player has encountered.
     */
    static bool isWon(int playerForce, int cardForce);
    
protected:
    /**
     * A helper function to modify the player according what they achieved by winning a card.
     *
     * @param player - The player to modify.
     * @param coins - Amount of coins to grant the player.
     * @param cardName - The name of the card the player won
     */
    static void handleWin(Player &player, int coins, std::string cardName);
    
    /**
     * A helper function to modify the player according what they lost by losing to a card.
     *
     * @param player - The player to modify.
     * @param damage - The damage to the player's HP.
     * @param cardName - The name of the card the player has lost to.
     * @param killOnLoss - Specifies if the player should be killed when losing to this card.
     */
    static void handleLoss(Player &player, int damage, std::string cardName, bool killOnLoss);
    
    std::string m_name;
    int m_force;
    int m_damageUponLoss;
    int m_loot;
};

#endif
