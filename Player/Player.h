//
// Created by Konstantin on 11/1/2020.
//

#ifndef CONSOLE_BLACKJACK_PLAYER_H
#define CONSOLE_BLACKJACK_PLAYER_H

#include "../Hand/Hand.h"

class Player {
public:
    virtual void dialog() = 0;

    virtual ~Player() = default;

    // Bet return false if not enough money
    virtual bool bet() = 0;

protected:
    // Name of Player
    std::string name;

    // Count money
    double money;

    // Hand
    Hand hand;

    // is Passed?
    bool isPassed = false;
};


#endif //CONSOLE_BLACKJACK_PLAYER_H
