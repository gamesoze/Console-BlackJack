//
// Created by Konstantin on 11/3/2020.
//

#ifndef CONSOLE_BLACKJACK_DEALER_H
#define CONSOLE_BLACKJACK_DEALER_H

#include "Player.h"

class Dealer : public Player {
public:
    void dialog() override {};

    void showCards() override;
};


#endif //CONSOLE_BLACKJACK_DEALER_H
