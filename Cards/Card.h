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
    explicit Card(std::string name);

    Card(const Card& card) = default;

    Card &operator=(const Card& card) = default;

    /**
     * Virtual function for handling the player's encounter with a card.
     */
    virtual void applyEncounter(Player &player) const = 0;

    static std::map<std::string, int> CARDS_MAP;


    virtual ~Card() = 0;

    enum CardTypes {
        Barfight = 1,
        Fairy,
        Pitfall,
        Vampire,
        Goblin,
        Dragon,
        Treasure,
        Merchant
    };

private:
    std::string m_name;
    
    /**
     *  << operator overloading
     *
     *  @param os - output stream to print into.
     */
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};

#endif // EX2_Card_H
