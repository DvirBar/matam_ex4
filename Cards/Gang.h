#ifndef MATAM_EX4_GANG_H
#define MATAM_EX4_GANG_H

#include "Card.h"
#include "Battle.h"
#include <string>
#include <deque>
#include <memory>
#include "../Players/Player.h"

class Gang: public Card {
public:
    Gang();
    void applyEncounter(Player &player) const override;

    static const std::string GANG_NAME;
private:
    std::deque<std::unique_ptr<Battle>> m_monsterQueue;
    static void printGangWin(const std::string& playerName);
};

#endif //MATAM_EX4_GANG_H
