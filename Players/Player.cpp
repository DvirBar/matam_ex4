#include <string>
#include "Player.h"

Player::Player(const std::string& name) :
    m_name(name),
    m_level(INIT_LEVEL),
    m_force(INIT_FORCE),
    m_max_HP(INIT_MAXHP),
    m_HP(INIT_MAXHP),
    m_coins(INIT_COINS)
{ }

//Player::Player(const Player& player):
//        m_name(player.m_name),
//        m_level(player.m_level),
//        m_force(player.m_force),
//        m_max_HP(player.m_max_HP),
//        m_HP(player.m_HP),
//        m_coins(player.m_coins)
//{}
//
//
//Player& Player::operator=(const Player& player) {
//    if (this == &player) {
//        return *this;
//    }
//
//    m_level = player.m_level;
//    m_force = player.m_force;
//    m_max_HP = player.m_max_HP;
//    m_HP = player.m_HP;
//    m_coins = player.m_coins;
//    m_name = player.m_name;
//
//    return *this;
//}

void Player::levelUp() {
    if (m_level == MAX_LEVEL) {
        return;
    }

    m_level++;
}

std::string Player::getName() const {
    return m_name;
}

int Player::getCoins() const {
    return m_coins;
}

int Player::getLevel() const {
    return m_level;
}

void Player::buff(int forceToBuff) {
    if (forceToBuff < 0) {
        return;
    }

    m_force += forceToBuff;
}

void Player::heal(int HPToHeal) {
    if (HPToHeal < 0) {
        return;
    }

    if (m_HP + HPToHeal >= m_max_HP) {
        m_HP = m_max_HP;
    }

    else {
        m_HP += HPToHeal;
    }
}

void Player::damage(int HPToDamage) {
    if (HPToDamage < 0) {
        return;
    }

    if (m_HP - HPToDamage <= 0) {
        m_HP = 0;
    }

    else
        m_HP -= HPToDamage;
}

bool Player::isKnockedOut() const {
    return m_HP == 0;
}

void Player::addCoins(int coinsToAdd) {
    if (coinsToAdd < 0) {
        return;
    }

    m_coins += coinsToAdd;
}

bool Player::pay(int coinsToPay) {
    if(coinsToPay < 0) {
        return true;
    }

    if (m_coins - coinsToPay < 0) {
        return false;
    }

    m_coins -= coinsToPay;

    return true;
}

int Player::getAttackStrength() const {
    return m_level + m_force;
}

void Player::killPlayer() {
    m_HP = 0;
}

std::ostream& operator<<(std::ostream& output, const Player& player) {
    player.printInfo(output);
    return output;
}