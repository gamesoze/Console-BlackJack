//
// Created by Konstantin on 11/1/2020.
//

#ifndef CONSOLE_BLACKJACK_HUMANPLAYER_H
#define CONSOLE_BLACKJACK_HUMANPLAYER_H

#include "Player.h"


class HumanPlayer : public Player {
public:
    HumanPlayer();

    HumanPlayer(std::string name, double money);

    void pass() override;
};


#endif //CONSOLE_BLACKJACK_HUMANPLAYER_H
