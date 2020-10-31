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

    // Get score
    int getScore();

    bool addCard();

    virtual ~Hand();

private:
    Cards *ptr_cards;
    std::deque<std::string> hand;
};


#endif //CONSOLE_BLACKJACK_HAND_H
