#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <string>

#include "Mtmchkin.h"
#include "Exception.h"
#include "utilities.h"
#include "Cards/Card.h"
#include "Cards/Vampire.h"
#include "Cards/Goblin.h"
#include "Cards/Dragon.h"
#include "Cards/Treasure.h"
#include "Cards/Fairy.h"
#include "Cards/Pitfall.h"
#include "Cards/Barfight.h"
#include "Cards/Merchant.h"
#include "Players/Player.h"
#include "Players/Wizard.h"
#include "Players/Rogue.h"
#include "Players/Fighter.h"

// TODO: should we use a shared_ptr or use
//std::map<std::string, std::unique_ptr<Card>> Mtmchkin::CARD_MAP {
//    { "Vampire", std::unique_ptr<Card>(new Vampire()) },
//    { "Goblin", std::unique_ptr<Card>(new Goblin()) },
//    { "Dragon", std::unique_ptr<Card>(new Dragon()) },
//    { "Treasure", std::unique_ptr<Card>(new Treasure()) },
//    { "Merchant", std::unique_ptr<Card>(new Merchant()) },
//    { "Fairy", std::unique_ptr<Card>(new Fairy()) },
//    { "Pitfall", std::unique_ptr<Card>(new Pitfall()) },
//    { "Barfight", std::unique_ptr<Card>(new Barfight()) },
//};

std::unique_ptr<Card> Mtmchkin::chooseCardByType(std::string &cardType, int deckSize) {
    if(cardType == "Vampire") {
        return std::unique_ptr<Card>(new Vampire());
    }

    if(cardType == "Goblin") {
        return std::unique_ptr<Card>(new Goblin());
    }

    if(cardType == "Dragon") {
        return std::unique_ptr<Card>(new Dragon());
    }

    if(cardType == "Treasure") {
        return std::unique_ptr<Card>(new Treasure());
    }

    if(cardType == "Merchant") {
        return std::unique_ptr<Card>(new Merchant());
    }

    if(cardType == "Fairy") {
        return std::unique_ptr<Card>(new Fairy());
    }

    if(cardType == "Pitfall") {
        return std::unique_ptr<Card>(new Pitfall());
    }

    if(cardType == "Barfight") {
        return std::unique_ptr<Card>(new Barfight());
    }

    throw DeckFileFormatError(deckSize);
}

// TODO: Could this be done with map?
 std::unique_ptr<Player> Mtmchkin::choosePlayerByClass(std::string &name, std::string &playerClass) {
    if(playerClass == "Wizard") {
        return std::unique_ptr<Player>(new Wizard(name));
    }
    
    if(playerClass == "Rogue") {
        return std::unique_ptr<Player>(new Rogue(name));
    }
    
    if(playerClass == "Fighter") {
        return std::unique_ptr<Player>(new Fighter(name));
    }
    
    throw InvalidPlayer();
}

void Mtmchkin::createDeck(std::ifstream &deckFile, std::deque<std::unique_ptr<Card>> &m_deck,
                          std::map<std::string, std::unique_ptr<Card>> &cardMap) {
    std::string cardType;
    std::unique_ptr<Card> newCard;
    int deckSize = 0;
    
    while(std::getline(deckFile, cardType)) {
        deckSize++;
        newCard = chooseCardByType(cardType, deckSize);
        m_deck.push_back(std::move(newCard));
    }
    
    if(deckSize < 5) {
        throw DeckFileInvalidSize();
    }
}

bool Mtmchkin::validatePlayerName(std::string &input, std::string &name) {
    char currentChar;
    for(int i = 0; i < input.size(); i++) {
        currentChar = input[i];
        if(currentChar == ' ') {
            break;
        }
        
        if(currentChar < 'a' || currentChar > 'z' || currentChar < 'A' || currentChar > 'Z') {
            return false;
        }
        
        name[i] = currentChar;
    }
    
    return true;
}

bool Mtmchkin::validateClassAndCreatePlayer(std::string input, std::string name, std::unique_ptr<Player> &player) {
    std::string playerClass;
    
    for(unsigned int i = name.size() + 1; i < input.size(); i++) {
        playerClass[i] = input[i];
    }
    
    try {
        player = choosePlayerByClass(name, playerClass);
    }
    catch (const InvalidPlayer& err) {
        return false;
    }
    
    return true;
}

void Mtmchkin::createPlayersQueue(int teamSize, std::deque<std::unique_ptr<Player>> &playersQueue) {
    int index = 0;
    std::string input;
    
    while(index < teamSize) {
        std::cin >> input;
        std::string name;
        std::unique_ptr<Player> player;
        
        if(!validatePlayerName(input, name)) {
            printInvalidName();
            continue;
        }
        
        if(!validateClassAndCreatePlayer(input, name, player)) {
            printInvalidClass();
            continue;
        }
        
        playersQueue.push_back(std::move(player));
        index++;
    }
}

void Mtmchkin::insertIntoLeaderboard(std::unique_ptr<Player> &player, std::deque<std::unique_ptr<Player>> &playersWon,
                                     std::deque<std::unique_ptr<Player>> &playersLost) {
    if(player->getLevel() == Player::MAX_LEVEL) {
        playersWon.push_back(std::move(player));
    }
    
    else if(player->isKnockedOut()) {
        playersLost.push_front(std::move(player));
    }

}

Mtmchkin::Mtmchkin(const std::string filename):
    m_numberOfRounds(0),
    m_gameOver(false)
{
    std::ifstream deckFile(filename);
    if(!deckFile) {
        throw DeckFileNotFound();
    }
    
    createDeck(deckFile, m_deck, CARD_MAP);
    
    printStartGameMessage();
    printEnterTeamSizeMessage();
    
    int teamSize;
    
    // TODO: Could it be more compact?
    std::cin >> teamSize;

    while (teamSize < Mtmchkin::TEAM_MIN_SIZE || teamSize > Mtmchkin::TEAM_MAX_SIZE) {
        printInvalidTeamSize();
        std::cin >> teamSize;
    }

    createPlayersQueue(teamSize, Mtmchkin::m_playersQueue);
}

void Mtmchkin::playRound() {
    printRoundStartMessage(m_numberOfRounds);
    
    int playersPlayed = 0;
    int originalQueueSize = (int)m_playersQueue.size();
    
    while(playersPlayed < originalQueueSize) {
        std::unique_ptr<Player> currentPlayer = std::move(m_playersQueue.front());
        m_playersQueue.pop_front();
        
        printTurnStartMessage(currentPlayer->getName());
        
        std::unique_ptr<Card> currentCard = std::move(m_deck.front());
        m_deck.pop_front();
        
        currentCard->applyEncounter(*currentPlayer);
        
        if(currentPlayer->getLevel() == Player::MAX_LEVEL || currentPlayer->isKnockedOut()) {
            insertIntoLeaderboard(currentPlayer, m_playersWon, m_playersLost);
        }
        
        else {
            m_playersQueue.push_back(std::move(currentPlayer));
        }
        
        m_deck.push_back(std::move(currentCard));
        playersPlayed++;
    }
    
    m_numberOfRounds++;
    
    if(m_playersQueue.size() == 0) {
        m_gameOver = true;
    }
}

int Mtmchkin::getNumberOfRounds() const {
    return m_numberOfRounds;
}

bool Mtmchkin::isGameOver() const {
    return m_gameOver;
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int ranking = 1;

    for(const std::unique_ptr<Player> &currentPlayer : m_playersWon) {
        printPlayerLeaderBoard(ranking, *currentPlayer);
        ranking++;
    }
    
    for(const std::unique_ptr<Player> &currentPlayer : m_playersQueue) {
        printPlayerLeaderBoard(ranking, *currentPlayer);
        ranking++;
    }
    
    for(const std::unique_ptr<Player> &currentPlayer : m_playersLost) {
        printPlayerLeaderBoard(ranking, *currentPlayer);
        ranking++;
    }
}

