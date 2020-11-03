//
// Created by Konstantin on 11/1/2020.
//

#ifndef CONSOLE_BLACKJACK_PLAYER_H
#define CONSOLE_BLACKJACK_PLAYER_H

#include "../Hand/Hand.h"

class Player {
public:
    // add_card or skip?
    virtual void dialog() = 0;

    virtual void showCards() = 0;

    virtual ~Player() = default;

    // bet == 0 if skip
    virtual void bet() = 0;

protected:
    // Name of Player
    std::string name;

    // Count money
    double money;

    // Hand
    Hand hand;

    // is Passed?
    bool isPassed = false;

    // bet
    double playerBet;
};


#endif //CONSOLE_BLACKJACK_PLAYER_H
