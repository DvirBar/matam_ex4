#ifndef MATAM_EX4_GANG_H
#define MATAM_EX4_GANG_H

#include <string>
#include <deque>
#include <memory>

#include "Card.h"
#include "Battle.h"
#include "../Players/Player.h"

class Gang: public Card {
public:
    Gang();
    void applyEncounter(Player &player) const override;
    void addMonster(std::unique_ptr<Battle> battleCard);
 
    Gang(const Gang& gang);
    Gang& operator=(const Gang& gang);
    
    static void cloneQueue(Gang &newGang, const std::deque<std::unique_ptr<Battle>> &queueToClone);
    static const std::string CARD_NAME;
    
private:
    std::deque<std::unique_ptr<Battle>> m_monsterQueue;
    static void printGangWin(const std::string& playerName);
};

#endif //MATAM_EX4_GANG_H
