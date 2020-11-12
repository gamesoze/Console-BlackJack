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
    bool dialog(bool isDealerHas1011 = false) override;

    // Bet return false if not enough money
    void bet() override;

    // return score
    int getScore() const override;

    // + or - playerBet
    void betAccrual(double playerBet) override;

    const double getPlayerBet() const override;

    // show all cards
    void showCards() override;

    // delete old cards
    void refreshHand() override;

    ~HumanPlayer() override = default;
};


#endif //CONSOLE_BLACKJACK_HUMANPLAYER_H
