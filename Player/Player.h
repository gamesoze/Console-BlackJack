//
// Created by Konstantin on 11/1/2020.
//

#ifndef CONSOLE_BLACKJACK_PLAYER_H
#define CONSOLE_BLACKJACK_PLAYER_H


class Player {
public:
    virtual void addCard() = 0;

    virtual void pass() = 0;

    virtual ~Player() = default;

protected:
    // Name of Player
    std::string name;

    // Count money
    double money = 0;

    // Hand
    Hand hand;
};


#endif //CONSOLE_BLACKJACK_PLAYER_H
