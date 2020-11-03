//
// Created by Konstantin on 11/1/2020.
//

#ifndef CONSOLE_BLACKJACK_HUMANPLAYER_H
#define CONSOLE_BLACKJACK_HUMANPLAYER_H

#include "Player.h"
#include "../Cards/Cards.h"
#include "../Hand/Hand.h"


class HumanPlayer : public Player {
public:
    // starts 500$ and name Anon
    explicit HumanPlayer(Cards *ptr_cards);

    HumanPlayer(Cards *ptr_cards, std::string name, double money);

    // Dialog to user
    void dialog() override;

    // Bet return false if not enough money
    void bet() override;

    void showCards() override;


    ~HumanPlayer() {}
};


#endif //CONSOLE_BLACKJACK_HUMANPLAYER_H
