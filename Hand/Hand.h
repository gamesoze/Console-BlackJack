//
// Created by Konstantin on 10/31/2020.
//

#ifndef CONSOLE_BLACKJACK_HAND_H
#define CONSOLE_BLACKJACK_HAND_H

#include <queue>
#include <string>
#include <sstream>

class Hand {
public:
    // Add 2 starts cards
    explicit Hand(Cards *ptr_cards);

public:

    // Init score

    // Get score
    int getScore();

    bool addCard();

    virtual ~Hand();

private:

    void setScore();

private:
    // pointer to pack cards
    Cards *ptr_cards;

    // Hand
    std::deque<std::string> hand;

    // Sum of all score
    int score;
};


#endif //CONSOLE_BLACKJACK_HAND_H
