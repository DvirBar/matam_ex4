#include <string>
#include <map>

#include "Card.h"
#include "../utilities.h"

std::map<std::string, int> Card::CARDS_MAP {
    { "Barfight", CardTypes::Barfight},
    { "Fairy", CardTypes::Fairy },
    { "Pitfall", CardTypes::Pitfall },
    { "Vampire", CardTypes::Vampire },
    { "Goblin", CardTypes::Goblin },
    { "Dragon", CardTypes::Dragon },
    { "Treasure", CardTypes::Treasure },
    { "Merchant", CardTypes::Merchant },
    { "Gang", CardTypes::Gang }
};

const std::string Card::END_GANG = "EndGang";

Card::Card(const std::string& name):
    m_name(name)
{}

void Card::printInfo(std::ostream& os) const {
    printCardDetails(os, this->m_name);
    printEndOfCardDetails(os);
}


std::ostream& operator<<(std::ostream& os, const Card& card) {
    card.printInfo(os);
    return os;
}
