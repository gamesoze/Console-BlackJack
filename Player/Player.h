//
// Created by Konstantin on 11/1/2020.
//

#ifndef CONSOLE_BLACKJACK_PLAYER_H
#define CONSOLE_BLACKJACK_PLAYER_H

#include "../Hand/Hand.h"

class Player {
public:
    // add_card or skip?
    virtual bool dialog() = 0;

    virtual void showCards() = 0;

    virtual ~Player() = default;

    virtual int getScore() const = 0;

    virtual void betAccrual(double playerBet) = 0;

    virtual const double getPlayerBet() const = 0;

    virtual void refreshHand() = 0;

    // bet == 0 if skip
    virtual void bet() = 0;

protected:
    // Name of Player
    std::string name = "Anon";

    // Count money
    double money = 0;

    // Hand
    Hand hand;

    // bet
    double playerBet = 0;

    // score
    int score = 0;
};


#endif //CONSOLE_BLACKJACK_PLAYER_H
