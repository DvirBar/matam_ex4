#include <string>

#include "Card.h"
#include "utilities.h"


Card::Card(std::string name):
    m_name(name)
{}


std::ostream& operator<<(std::ostream& os, const Card& card) {
    printCardDetails(os, card.m_name);
    printEndOfCardDetails(os);
}
