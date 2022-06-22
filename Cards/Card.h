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

    /**
     * Virtual function for handling the player's encounter with a card.
     */
    virtual void applyEncounter(Player &player) const = 0;

    /**
     * Prints the card info:
     */
    void printInfo() const;
    
    static std::map<std::string, int> CARDS_MAP;

    /*
     * C'tor to the "default card" - Treasure card that gives 0 coins
     */
//    Card() : m_effect(CardType::Treasure), m_stats() {}

    /*
     * Here we are explicitly telling the compiler to use the default methods
     */
    Card(const Card &) = default;
    virtual ~Card() {};
    Card &operator=(const Card &other) = default;
    
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
