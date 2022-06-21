#include <string>
#include <map>

#include "Card.h"

// TODO: Replace
#include "Battle.h"
#include "../utilities.h"

std::map<std::string, int> Card::CARDS_MAP {
    { "Barfight", CardTypes::Barfight},
    { "Fairy", CardTypes::Fairy },
    { "Pitfall", CardTypes::Pitfall },
    { "Vampire", CardTypes::Vampire },
    { "Goblin", CardTypes::Goblin },
    { "Dragon", CardTypes::Dragon },
    { "Treasure", CardTypes::Treasure },
    { "Merchant", CardTypes::Merchant }
};

Card::Card(std::string name):
    m_name(name)
{}


std::ostream& operator<<(std::ostream& os, const Card& card) {
    printCardDetails(os, card.m_name);
    const Battle* battleCard = dynamic_cast<const Battle*>(&card);
    
    if(battleCard != nullptr) {
        printMonsterDetails(os, battleCard->getForce(), battleCard->getDamageUponLoss(), battleCard->getCoins());
    }
    
    printEndOfCardDetails(os);
    
    return os;
}
