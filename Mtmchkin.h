#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <memory>
#include <string>
#include <map>
#include <deque>
#include <fstream>

#include "Cards/Card.h"
#include "Players/Player.h"

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
    
private:
    std::deque<std::unique_ptr<Card>> m_deck;
    std::deque<std::unique_ptr<Player>> m_playersQueue;
    std::deque<std::unique_ptr<Player>> m_playersWon;
    std::deque<std::unique_ptr<Player>> m_playersLost;
    int m_numberOfRounds;
    bool m_gameOver;
    
    static void createDeck(std::ifstream &deckFile, std::deque<std::unique_ptr<Card>> &deck,
                           std::map<std::string, std::unique_ptr<Card>> &cardMap);
    
    static std::unique_ptr<Card> chooseCardByType(std::string &cardType, int deckSize);
    static std::unique_ptr<Player> choosePlayerByClass(std::string &name, std::string &playerClass);
    static void createPlayersQueue(int teamSize, std::deque<std::unique_ptr<Player>> &playersQueue);
    static bool validatePlayerName(std::string &input, std::string &name);
    static bool validateClassAndCreatePlayer(std::string input, std::string name, std::unique_ptr<Player> &player);
    static void insertIntoLeaderboard(std::unique_ptr<Player> &player, std::deque<std::unique_ptr<Player>> &playersWon,
                                      std::deque<std::unique_ptr<Player>> &playersLost);
    
    static std::map<std::string, std::unique_ptr<Card>> CARD_MAP;
//    static const std::map<std::string, std::unique_ptr<Player>> playersMap;
    static const int TEAM_MIN_SIZE = 2;
    static const int TEAM_MAX_SIZE = 6; 
};



#endif /* MTMCHKIN_H_ */
