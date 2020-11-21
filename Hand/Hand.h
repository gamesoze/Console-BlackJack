//
// Created by Konstantin on 10/31/2020.
//

#ifndef CONSOLE_BLACKJACK_HAND_H
#define CONSOLE_BLACKJACK_HAND_H

#include <queue>
#include <string>
#include <sstream>

#include "../Rools/Rools.h"
#include "../Cards/Cards.h"

class Hand {
public:
    // Add 2 starts cards
    explicit Hand(Cards *ptr_cards);

    Hand();

public:
    // Get score
    int getScore();

    // Print all cards in Hand
    const std::stringstream printHand() const;

    // get a new card
    bool addCard(bool isBeginRound = false);

    // destructor
    // virtual ~Hand();

    // TODO delete after all test
    void test();

    const std::deque<std::string> &getHand() const;

    void refresh();

private:
    // Rools::getScore(hand)
    void setScore();

private:
    // pointer to pack cards
    Cards *ptr_cards;

    // Hand
    std::deque<std::string> hand;

    // Sum of all score
    int score = 0;
};


#endif //CONSOLE_BLACKJACK_HAND_H
