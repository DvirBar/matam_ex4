#include <string>

#include "Card.h"
#include "Battle.h"
#include "../utilities.h"


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
