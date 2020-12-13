//
// Created by Konstantin on 10/29/2020.
//

#ifndef CONSOLE_BLACKJACK_CARDS_H
#define CONSOLE_BLACKJACK_CARDS_H

#include <string>
#include <deque>

class Cards {
public:
    // Init
    Cards();

    // Constructor copy
    Cards(const Cards &obj);

    // For testing
    void printPack();

    // Shuffle among the remaining
    void shuffle();

    // Get random card and delete it from pack
    const std::string getCard(bool isBeginRound = false);

    // Return copy pointer
    Cards *copyPointer();

private:
    // Check define
    void checkAndInit();

private:
    // Pack of Cards
    std::deque<std::string> packCards;

    // This small homework, baby
    const std::string suitsName[4] = {"Hearts", "Clubs", "Diamonds", "Spades"};
    const std::string faceName[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
};


#endif //CONSOLE_BLACKJACK_CARDS_H
