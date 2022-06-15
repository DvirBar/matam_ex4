#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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

const int Mtmchkin::TEAM_MIN_SIZE = 2;
const int Mtmchkin::TEAM_MAX_SIZE = 6;

const std::map<std::string, std::unique_ptr<Card>> Mtmchkin::cardMap {
    { "Vampire", std::unique_ptr<Card>(new Vampire()) },
    { "Goblin", std::unique_ptr<Card>(new Goblin()) },
    { "Dragon", std::unique_ptr<Card>(new Dragon()) },
    { "Treasure", std::unique_ptr<Card>(new Treasure()) },
    { "Merchant", std::unique_ptr<Card>(new Merchant()) },
    { "Fairy", std::unique_ptr<Card>(new Fairy()) },
    { "Pitfall", std::unique_ptr<Card>(new Pitfall()) },
    { "Barfight", std::unique_ptr<Card>(new Barfight()) },
};

// TODO: Weird.
std::unique_ptr<Player> Mtmchkin::choosePlayerByClass(std::string name, std::string playerClass) {
    if(playerClass == "Wizard") {
        return std::unique_ptr<Player>(new Wizard(name));
    }
    
    else if(playerClass == "Rogue") {
        return std::unique_ptr<Player>(new Rogue(name));
    }
    
    else if(playerClass == "Fighter") {
        return std::unique_ptr<Player>(new Fighter(name));
    }
    
    throw InvalidPlayer();
}

// TODO: Is it good practive to give map as argument?
void Mtmchkin::createDeck(std::ifstream &deckFile, std::deque<std::unique_ptr<Card>> &deck,
                          const std::map<std::string, std::unique_ptr<Card>> &cardMap) {
    std::string cardType;
    int deckSize = 0;
    
    while(std::getline(deckFile, cardType)) {
        try {
            deckSize++;
            // TODO: std::move???
            deck.push_back(cardMap.at(cardType));
        }
        catch(const std::out_of_range& err) {
            // TODO: Do we need to free something here?
            throw DeckFileFormatError(deckSize);
        }
    }
    
    if(deckSize < 5) {
        throw DeckFileInvalidSize();
    }
}

bool Mtmchkin::validatePlayerName(std::string input, std::string &name) {
    char currentChar;
    for(int i; i < input.size(); i++) {
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
    
    for(int i = (int)name.size() + 1; i < input.size(); i++) {
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
        
        playersQueue.push_back(player);
        index++;
    }
}

Mtmchkin::Mtmchkin(const std::string filename) {
    std::ifstream deckFile(filename);
    if(!deckFile) {
        throw DeckFileNotFound();
    }
    
    createDeck(deckFile, Mtmchkin::deck, Mtmchkin::cardMap);
    
    printStartGameMessage();
    printEnterTeamSizeMessage();
    
    int teamSize;
    
    // TODO: Could it be more compact?
    std::cin >> teamSize;
    while (teamSize < Mtmchkin::TEAM_MIN_SIZE || teamSize > Mtmchkin::TEAM_MAX_SIZE) {
        printInvalidTeamSize();
        std::cin >> teamSize;
    }
    
    createPlayersQueue(teamSize, Mtmchkin::playersQueue);
    Mtmchkin::roundCount = 0;
}

void Mtmchkin::playRound() {
    printRoundStartMessage(Mtmchkin::roundCount);
    // TODO: Leaderboard
    // TODO: Manage win-loss
    for(std::unique_ptr<Player> &currentPlayer : Mtmchkin::playersQueue) {
        printTurnStartMessage(currentPlayer->getName());
        const std::unique_ptr<Card> currentCard = std::move(Mtmchkin::deck.front());
        deck.pop_front();
        currentCard->applyEncounter(*currentPlayer);
        deck.push_back(currentCard);
    }
}

