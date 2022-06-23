#ifndef EX2_Card_H
#define EX2_Card_H

#include <iostream>
#include <string>
#include <map>

#include "../Players/Player.h"

class Card {
public:
    /**
     * C'tor of Card class
     *
     * @param name - The name of the card.
     */
    explicit Card(const std::string& name);

    /**
     * Virtual method for handling the player's encounter with a card.
     *
     * @param player - The player to apply encounter to.
     */
    virtual void applyEncounter(Player &player) const = 0;
    
    /**
     * Vitual method for printing card details.
     *
     * @param os - Output stream to print details to.
     */
    virtual void printInfo(std::ostream& os) const;
    
    /**
     * Copy contstructor, =operator and destructor.
     */
    Card(const Card& card) = default;
    Card &operator=(const Card& card) = default;
    virtual ~Card() {};
    
    static std::map<std::string, int> CARDS_MAP;

    enum CardTypes {
        Barfight = 1,
        Fairy,
        Pitfall,
        Vampire,
        Goblin,
        Dragon,
        Treasure,
        Merchant,
        Gang
    };
    
    static const std::string END_GANG;
    std::string m_name;

private:
    
    
    /**
     *  << operator overloading
     *
     *  @param os - output stream to print into.
     */
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};

#endif // EX2_Card_H
